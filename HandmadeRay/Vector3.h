#pragma once
#define VECTOR3_UINT8_HASH size_t (*)(const Vector3<uint8_t>&)
#include <array>

template <typename  T>
class Vector3
{
	std::array<T, 3> arr;

	public:

	Vector3(T x, T y, T z);
	Vector3();
	inline T x() const { return arr[0]; };
	inline T y() const { return arr[1]; };
	inline T z() const { return arr[2]; };
	inline T r() const { return arr[0]; };
	inline T g() const { return arr[1]; };
	inline T b() const { return arr[2]; };

	bool operator==(const Vector3<T> &thisVector3) const;
	static size_t Hash(const Vector3<T> &vector);

	Vector3<T> operator+(const Vector3<T> &vec) const;
	Vector3<T> operator-(const Vector3<T> &vec) const;
	Vector3<T> operator*(const Vector3<T> &vec) const;
	Vector3<T> operator/(const Vector3<T> &vec) const;
	Vector3<T> operator*(double a) const;
	Vector3<T> operator/(double a) const;

	Vector3<T>& operator+=(const Vector3<T> &vec);
	Vector3<T>& operator-=(const Vector3<T> &vec);
	Vector3<T>& operator*=(const Vector3<T> &vec);
	Vector3<T>& operator/=(const Vector3<T> &vec);
	Vector3<T>& operator*=(double a);
	Vector3<T>& operator/=(double a);

	std::ostream& operator<<(std::ostream& os);

	double Length() const;
	double SquaredLength() const;
	Vector3<T> UnitVector();

};
