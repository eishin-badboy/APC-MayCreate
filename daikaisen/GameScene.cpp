#include <stdlib.h>
#include <time.h>
#include "Dxlib.h"
#include "SceneMng.h"
#include "ImageMng.h"
#include "GameScene.h"
#include "GameCtl.h"

#define PI (3.1415926535)

GameScene::GameScene()
{
	Init();
}


GameScene::~GameScene()
{
}

unique_Base GameScene::UpDate(unique_Base own, const GameCtl& controller)
{
	auto radius = rotaAngle * PI / 180.0f;

	// ¶¸Ø¯¸‚µ‚½‚Æ‚«
	if ((GetMouseInput() & MOUSE_INPUT_LEFT))
	{
		GetMousePoint(&mousePos.x, &mousePos.y);
		charaAngle = atan2(mousePos.y - charaPos.y, mousePos.x - charaPos.x) + (PI / 2);
	}

	// ˆÊ’n‚ªˆá‚¤Žž
	if (charaPos.x > mousePos.x)
	{
		charaPos.x -= 10 * abs(sin(charaAngle));
	}
	if (charaPos.x < mousePos.x)
	{
		charaPos.x += 10 * abs(sin(charaAngle));
	}
	if (charaPos.y > mousePos.y)
	{
		charaPos.y -= 10 * abs(cos(charaAngle));
	}
	if (charaPos.y < mousePos.y)
	{
		charaPos.y += 10 * abs(cos(charaAngle));
	}


	// •`‰æˆ—
	GameDraw();
	return std::move(own);
}

int GameScene::Init(void)
{
	charaGra = LoadGraph("image/player.png");
	charaPos = VECTOR2(500, 210);
	charaAngle = 0;
	rotaAngle = 270;
	return 0;
}

bool GameScene::CheckGameEnd(void)
{
	return false;
}

bool GameScene::GameDraw(void)
{
	DrawRotaGraph(charaPos.x, charaPos.y, 1.0, charaAngle, charaGra, false);

	return true;
}
