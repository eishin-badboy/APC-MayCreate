#include "TitleScene.h"
#include "Dxlib.h"
#include "SceneMng.h"
#include "GameScene.h"
#include "../Common/ImageMng.h"
#include "../Common/GameCtl.h"


TitleScene::TitleScene()
{
	Init();
}

TitleScene::~TitleScene()
{
	DeleteGraph(titMov);
	DeleteGraph(rogo);
	DeleteGraph(flash);
	DeleteGraph(moveEffect);
	DeleteSoundMem(titBGM);
}

unique_Base TitleScene::UpDate(unique_Base own, const GameCtl& controller)
{
	if (CheckSoundMem(titBGM) == 0)
	{
		PlaySoundMem(titBGM, DX_PLAYTYPE_BACK);
	}

	if ((GetMouseInput() & MOUSE_INPUT_LEFT))
	{
		fadeFlag = true;
	}

	if (fadeFlag)
	{
		rate += (5.0f / 60);
		angle += 10.0f;
		fadeCnt++;
	}

	if (fadeCnt >= 60 * 2)
	{
		return std::make_unique<GameScene>();
	}

	Draw();
	flashCnt++;
	return std::move(own);
}

int TitleScene::Init(void)
{
	titMov = LoadGraph("image/title.mp4");
	PlayMovieToGraph(titMov);
	rogo = LoadGraph("image/rogo.png");
	titBGM = LoadSoundMem("bgm/title.mp3");
	fadeFlag = false;
	flash = LoadGraph("image/click.png");
	flashCnt = 0;
	moveEffect = LoadGraph("image/black.png");
	angle = 10.0f;
	rate = 0.1f;
	fadeCnt = 0;
	return 0;
}

void TitleScene::Draw(void)
{
	if (GetMovieStateToGraph(titMov) == 1)
	{
		DrawGraph(0, 0, titMov, false);
	}
	DrawRotaGraph((1920 / 2), 300, 1.5f, 0, rogo, true);
	if ((flashCnt / 60) % 2 == 0)
	{
		DrawRotaGraph((1920 / 2), (1080 / 2 +100), 0.5f, 0, flash, true);
	}
	if (fadeFlag)
	{
		DrawRotaGraph((1920 / 2), (1080 / 2), rate, angle, moveEffect, true);
	}
}
