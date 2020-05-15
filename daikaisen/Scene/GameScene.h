#pragma once
#include <array>
#include <vector>
#include "BaseScene.h"
#include "../Unit/Obj.h"
#include "../Common/VECTOR2.h"


class GameScene : public BaseScene
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

	std::vector<shared_Obj> m_objList;		// Obj継承ｸﾗｽの可変配列

	int charaGra;				// ﾃｽﾄ用ｸﾞﾗﾌｨｯｸ
	VECTOR2 charaPos;			// ﾃｽﾄ用位地
	VECTOR2 mousePos;			// ﾏｳｽの位置
	float charaAngle;			// ﾃｽﾄ用の角度
	double rotaAngle;			// 回転角度

	VECTOR2 enemyPos;
	VECTOR2 bulletPos;
	bool bulletFlag;
	double bulAngle;
	int enemyHP;
	int bulDamage;
};