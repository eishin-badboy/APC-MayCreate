#pragma once
#include <list>
#include <array>
#include <vector>
#include <memory>
#include "BaseScene.h"
#include "../Unit/Obj.h"
#include "../Common/Vector2.h"


class GameScene : public BaseScene
{
public:
	GameScene();
	~GameScene();
	unique_Base UpDate(unique_Base own, const GameCtl& controller);


private:
	Vector2 sSize;				// 画面ｻｲｽﾞ

	int Init(void);
	bool CheckGameEnd(void);	// 勝敗をチェック		
	bool GameDraw(void);		// 描画処理

	std::vector<shared_Obj> m_objList;		// Obj継承ｸﾗｽの可変配列

	int charaGra;				// ﾃｽﾄ用ｸﾞﾗﾌｨｯｸ
	Vector2Dbl charaPos;		// ﾃｽﾄ用位地
	Vector2 mousePos;			// ﾏｳｽの位置
	float charaAngle;			// ﾃｽﾄ用の角度
	double rotaAngle;			// 回転角度

	Vector2Dbl enemyPos;
	Vector2Dbl bulletPos;
	bool bulletFlag;
	double bulAngle;
	int enemyHP;
	int bulDamage;
};