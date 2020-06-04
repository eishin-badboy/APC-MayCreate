#include "ResultScene.h"
#include "Dxlib.h"
#include "SceneMng.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "../Common/ImageMng.h"
#include "../Common/GameCtl.h"


ResultScene::ResultScene()
{
	Init();
}

ResultScene::~ResultScene()
{
	DeleteGraph(backGra);
}

unique_Base ResultScene::UpDate(unique_Base own, const GameCtl& controller)
{
	if ((GetMouseInput() & MOUSE_INPUT_LEFT))
	{
		return std::make_unique<TitleScene>();
	}
	Draw();
	return std::move(own);
}

int ResultScene::Init(void)
{
	backGra = LoadGraph("image/result.png");
	return 0;
}

void ResultScene::Draw(void)
{
	DrawRotaGraph((1920 / 2), (1080 / 2), 1, 0, backGra, true);
}
