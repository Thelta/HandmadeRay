#pragma once
#define VECTOR3_UINT8_HASH size_t (*)(const Vector3<uint8_t>&)

template <typename  T>
class Vector3
{
	public:
	T x;
	T y;
	T z;

	Vector3(T x, T y, T z);
	Vector3();
	bool operator==(const Vector3<T> &thisVector3) const;
	static size_t Hash(const Vector3<T> &vector);
};
