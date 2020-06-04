#pragma once
#include "Obj.h"


class Aircraft : public Obj
{
public:
	Aircraft();
	Aircraft(Vector2Dbl pos, Vector2 size, IFF iff, int HP, bool visible, bool turn);	// 位地、ｻｲｽﾞ、敵味方識別、体力、可視化、帰還ﾌﾗｸﾞ
	~Aircraft();
	void Updata(void)override;					// 情報更新の関数
	IFF GetIFF(void)override;					// 所属の取得関数
	bool GetDeath(void)override;				// 死亡情報の取得関数
	Vector2Dbl GetDistPos(void)override;		// 目的地の取得関数

	SHIP GetShipType(void)override;				// ﾕﾆｯﾄ(敵)の情報取得の関数（未使用）
	int GetAtInter(void)override;				// 攻撃範囲の取得関数（未使用）

private:
	bool Init(void);							// 初期化の関数
};

