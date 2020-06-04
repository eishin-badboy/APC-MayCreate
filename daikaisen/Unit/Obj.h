#pragma once
#include <array>
#include <memory>
#include <vector>
#include <map>
#include "../Common/Vector2.h"

#define PI (3.1415926535)

enum class IFF		// 敵味方識別
{
	FRIEND,			// 味方
	ENEMY,			// 敵
	BULLET,			// 砲弾
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
	virtual void Draw(void);					// 描画
	virtual IFF GetIFF(void) = 0;				// 所属取得関数
	virtual SHIP GetShipType(void) = 0;			// 艦種取得関数
	virtual int GetAtInter(void) = 0;			// 攻撃範囲取得関数
	virtual void Updata(void) = 0;				// 情報更新関数
	virtual bool GetDeath(void) = 0;			// 死亡取得関数
	virtual Vector2Dbl GetDistPos(void) = 0;	// 目的地取得関数
	double GetAngle(void);						// 角度の取得関数

	const Vector2Dbl pos(void) const;			// 位地の取得関数
	void SetDistPos(Vector2Dbl distPos);		// 目的地の設定関数
	void SetPos(Vector2Dbl pos);				// 位地の設定関数
	void SetAngle(double angle);				// 角度の設定関数
	void SetDamage(int damage);					// ﾀﾞﾒｰｼﾞの設定関数
	void SetDeath(bool death);					// 死亡の設定関数
	void SetVisible(bool visible);				// 可視化の設定関数
	void SetAtInter(void);						// 攻撃範囲の設定関数
	bool isDeath(void) { return m_death; };		// m_deathのGet関数

	Vector2Dbl GetShipPos(void);				// 位地の取得関数

	void SetTurn(bool turn);					// 帰還ﾌﾗｸﾞの設定関数
	bool GetTurn(void);							// 帰還ﾌﾗｸﾞの取得関数

protected:
	Vector2Dbl m_pos;												// 位地
	Vector2Dbl m_distPos;											// 目的地
	Vector2 m_size;													// ｻｲｽﾞ
	double m_angle;													// 角度
	int m_graph;													// 仮置き画像
	SHIP m_ship;													// 艦種用の変数
	IFF m_iff;														// 所属
	std::array<int, static_cast<int>(SHIP::MAX)> m_shipGra;			// 艦種ごとの画像
	std::array<double, static_cast<int>(SHIP::MAX)> m_speedTbl;		// 艦種ごとの速度
	int m_HP;														// 耐久値
	bool m_death;													// やったかﾌﾗｸﾞ
	bool m_visible;													// 可視化ﾌﾗｸﾞ
	int m_atInter;													// 攻撃用ｲﾝﾀｰﾊﾞﾙ
	int m_atGra;													// 攻撃画像
	int m_explo;													// 爆発画像
	int m_animCnt;													// ｱﾆﾒｰｼｮﾝのｺﾏｶｳﾝﾄ変数
	bool m_turnFlag;												// 航空機用帰還ﾌﾗｸﾞ
};

