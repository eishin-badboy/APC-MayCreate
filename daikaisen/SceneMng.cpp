#include "Dxlib.h"	// DxLibײ���؂��g�p����
#include "GameCtl.h"
#include "GameScene.h"
#include "SceneMng.h"


#define SCREEN_SIZE_X (1280)
#define SCREEN_SIZE_Y (720)


void SceneMng::Run(void)
{
	activeScene = std::make_unique<GameScene>();

	// ---------- �ް�ٰ��
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
	// ���я���
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);		// 65536�FӰ�ނɐݒ�
	ChangeWindowMode(true);				// true:window�@false:�ٽ�ذ�
	SetWindowText("��C��");
	if (DxLib_Init() == -1) return false;	// DXײ���؏���������
	SetDrawScreen(DX_SCREEN_BACK);			// �ЂƂ܂��ޯ��ޯ̧�ɕ`��
	gameCtl = std::make_unique<GameCtl>();
	return true;
}
