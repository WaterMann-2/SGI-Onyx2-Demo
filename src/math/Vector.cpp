//
// Created by robsc on 4/30/26.
//

#include "Vector.h"

template <typename T> Vector<T>::Vector(uint16 size) {
	length = size;

	SpUtils::ExitCheck(length == 0, "Length must be greater than 0!", SP_FAIL);

	data = new T[length];
}

template <typename T> Vector<T>::Vector(uint16 size, T startValue) {
	length = size;

	SpUtils::ExitCheck(length == 0, "Length must be greater than 0!", SP_FAIL);

	data = new T[length];

	for (int i = 0; i < length; i++) {
		data[i] = startValue;
	}
}

template <typename T> Vector<T>::~Vector() {
	delete[] data;
}

template <typename T> void Vector<T>::SetToValue(T newValue) {
	for (int i = 0; i < length; i++) {
		data[i] = newValue;
	}
}

template <typename T> Vector<T> Vector<T>::Negative() {
	Vector<T> result(length);

	for (int i = 0; i < length; i++) {
		result.data[i] = -data[i];
	}

	return result;
}

template <typename T> Vector<T> Vector<T>::Add(Vector<T>& addFrom) {
	Vector<T> result(length);
	if (addFrom.length != length) {
		SpUtils::PrintConsole(SP_WARNING, "Vector length mismatch!");
	}

	for (int i = 0; i < length; i++) {
		result.data[i] = data[i] + addFrom.data[i];
	}

	return result;
}

template <typename T> Vector<T> Vector<T>::Scale(T scale) {
	Vector<T> result(length);
	for (int i = 0; i < length; i++) {
		result.data[i] = data[i] * scale;
	}

	return result;
}

template <typename T> T Vector<T>::DotProduct(Vector& dotProductFrom) {
	if (dotProductFrom.length != length) {
		SpUtils::PrintConsole(SP_WARNING, "Vector length mismatch! (Dot Product)");
		return static_cast<T>(0);
	}

	T sumValue = static_cast<T>(0);
	for (int i = 0; i < length; i++) {
		sumValue += data[i] * dotProductFrom.data[i];
	}

	return sumValue;
}

template <typename T> T* Vector<T>::GetData() {
	return data;
}
