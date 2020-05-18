#pragma once
#include <array>
#include "Obj.h"


class Enemy : public Obj
{
public:
	Enemy();
	Enemy(Vector2Dbl pos, Vector2Dbl size, SHIP ship, IFF iff);
	~Enemy();
	SHIP GetShipType(void)override;		// ﾕﾆｯﾄ(敵)の情報取得の関数
	IFF GetIFF(void)override;
	void Updata(void)override;			// 情報更新の関数

	Vector2 GetSize(void);				// 敵のｻｲｽﾞを受け取る関数

private:
	bool Init(void);

};

