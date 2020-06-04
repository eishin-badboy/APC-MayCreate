#pragma once
#include "Obj.h"


class Bullet : public Obj
{
public:
	Bullet();
	Bullet(Vector2Dbl pos, Vector2 size, double angle);		// 位地、ｻｲｽﾞ、角度
	~Bullet();
	void Updata(void)override;				// 情報の更新関数
	IFF GetIFF(void)override;				// 所属の取得関数
	SHIP GetShipType(void)override;			// ﾕﾆｯﾄ種類の取得関数
	void Draw(void);						// 描画用の関数

	Vector2 GetSize(void);					// ｻｲｽﾞ取得関数

private:
	bool Init(void);						// 初期化用
};

