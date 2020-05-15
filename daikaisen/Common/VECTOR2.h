#pragma once


template<class T> class Vector2Template
{
public:
	Vector2Template();
	Vector2Template(T x, T y);
	~Vector2Template();
	T x;		// X���W
	T y;		// Y���W

	// ������Z�q
	Vector2Template& operator = (const Vector2Template& vec);		// ���������s��

	// �Y�������Z�q
	int& operator[](int i);

	// ��r���Z�q
	bool operator == (const Vector2Template& vec) const;
	bool operator != (const Vector2Template& vec) const;
	bool operator <= (const Vector2Template& vec) const;
	bool operator < (const Vector2Template& vec) const;
	bool operator >= (const Vector2Template& vec) const;
	bool operator > (const Vector2Template& vec) const;

	// �P�����Z�q
	Vector2Template& operator += (const Vector2Template& vec);
	Vector2Template& operator -=(const Vector2Template& vec);
	Vector2Template& operator *= (const T k);
	Vector2Template& operator /=(const T k);
	Vector2Template  operator +()const;
	Vector2Template  operator -()const;
};

// �޸�ق̉��Z
//Vector2Template + int
template<class T>
Vector2Template<T> operator +(const Vector2Template<T>& u, const T v);
//Vector2Template - int
template<class T>
Vector2Template<T> operator -(const Vector2Template<T>& u, const T v);
//Vector2Template + Vector2Template
template<class T>
Vector2Template<T> operator +(const Vector2Template<T>& u, const Vector2Template<T>& v);
//Vector2Template - Vector2Template
template<class T>
Vector2Template<T> operator -(const Vector2Template<T>& u, const Vector2Template<T>& v);
//int * Vector2Template
template<class T>
Vector2Template<T> operator *(const T k, const Vector2Template<T>& v);
//Vector2Template * int
template<class T>
Vector2Template<T> operator *(const Vector2Template<T>& v, const T k);
//Vector2Template / int
template<class T>
Vector2Template<T> operator /(const Vector2Template<T>& v, const T k);
//Vector2Template % int
template<class T>
Vector2Template<T> operator %(const Vector2Template<T>& v, const T k);

using Vector2 = Vector2Template<int>;
using Vector2Dbl = Vector2Template<double>;
using Vector2Flt = Vector2Template<float>;


#include "details/Vector2.h"