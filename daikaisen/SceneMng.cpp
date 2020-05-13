#include "Dxlib.h"	// DxLibﾗｲﾌﾞﾗﾘを使用する
#include "GameCtl.h"
#include "GameScene.h"
#include "SceneMng.h"


#define SCREEN_SIZE_X (1280)
#define SCREEN_SIZE_Y (720)


void SceneMng::Run(void)
{
	activeScene = std::make_unique<GameScene>();

	// ---------- ｹﾞｰﾑﾙｰﾌﾟ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		gameCtl->UpDate();

		ClsDrawScreen();

		activeScene = activeScene->UpDate(std::move(activeScene), *gameCtl);
		ScreenFlip();
	}
}

VECTOR2 SceneMng::GetScreenSize(void)
{
	return VECTOR2(SCREEN_SIZE_X, SCREEN_SIZE_Y);
}

SceneMng::SceneMng()
{
	SysInit();
}


SceneMng::~SceneMng()
{
}

bool SceneMng::SysInit(void)
{
	// ｼｽﾃﾑ処理
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);		// 65536色ﾓｰﾄﾞに設定
	ChangeWindowMode(true);				// true:window　false:ﾌﾙｽｸﾘｰﾝ
	SetWindowText("大海戦");
	if (DxLib_Init() == -1) return false;	// DXﾗｲﾌﾞﾗﾘ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);			// ひとまずﾊﾞｯｸﾊﾞｯﾌｧに描画
	gameCtl = std::make_unique<GameCtl>();
	return true;
}
