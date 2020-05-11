#pragma once
class VECTOR2
{
public:
	VECTOR2();
	VECTOR2(int x, int y);
	~VECTOR2();
	int x;
	int y;

	//ë„ì¸ââéZéq
	VECTOR2& operator=(const VECTOR2& vec);

	//ìYÇ¶éöââéZéq
	int& operator[](int i);

	//î‰ärââéZéq
	bool operator==(const VECTOR2& vec) const;
	bool operator==(int k);

	bool operator!=(const VECTOR2& vec) const;

	bool operator<(const VECTOR2& vec) const;
	bool operator<=(const VECTOR2& vec) const;

	bool operator<(int k);
	bool operator<=(int k);

	bool operator>(const VECTOR2& vec) const;
	bool operator>=(const VECTOR2& vec) const;

	bool operator>(int k);
	bool operator>=(int k);

	//íPçÄââéZéq
	VECTOR2& operator +=(const VECTOR2& vec);
	VECTOR2& operator -=(const VECTOR2& vec);
	VECTOR2& operator *=(int k);
	VECTOR2& operator /=(int k);
	VECTOR2  operator+()const;
	VECTOR2  operator-()const;
};

//ÉxÉNÉgÉãÇÃââéZ
//VECTOR2 + int
VECTOR2 operator+(const VECTOR2 &u, int v);

//VECTOR2 - int
VECTOR2 operator-(const VECTOR2 &u, int v);

//VECTOR2 + VECTOR2
VECTOR2 operator+(const VECTOR2 &u, const VECTOR2 &v);

//VECTOR2 - VECTOR2
VECTOR2 operator-(const VECTOR2 &u, const VECTOR2 &v);

//VECTOR2 * int
VECTOR2 operator*(const VECTOR2 &u, int k);

//int * VECTOR2
VECTOR2 operator*(int k, const VECTOR2 &u);

//VECTOR2 / int
VECTOR2 operator/(const VECTOR2 &u, int k);

//VECTOR2 / VECTOR2
VECTOR2 operator/(const VECTOR2 &u, const VECTOR2 &v);

//VECTOR2 % int
VECTOR2 operator%(const VECTOR2 &u, int k);

//VECTOR2 % VECTOR2
VECTOR2 operator%(const VECTOR2 &u, const VECTOR2 &v);
