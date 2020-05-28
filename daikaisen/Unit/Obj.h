#pragma once
#include <array>
#include <memory>
#include <vector>
#include <map>
#include "../Common/Vector2.h"

#define PI (3.1415926535)

enum class IFF		// G¡û¯Ê
{
	FRIEND,			// ¡û
	ENEMY,			// G
	BULLET,
	MAX
};

enum class SHIP
{
	BB,		// íÍ
	CV,		// óê
	CA,		// d
	CL,		// y
	DD,		// ì
	SS,		// ö
	MAX
};


class Obj;
using unique_Obj = std::unique_ptr<Obj>;
using shared_Obj = std::shared_ptr<Obj>;

class Obj
{
public:
	Obj();
	virtual ~Obj();
	virtual void Draw(void);
	virtual IFF GetIFF(void) = 0;
	virtual SHIP GetShipType(void) = 0;
	virtual int GetAtInter(void) = 0;
	virtual void Updata(void) = 0;

	const Vector2Dbl pos(void) const;			// m_posÌGetÖ
	double GetAngle(void);
	void SetPos(Vector2Dbl pos);
	void SetAngle(double angle);
	void SetDamage(int damage);
	void SetDeath(bool death);
	void SetVisible(bool visible);
	void SetAtInter(void);
	bool isDeath(void) { return m_death; };		// m_deathÌGetÖ

	Vector2Dbl GetShipPos(void);

protected:
	Vector2Dbl m_pos;
	Vector2Dbl m_distiPos;
	Vector2 m_size;
	double m_angle;
	int m_graph;	// ¼u«®çÀÁ­
	SHIP m_ship;													// ÍípÌÏ
	std::array<int, static_cast<int>(SHIP::MAX)> m_shipGra;			// Íí²ÆÌæ
	std::array<double, static_cast<int>(SHIP::MAX)> m_speedTbl;		// Íí²ÆÌ¬x
	int m_HP;											// Ïvl
	bool m_death;										// âÁ½©Ì×¸Þ
	bool m_visible;										// Â»Ì×¸Þ
	int m_atInter;										// Up²ÝÀ°ÊÞÙ
};

