//
// Created by robsc on 4/23/26.
//

#ifndef SILICONGRAPHICS_MATRIX_H
#define SILICONGRAPHICS_MATRIX_H

#include "../utils/SpUtils.h"
#include "Vector.h"

namespace SpGL {

template<typename T>
class Matrix {
public:
	Matrix();
	explicit Matrix(uint16 width, uint16 height);
	~Matrix();

	bool IsSquare() const;

	void SetToIdentity();

	String ToString() const;

protected:
	T** data_ = nullptr;
	uint16 columns_, rows_;
};

template<typename T>
class Matrix4 : public Matrix<T> {
	public:
	using Matrix<T>::Matrix;
	using Matrix<T>::IsSquare;
	using Matrix<T>::SetToIdentity;
	using Matrix<T>::ToString;

	Matrix4();
	Matrix4(Vector3<T> startVector);
	~Matrix4();

private:
	using Matrix<T>::data_;
	using Matrix<T>::columns_;
	using Matrix<T>::rows_;


};

template struct Matrix<float>;
template struct Matrix<double>;

template struct Matrix4<float>;
template struct Matrix4<double>;
} // SpGL

#endif //SILICONGRAPHICS_MATRIX_H
