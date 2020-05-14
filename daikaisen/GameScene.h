#pragma once
#include "BaseScene.h"
#include <array>
#include "VECTOR2.h"

class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();
	unique_Base UpDate(unique_Base own, const GameCtl& controller);


private:
	VECTOR2 sSize;				// 画面ｻｲｽﾞ

	int Init(void);
	bool CheckGameEnd(void);	// 勝敗をチェック		
	bool GameDraw(void);		// 描画処理

	int charaGra;				// ﾃｽﾄ用ｸﾞﾗﾌｨｯｸ
	VECTOR2 charaPos;			// ﾃｽﾄ用位地
	VECTOR2 mousePos;			// ﾏｳｽの位置
	float charaAngle;			// ﾃｽﾄ用の角度
	double rotaAngle;			// 回転角度

	VECTOR2 enemyPos;
};