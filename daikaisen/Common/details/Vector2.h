#pragma once
#include "./Vector2.h"

template<class T>
Vector2Template<T>::Vector2Template()
{
	x = 0;
	y = 0;
}

template<class T>
Vector2Template<T>::Vector2Template(T x, T y)
{
	this->x = x;
	this->y = y;
}

template<class T>
Vector2Template<T>::~Vector2Template()
{
}

// ������Z�q
template<class T>
Vector2Template<T>& Vector2Template<T>::operator=(const Vector2Template& vec)
{
	x = vec.x;
	y = vec.y;
	return *this;		// this�͊O���ŊǗ�����Ă邩�� "*this" �ő��v
}

// �Y�������Z�q
template<class T>
int& Vector2Template<T>::operator[](int i)
{
	if (i == 0)
	{
		return x;
	}
	else if (i == 1)
	{
		return y;
	}
	else
	{
		return x;
	}
}

// ��r���Z�q
template<class T>
bool Vector2Template<T>::operator==(const Vector2Template& vec) const
{
	return ((this->x == vec.x) && (this->y == vec.y));		// ���ʂ̐�����Ԃ�
}

template<class T>
bool Vector2Template<T>::operator!=(const Vector2Template& vec) const
{
	return !((this->x == vec.x) && (this->y == vec.y));		// "==" �̔ے�Ȃ̂� "!" ������Ƃ悢
}

template<class T>
bool Vector2Template<T>::operator<=(const Vector2Template& vec) const
{
	return ((this->x <= vec.x) && (this->y <= vec.y));
}

template<class T>
bool Vector2Template<T>::operator<(const Vector2Template& vec) const
{
	return ((this->x < vec.x) && (this->y < vec.y));
}

template<class T>
bool Vector2Template<T>::operator>=(const Vector2Template& vec) const
{
	return ((this->x >= vec.x) && (this->y >= vec.y));
}

template<class T>
bool Vector2Template<T>::operator>(const Vector2Template& vec) const
{
	return ((this->x > vec.x) && (this->y > vec.y));
}

// �P�����Z�q
template<class T>
Vector2Template<T>& Vector2Template<T>::operator+=(const Vector2Template& vec)
{
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}

template<class T>
Vector2Template<T>& Vector2Template<T>::operator-=(const Vector2Template& vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	return *this;
}

template<class T>
Vector2Template<T>& Vector2Template<T>::operator*=(const T k)
{
	this->x *= k;
	this->y *= k;
	return *this;
}

template<class T>
Vector2Template<T>& Vector2Template<T>::operator/=(const T k)
{
	this->x /= k;
	this->y /= k;
	return *this;
}

template<class T>
Vector2Template<T> Vector2Template<T>::operator+() const
{
	return *this;
}

template<class T>
Vector2Template<T> Vector2Template<T>::operator-() const
{
	return Vector2Template(-this->x, -this->y);
}

// ----- �޸�ى��Z
// Vector2Template + int

template<class T>
Vector2Template<T> operator+(const Vector2Template<T>& u, const T v)
{
	return Vector2Template<T>((u.x + v), (u.y + v));		// "u"��۰�ٕϐ��B�v�Z�I����ɖ����������
}
// Vector2Template - int
template<class T>
Vector2Template<T> operator-(const Vector2Template<T>& u, const T v)
{
	return Vector2Template<T>((u.x - v), (u.y - v));
}
// Vector2Template + Vector2Template
template<class T>
Vector2Template<T> operator+(const Vector2Template<T>& u, const Vector2Template<T>& v)
{
	return Vector2Template<T>((u.x + v.x), (u.y + v.y));
}
// Vector2Template - Vector2Template
template<class T>
Vector2Template<T> operator-(const Vector2Template<T>& u, const Vector2Template<T>& v)
{
	return Vector2Template<T>((u.x - v.x), (u.y - v.y));
}
// int * Vector2Template
template<class T>
Vector2Template<T> operator*(const T k, const Vector2Template<T>& v)
{
	return Vector2Template<T>((k * v.x), (k * v.y));
}
// Vector2Template * int
template<class T>
Vector2Template<T> operator*(const Vector2Template<T>& v, const T k)
{
	return Vector2Template<T>((v.x * k), (v.y * k));
}
// Vector2Template / int
template<class T>
Vector2Template<T> operator/(const Vector2Template<T>& v, const T k)
{
	return Vector2Template<T>((v.x / k), (v.y / k));
}
// VECTRO2 % int
template<class T>
Vector2Template<T> operator%(const Vector2Template<T>& v, const T k)
{
	return Vector2Template<T>((v.x % k), (v.y % k));
}