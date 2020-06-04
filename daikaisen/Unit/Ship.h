#pragma once
#include <array>
#include "../Common/Vector2.h"

enum class SHIP_TYPE
{
	BB,		// 戦艦
	CV,		// 空母
	CA,		// 重巡
	CL,		// 軽巡
	DD,		// 駆逐
	SS,		// 潜水
	MAX
};


class Ship
{
public:
	Ship();
	~Ship();
	void Draw(void);			// 描画
	void Updata(void);			//　情報更新

	Vector2 GetSize(void);		// ｻｲｽﾞの取得

private:
	bool Init(void);			// 初期化
	double m_speed;				// 移動速度

};

