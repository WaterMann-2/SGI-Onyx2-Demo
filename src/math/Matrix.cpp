//
// Created by robsc on 4/23/26.
//

#include "Matrix.h"

namespace SpGL {

template <typename T> Matrix<T>::Matrix(uint16 width, uint16 height) {
	columns_ = width;
	rows_ = height;

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

Matrix4f::Matrix4f() : Matrix<float>(4, 4) {

}
} // SpGL