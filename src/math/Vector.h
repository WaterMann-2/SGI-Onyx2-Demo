//
// Created by robsc on 4/30/26.
//

#ifndef SILICONGRAPHICS_VECTORS_H
#define SILICONGRAPHICS_VECTORS_H
#include "../utils/SpUtils.h"


template <typename T = float>
class Vector {
public:
	explicit Vector(uint16 size);
	Vector(uint16 size, T startValue);
	~Vector();

	void SetToValue(T newValue);

	Vector Negative();
	Vector Add(Vector& addFrom);
	Vector Scale(T scale);

	T DotProduct(Vector& dotProductFrom);

	T* GetData();

protected:
	T* data;
	uint16 length;
};



#endif //SILICONGRAPHICS_VECTORS_H
