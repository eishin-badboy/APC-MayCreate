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

// 代入演算子
template<class T>
Vector2Template<T>& Vector2Template<T>::operator=(const Vector2Template& vec)
{
	x = vec.x;
	y = vec.y;
	return *this;		// thisは外側で管理されてるから "*this" で大丈夫
}

// 添え字演算子
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

// 比較演算子
template<class T>
bool Vector2Template<T>::operator==(const Vector2Template& vec) const
{
	return ((this->x == vec.x) && (this->y == vec.y));		// 結果の正負を返す
}

template<class T>
bool Vector2Template<T>::operator!=(const Vector2Template& vec) const
{
	return !((this->x == vec.x) && (this->y == vec.y));		// "==" の否定なので "!" をつけるとよい
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

// 単項演算子
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

// ----- ﾍﾞｸﾄﾙ演算
// Vector2Template + int

template<class T>
Vector2Template<T> operator+(const Vector2Template<T>& u, const T v)
{
	return Vector2Template<T>((u.x + v), (u.y + v));		// "u"はﾛｰｶﾙ変数。計算終了後に無効化される
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