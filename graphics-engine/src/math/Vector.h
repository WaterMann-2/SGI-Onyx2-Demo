//
// Created by robsc on 4/30/26.
//

#ifndef SILICONGRAPHICS_VECTORS_H
#define SILICONGRAPHICS_VECTORS_H
#include "../utils/SpUtils.h"


namespace SpGL {
template <typename T>
class Vector {
public:
	explicit Vector(uint16 size);
	Vector(uint16 size, T startValue);
	~Vector();

	void SetToValue(T newValue);

	Vector Normalize();

	Vector Negative();
	Vector Add(Vector& addFrom);
	Vector Subtract(Vector& subtractFrom);
	Vector Scale(T scale);

	T DotProduct(Vector& dotProductFrom);

	T& At(uint16 index);
	T& Front();
	T& Back();

	T* GetData();

protected:
	T* data = nullptr;
	uint16 length;
};

template <typename T>
class Vector3 : public Vector<T> {
public:
	Vector3();
	Vector3(T x, T y, T z);

protected:


};


template struct Vector<float>;
template struct Vector<double>;

template struct Vector3<float>;
template struct Vector3<double>;


} //SpGL
#endif //SILICONGRAPHICS_VECTORS_H

