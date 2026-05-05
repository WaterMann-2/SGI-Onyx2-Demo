//
// Created by robsc on 4/23/26.
//

#include "Matrix.h"

namespace SpGL {
template <typename T> Matrix<T>::Matrix() {
	SpUtils::PrintConsole(SP_WARNING, "No size given, Defaulting matrix to 4x4");
	columns_ = 4;
	rows_ = 4;

	data_ = new T*[rows_];

	for (int i = 0; i < rows_; i++) {
		data_[i] = new T[columns_];
	}

	for (int i = 0; i < columns_; i++) {
		for (int j = 0; j < rows_; j++) {
			data_[i][j] = static_cast<T>(0.0f);
		}
	}
}

template <typename T> Matrix<T>::Matrix(uint16 width, uint16 height) {
	columns_ = width;
	rows_ = height;

	SpUtils::ExitCheck(columns_ <= 0, "Width must be greater than 0 for matrix!", SP_FAIL);
	SpUtils::ExitCheck(rows_ <= 0, "Height must be greater than 0 for matrix!", SP_FAIL);
	if (columns_ > rows_) {
		SpUtils::PrintConsole(SP_WARNING, "Cannot have rows greater than columns! Switching Rows and Columns");
		columns_ = height;
		rows_ = width;
	}

	data_ = new T*[rows_];

	for (int i = 0; i < rows_; i++) {
		data_[i] = new T[columns_];
	}

	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < columns_; j++) {
			data_[i][j] = static_cast<T>(0.0f);
		}
	}

}

template <typename T> Matrix<T>::~Matrix() {
	if (data_ == nullptr) {
		SpUtils::PrintConsole(SP_WARNING, "Matrix data was already freed!");
		return;
	}
	for (int i = 0; i < columns_; i++) {
		data_[i] = nullptr;
		delete[] data_[i];
	}

	delete[] data_;
	data_ = nullptr;
}

template <typename T> bool Matrix<T>::IsSquare() const {
	return columns_ == rows_;
}

template <typename T> void Matrix<T>::SetToIdentity() {

	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < columns_; j++) {
			data_[i][j] = static_cast<T>(0.0f);
		}
		data_[i][i] = static_cast<T>(1.0f);
	}
}

template <typename T> String Matrix<T>::ToString() const {
	String message;

	message.append("[ ");

	for (int i = 0; i < rows_; i++) {
		message.append("[ ");
		for (int j = 0; j < columns_; j++) {
			String number = std::to_string(data_[i][j]);

			if (j < columns_ - 1) {
				message.append(number + ", ");
			}else {
				message.append(number);
			}
		}

		if (i < rows_ - 1) {
			message.append(" ], ");
		}else {
			message.append(" ]");
		}
	}

	message.append(" ]");
	
	return message;
}

template <typename T> Matrix4<T>::Matrix4() : Matrix<T>(4, 4) {
	SetToIdentity();
}

template <typename T> Matrix4<T>::Matrix4(Vector3<T> startVector) : Matrix<T>(4, 4) {
	SetToIdentity();
	data_[0][0] = startVector.At(0);
	data_[1][1] = startVector.At(1);
	data_[2][2] = startVector.At(2);
}

template <typename T> Matrix4<T>::~Matrix4() {
	// for (int i = 0; i < columns_; i++) {
	// 	delete[] data_[i];
	// };
	//
	// delete[] data_;
}
} // SpGL