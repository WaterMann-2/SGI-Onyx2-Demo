//
// Created by robsc on 4/23/26.
//

#include "Matrix.h"

namespace SpGL {

template <typename T> Matrix<T>::Matrix(uint16 width, uint16 height, T defaultValue) {
	columns_ = width;
	rows_ = height;

	SpUtils::ExitCheck(columns_ <= 0, "Width must be greater than 0 for matrix!", SP_FAIL);
	SpUtils::ExitCheck(rows_ <= 0, "Height must be greater than 0 for matrix!", SP_FAIL);

	data_ = new T*[rows_];

	for (int i = 0; i < rows_; i++) {
		data_[i] = new T[columns_];
	}

	for (int i = 0; i < columns_; i++) {
		for (int j = 0; j < rows_; j++) {
			data_[i][j] = defaultValue;
		}
	}
}

template <typename T> Matrix<T>::~Matrix() {
	for (int i = 0; i < columns_; i++) {
		delete[] data_[i];
	}

	delete[] data_;
}

template <typename T> bool Matrix<T>::IsSquare() const {
	return columns_ == rows_;
}

template <typename T> void Matrix<T>::SetToIdentity() {
	if (!IsSquare()) {
		SpUtils::PrintConsole(SP_WARNING, "SetToIdentity() must be called on a square matrix!");
		return;
	}

	for (int i = 0; i < columns_; i++) {
		for (int j = 0; j < rows_; j++) {
			data_[i][j] = static_cast<T>(0.0f);
		}
		data_[i][i] = static_cast<T>(1.0f);
	}
}

Matrix4f::Matrix4f() : Matrix<float>(4, 4, 0) {



}
} // SpGL