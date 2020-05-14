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

	float c = sqrt(pow(charaPos.x - enemyPos.x, 2) + pow(charaPos.y - enemyPos.y, 2));

	if (c <= 90 + 45)
	{
		int i = 0;
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
	enemyPos = VECTOR2(900, 90);
	return 0;
}

bool GameScene::CheckGameEnd(void)
{
	return false;
}

bool GameScene::GameDraw(void)
{
	DrawRotaGraph(charaPos.x, charaPos.y, 0.5f, charaAngle, charaGra, false);
	DrawRotaGraph(enemyPos.x, enemyPos.y, 0.5f, 0, LoadGraph("image/enemy.png"), false);
	DrawCircle(charaPos.x, charaPos.y, 90, GetColor(255, 255, 255), false);
	DrawCircle(enemyPos.x, enemyPos.y, 45, GetColor(255, 0, 255), false);

	return true;
}
