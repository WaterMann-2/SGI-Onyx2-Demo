//
// Created by robsc on 4/23/26.
//

#ifndef SILICONGRAPHICS_MATRIX_H
#define SILICONGRAPHICS_MATRIX_H

#include "../utils/SpUtils.h"

namespace SpGL {

//TODO Implement
template<typename T = float>
class Matrix {
public:
	Matrix(uint16 width, uint16 height, T start);
	~Matrix();

	bool IsSquare() const;

	void SetToIdentity();

protected:
	T** data_ = nullptr;
	uint16 columns_, rows_;
};

//TODO Implement
class Matrix4f : public Matrix<float> {
	public:
	Matrix4f();


};

} // SpGL

#endif //SILICONGRAPHICS_MATRIX_H
