#pragma once
#include "BaseScene.h"
#include "../Common/GameCtl.h"
#include "../Common/Vector2.h"


#define lpSceneMng SceneMng::GetInstance()

class GameCtl;

class SceneMng
{
public:
	static SceneMng& GetInstance(void)			// このｸﾗｽのﾎﾟｲﾝﾀを取得する、ここでｼﾝｸﾞﾙﾄﾝの状態にしている
	{
		static SceneMng s_Instance;
		return s_Instance;
	}
	void Run(void);
	Vector2 GetScreenSize(void);						// ｽｸﾘｰﾝｻｲｽﾞを取得する


private:
	SceneMng();
	~SceneMng();

	unique_Base activeScene;	// 各ｼｰﾝにｱｸｾｽするためのﾕﾆｰｸﾎﾟｲﾝﾀｰ

	std::shared_ptr<GameCtl> gameCtl;		// GameControllerｸﾗｽのﾎﾟｲﾝﾀ格納用変数

	bool SysInit(void);			// ｼｽﾃﾑ的な変数の初期化を行う
};

