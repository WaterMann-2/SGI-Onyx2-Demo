//
// Created by robsc on 4/30/26.
//

#include "Vector.h"

namespace SpGL {
template <typename T> Vector<T>::Vector(uint16 size) {
	length = size;

	SpUtils::ExitCheck(length == 0, "Length must be greater than 0!", SP_FAIL);

	data = new T[length];
}

template <typename T> Vector<T>::Vector(uint16 size, T startValue) {
	length = size;

	SpUtils::ExitCheck(length == 0, "Length must be greater than 0!", SP_FAIL);
	SpUtils::ExitCheck(length == 1, "Length must be greater than 1!", SP_FAIL);

	data = new T[length];

	for (int i = 0; i < length; i++) {
		data[i] = startValue;
	}
}

template <typename T> Vector<T>::~Vector() {
	data = nullptr;
	delete[] data;
}

template <typename T> void Vector<T>::SetToValue(T newValue) {
	for (int i = 0; i < length; i++) {
		data[i] = newValue;
	}
}

template <typename T> Vector<T> Vector<T>::Normalize() {
	Vector<T> result(length);

	T magnitude = static_cast<T>(0);

	for (int i = 0; i < length; i++) {
		magnitude += data[i] * data[i];
	}

	magnitude = std::sqrt(magnitude);

	for (int i = 0; i < length; i++) {
		data[i] = data[i] / magnitude;
	}

	return result;
}

template <typename T> Vector<T> Vector<T>::Negative() {
	Vector<T> result(length);

	for (int i = 0; i < length; i++) {
		result.data[i] = -data[i];
	}

	return result;
}

template <typename T> Vector<T> Vector<T>::Add(Vector<T>& addFrom) {
	Vector<T> result(length, 0);
	if (addFrom.length != length) {
		SpUtils::PrintConsole(SP_WARNING, "Vector length mismatch!");
	}

	for (int i = 0; i < length; i++) {
		result.data[i] = data[i] + addFrom.data[i];
	}

	return result;
}

template <typename T> Vector<T> Vector<T>::Subtract(Vector& subtractFrom) {
	Vector<T> result(length, 0);
	if (subtractFrom.length != length) {
		SpUtils::PrintConsole(SP_WARNING, "Vector length mismatch!");
		return result;
	}

	for (int i = 0; i < length; i++) {
		result.data[i] = data[i] + subtractFrom.data[i];
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

template <typename T> T& Vector<T>::At(uint16 index) {
	SpUtils::ExitCheck(index >= length, "Arithmatic vector out of range!", SP_FAIL);
	return data[index];
}

template <typename T> T& Vector<T>::Front() {
	return data[0];
}

template <typename T> T& Vector<T>::Back() {
	return data[length - 1];
}

template <typename T> T* Vector<T>::GetData() {
	return data;
}

template <typename T> Vector3<T>::Vector3() : Vector<T>(3) {
	this->data[0] = static_cast<T>(0);
	this->data[1] = static_cast<T>(0);
	this->data[2] = static_cast<T>(0);
}

template <typename T> Vector3<T>::Vector3(const T x,const T y,const T z) : Vector<T>(3) {
	this->data[0] = x;
	this->data[1] = y;
	this->data[2] = z;
}

} //SpGl