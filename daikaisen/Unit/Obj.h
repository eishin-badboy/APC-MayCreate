#pragma once
#include <array>
#include <memory>
#include <vector>
#include <map>
#include "../Common/Vector2.h"

enum class IFF		// 敵味方識別
{
	FRIEND,			// 味方
	ENEMY,			// 敵
	MAX
};

enum class SHIP
{
	BB,		// 戦艦
	CV,		// 空母
	CA,		// 重巡
	CL,		// 軽巡
	DD,		// 駆逐
	SS,		// 潜水
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
	virtual void Updata(void) = 0;

	Vector2Dbl GetShipPos(void);

protected:
	Vector2Dbl m_pos;
	Vector2Dbl m_distiPos;
	Vector2 m_size;
	double m_angle;
	int m_graph;	// 仮置きぐらぢっく
	SHIP m_ship;													// 艦種用の変数
	std::array<int, static_cast<int>(SHIP::MAX)> m_shipGra;			// 艦種ごとの画像
	std::array<double, static_cast<int>(SHIP::MAX)> m_speedTbl;		// 艦種ごとの速度
};

