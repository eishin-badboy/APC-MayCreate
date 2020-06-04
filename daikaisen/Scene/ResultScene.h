#pragma once
#include "BaseScene.h"
#include "../Common/Vector2.h"

class ResultScene : public BaseScene
{
public:
	ResultScene();
	~ResultScene();
	unique_Base UpDate(unique_Base own, const GameCtl& controller);		// 情報更新


private:
	int Init(void);			// 初期化
	void Draw(void);		// 描画

	Vector2 sSize;			// 画面ｻｲｽﾞ
	int backGra;			// 背景画像
};

