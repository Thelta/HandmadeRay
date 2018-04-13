#include "Vector3.h"
#include <cstdint>

template <typename T>
Vector3<T>::Vector3(T x, T y, T z)
{
	this->x = x;
	this->y = y;
	this->z = z;	
}

template Vector3<uint8_t>::Vector3(uint8_t x, uint8_t y, uint8_t z);

template <typename T>
Vector3<T>::Vector3()
{
	x = 0;
	y = 0; 
	z = 0;
}
template Vector3<uint8_t>::Vector3();


template <typename  T>
bool Vector3<T>::operator==(const Vector3<T> &anotherVector3) const
{
	return (x == anotherVector3.x) && (y == anotherVector3.y) && (z == anotherVector3.z);
}
template bool Vector3<uint8_t>::operator==(const Vector3<uint8_t> &anotherVector3) const;

template <typename T>
size_t Vector3<T>::Hash(const Vector3<T> &vector)
{
	return vector.x ^ vector.y << 2 ^ vector.z >> 2;
}
template size_t Vector3<uint8_t>::Hash(const Vector3<uint8_t> &vector);
