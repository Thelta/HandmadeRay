#include "Vector3.h"
#include <cstdint>
#include <memory>

using namespace std;

template <typename T>
Vector3<T>::Vector3(T x, T y, T z)
{
	arr[0] = x; 
	arr[1] = y;
	arr[2] = z;
}
template Vector3<uint8_t>::Vector3(uint8_t x, uint8_t y, uint8_t z);
template Vector3<double>::Vector3(double x, double y, double z);


template <typename T>
Vector3<T>::Vector3()
{
	arr[0] = 0; arr[1] = 0; arr[2] = 0;
}
template Vector3<uint8_t>::Vector3();
template Vector3<double>::Vector3();


//TODO : While this overriding is fine for now because we use only uint8, we should change it when we start to use float or double.
template <typename  T>
bool Vector3<T>::operator==(const Vector3<T> &anotherVector3) const
{
	return (arr[0] == anotherVector3.x()) && (arr[1] == anotherVector3.y()) && (arr[2] == anotherVector3.z());
}
template bool Vector3<uint8_t>::operator==(const Vector3<uint8_t> &anotherVector3) const;
//template bool Vector3<double>::operator==(const Vector3<double> &anotherVector3) const;


template <typename T>
size_t Vector3<T>::Hash(const Vector3<T> &vector)
{
	hash<T> hasher;
	return hasher(vector.x()) ^ (hasher(vector.y()) << 2) ^ (hasher(vector.z()) >> 2);
}
template size_t Vector3<uint8_t>::Hash(const Vector3<uint8_t> &vector);
template size_t Vector3<double>::Hash(const Vector3<double> &vector);

template <typename T>
Vector3<T> Vector3<T>::operator+(const Vector3<T> &vec) const
{
	return Vector3<T>(x() + vec.x(), y() + vec.y(), z() + vec.z());
}
template Vector3<double> Vector3<double>::operator+(const Vector3<double> &vec) const;

template <typename T>
Vector3<T> Vector3<T>::operator-(const Vector3<T> &vec) const
{
	return Vector3<T>(x() - vec.x(), y() - vec.y(), z() - vec.z());
}
template Vector3<double> Vector3<double>::operator-(const Vector3<double> &vec) const;

template <typename T>
Vector3<T> Vector3<T>::operator*(const Vector3<T>& vec) const
{
	return Vector3<T>(x() * vec.x(), y() * vec.y(), z() * vec.z());
}
template Vector3<double> Vector3<double>::operator*(const Vector3<double>& vec) const;

template <typename T>
Vector3<T> Vector3<T>::operator*(double a) const
{
	return Vector3<T>(x() * a, y() * a, z() * a);
}
template Vector3<double> Vector3<double>::operator*(double a) const;

template <typename T>
Vector3<T> Vector3<T>::operator/(const Vector3<T>& vec) const
{
	return Vector3<T>(x() / vec.x(), y() / vec.y(), z() / vec.z());
}
template Vector3<double> Vector3<double>::operator/(const Vector3<double>& vec) const;

template <typename T>
Vector3<T> Vector3<T>::operator/(double a) const
{
	return Vector3<T>(x() / a, y() / a, z() / a);
}
template Vector3<double> Vector3<double>::operator/(double a) const;

template <typename T>
Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& vec)
{
	*this = *this + vec;
	return *this;
}
template Vector3<double>& Vector3<double>::operator+=(const Vector3<double>& vec);

template <typename T>
Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& vec)
{
	*this = *this - vec;
	return *this;
}
template Vector3<double>& Vector3<double>::operator-=(const Vector3<double>& vec);
 
template <typename T>
Vector3<T>& Vector3<T>::operator*=(const Vector3<T>& vec)
{
	*this = *this * vec;
	return *this;
}
template Vector3<double>& Vector3<double>::operator*=(const Vector3<double>& vec);

template <typename T>
Vector3<T>& Vector3<T>::operator/=(const Vector3<T>& vec)
{
	*this = *this / vec;
	return *this;
}
template Vector3<double>& Vector3<double>::operator/=(const Vector3<double>& vec);

template <typename T>
Vector3<T>& Vector3<T>::operator*=(double a)
{
	*this = *this * a;
	return *this;
}
template Vector3<double>& Vector3<double>::operator*=(double a);

template <typename T>
Vector3<T>& Vector3<T>::operator/=(double a)
{
	*this = *this / a;
	return *this;
}
template Vector3<double>& Vector3<double>::operator/=(double a);

template <typename T>
std::ostream& Vector3<T>::operator<<(std::ostream& os)
{
	os << "x: " << arr[0] << " y: " << arr[1] << " z: " << arr[2];
	return os;
}
template std::ostream& Vector3<uint8_t>::operator<<(std::ostream& os);
template std::ostream& Vector3<double>::operator<<(std::ostream& os);


template <typename T>
double Vector3<T>::Length() const
{
	return sqrt(arr[0] * arr[0] + arr[1] * arr[1] + arr[2] * arr[2]);
}
template double Vector3<uint8_t>::Length() const;
template double Vector3<double>::Length() const;

template <typename T>
double Vector3<T>::SquaredLength() const
{
	return arr[0] * arr[0] + arr[1] * arr[1] + arr[2] * arr[2];
}
template double Vector3<uint8_t>::SquaredLength() const;
template double Vector3<double>::SquaredLength() const;

template <typename T>
Vector3<T> Vector3<T>::UnitVector()
{
	return *this / Length();
}
template Vector3<double> Vector3<double>::UnitVector();


