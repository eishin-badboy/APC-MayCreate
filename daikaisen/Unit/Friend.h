#pragma once
#include "Obj.h"


class Friend : public Obj
{
public:
	Friend();
	Friend(Vector2Dbl pos, Vector2 size, SHIP ship, IFF iff, int HP, bool visible);		// 位地、ｻｲｽﾞ、艦種、所属、体力、可視化
	~Friend();
	void Updata(void)override;					// 情報更新の関数
	SHIP GetShipType(void)override;				// ﾕﾆｯﾄ(敵)の情報取得の関数
	IFF GetIFF(void)override;					// 所属の取得関数
	int GetAtInter(void)override;				// 攻撃範囲の取得関数
	bool GetDeath(void)override;				// 死亡の取得関数
	Vector2Dbl GetDistPos(void)override;		// 目的地の取得
	Vector2 GetSize(void);						// 敵のｻｲｽﾞを受け取る関数

private:
	bool Init(void);							// 初期化

	Vector2 mousePos;							// ﾏｳｽの位置
	
};

