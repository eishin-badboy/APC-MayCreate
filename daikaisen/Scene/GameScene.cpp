#include <stdlib.h>
#include <time.h>
#include "Dxlib.h"
#include "SceneMng.h"
#include "GameScene.h"
#include "../Common/ImageMng.h"
#include "../Common/GameCtl.h"

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
	// ”z—ñ‚É“o˜^‚³‚ê‚Ä‚¢‚é‘SÕÆ¯Ä‚Ìs“®XV
	for (auto obj : m_objList)
	{
		obj->Updata();
	}

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
	float hit = sqrt(pow(bulletPos.x - enemyPos.x, 2) + pow(bulletPos.y - enemyPos.y, 2));
	if (c <= 270 + 45)
	{
		bulletFlag = true;
	}

	// –½’†
	if (hit <= 45)
	{
		enemyHP -= bulDamage;
		bulletFlag = false;
	}

	// –C’eˆ—
	if (bulletFlag)
	{
		bulAngle = atan2(enemyPos.y - bulletPos.y, enemyPos.x - bulletPos.x)/* + (PI / 2)*/;

		bulletPos.x += cos(bulAngle) * 6;
		bulletPos.y += sin(bulAngle) * 6;
		//if (bulletPos.x > enemyPos.x)
		//{
		//	bulletPos.x -= 15 * abs(cos(bulAngle));
		//}
		//if (bulletPos.x < enemyPos.x)
		//{
		//	bulletPos.x += 15 * abs(cos(bulAngle));
		//}
		//if (bulletPos.y > enemyPos.y)
		//{
		//	bulletPos.y -= 15 * abs(sin(bulAngle));
		//}
		//if (bulletPos.y < enemyPos.y)
		//{
		//	bulletPos.y += 15 * abs(sin(bulAngle));
		//}
	}
	else
	{
		bulletPos = charaPos;
	}

	if (bulletPos.x > 1280 || bulletPos.x < 0 || bulletPos.y > 800 || bulletPos.y < 0)
	{
		bulletFlag = false;
	}

	// •`‰æˆ—
	GameDraw();
	return std::move(own);
}

int GameScene::Init(void)
{
	charaGra = LoadGraph("image/player.png");
	charaPos = Vector2Dbl(500, 210);
	charaAngle = 0;
	rotaAngle = 270;
	enemyPos = Vector2Dbl(900, 90);
	bulletPos = charaPos;
	bulletFlag = false;
	bulAngle = 0;
	bulDamage = 1;
	enemyHP = 5;
	return 0;
}

bool GameScene::CheckGameEnd(void)
{
	return false;
}

bool GameScene::GameDraw(void)
{

	DrawRotaGraph(charaPos.x, charaPos.y, 0.5f, charaAngle, charaGra, true);
	DrawCircle(charaPos.x, charaPos.y, 270, GetColor(0, 255, 255), false);
	if (enemyHP > 0)
	{
		DrawRotaGraph(enemyPos.x, enemyPos.y, 0.5f, 0, LoadGraph("image/enemy.png"), true);
		DrawCircle(enemyPos.x, enemyPos.y, 45, GetColor(255, 0, 255), false);
	}
	if (bulletFlag)
	{
		DrawCircle(bulletPos.x, bulletPos.y, 5, GetColor(255, 255, 255), true);
	}
	return true;
}
