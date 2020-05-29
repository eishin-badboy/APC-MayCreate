#include <stdlib.h>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iterator>

#include "Dxlib.h"
#include "SceneMng.h"
#include "GameScene.h"
#include "../Unit/Friend.h"
#include "../Unit/Enemy.h"
#include "../Unit/Bullet.h"
#include "../Common/ImageMng.h"
#include "../Common/GameCtl.h"

#define PI (3.1415926535)
#define MAP_RATE (3.84)		// 3840/1000
#define MINI_RATE_X (11.2280701754)	// 3840/342
#define MINI_RATE_Y (16.4806866952)				// 3840/233

GameScene::GameScene()
{
	Init();
}


GameScene::~GameScene()
{
	//DeleteGraph(waveBG);
}

unique_Base GameScene::UpDate(unique_Base own, const GameCtl& controller)
{
	GetMousePoint(&mousePos.x, &mousePos.y);
	// あとで解除@@@
	{
		//if (!bgmStart)
		//{
		//	PlaySoundMem(gameBGM, DX_PLAYTYPE_LOOP);
		//	bgmStart = true;
		//}
		//if (CheckSoundMem(gameBGM) == 0)
		//{
		//	bgmStart = false;
		//}
	}

	// 配列に登録されている全ﾕﾆｯﾄの行動更新
	for (auto obj : m_objList)
	{
		obj->Updata();
	}

	for (auto obj : f_fleetListF)
	{
		obj->Updata();
	}

	// 移動ｺﾏﾝﾄﾞを選択
	if (!uiHide && (mousePos.x > movePos.x && mousePos.x < mousePos.x + 160) && (mousePos.y > movePos.y && mousePos.y < movePos.y + 54))
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT))
		{
			uiHide = true;
			mapVis = true;
		}
	}

	// 偵察ｺﾏﾝﾄﾞを選択
	if (!uiHide && (mousePos.x > searPos.x && mousePos.x < searPos.x + 160) && (mousePos.y > searPos.y && mousePos.y < searPos.y + 54))
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT))
		{
			uiHide = true;
			searFlag = true;
		}
	}


	//342:235
	Vector2Dbl testPos = f_fleetListF[0]->pos();
	miniFfPos = Vector2Dbl((miniPos.x + 33) + (testPos.x / MINI_RATE_X)+(viewPos.x / MINI_RATE_X), (miniPos.y + 12) + (testPos.y / MINI_RATE_Y)+(viewPos.y/ MINI_RATE_Y));
	// ﾐﾆﾏｯﾌﾟ


	// 移動地点決め
	if (mapVis)
	{
		CheckDistina();
	}
	// 偵察地点決め
	if (searFlag)
	{
		Searching();
	}

	ViewMove();
	FleetMove();		// 艦隊移動


	for (auto obj : m_objList)
	{
		if (obj->GetIFF() == IFF::ENEMY)
		{
			for (auto other : f_fleetListF)
			{
				//if (other->GetIFF() == IFF::FRIEND)
				//{

				float c = sqrt(pow(other->pos().x - obj->pos().x, 2) + pow(other->pos().y - obj->pos().y, 2));
				// 索敵範囲内
				if (c > 900 + 45)
				{
					obj->SetVisible(false);
				}
				if (c <= 500 + 45)
				{
					obj->SetVisible(true);
				}
				// 攻撃範囲内
				if (c <= 400 + 45)
				{
					other->SetAtInter();
					if (other->GetAtInter() % (60 * 5) == 0)
					{
						PlaySoundMem(shotSe, DX_PLAYTYPE_BACK);
						obj->SetDamage(1);
					}
					//bulAngle = atan2(enemyPos.y - bulletPos.y, enemyPos.x - bulletPos.x)/* + (PI / 2)*/;
					//m_objList.emplace_back(new Bullet(Vector2Dbl(90,90), { 90, 90 }, bulAngle));
					//bulletFlag = true;
				}
			}
		}
	}
	cloPos.x++;
	cloPos.y--;
	if (cloPos.y < -730)
	{
		cloPos = { -100, 1800 };
	}

	m_objList.erase(std::remove_if(m_objList.begin(), m_objList.end(),
		[](shared_Obj& obj) {return (*obj).isDeath(); }), m_objList.end());

	// 描画処理
	GameDraw();
	return std::move(own);
}

int GameScene::Init(void)
{
	viewPos = Vector2Dbl(0, 0);
	viewSpeed = 3;

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

	for (int no = 0; no < 4; no++)
	{
		f_fleetListF.emplace_back(new Friend({ 500,210}, { 90, 90 }, SHIP::BB, IFF::FRIEND, 5, true));;
	}

	m_objList.emplace_back(new Enemy({ 1300, 90 }, { 90, 90 }, SHIP::BB, IFF::ENEMY, 10, false));

	waveBG = LoadGraph("image/sea.png");
	cloudGra = LoadGraph("image/cloud.png");
	cloPos = Vector2Dbl(-100, 1800);

	miniDistPos = { 0,0 };

	gameBGM = LoadSoundMem("bgm/game.mp3");
	bgmStart = false;

	shotSe = LoadSoundMem("se/shot.mp3");
	rogerSe = LoadSoundMem("se/roger.wav");
	// UI関連
	{
		miniMap = LoadGraph("image/miniMap.png");
		miniPos = Vector2Dbl(0, 1080 - 275);
		info = LoadGraph("image/info.png");
		infoPos = Vector2Dbl(422, 1080 - 210);
		task = LoadGraph("image/task.png");
		taskPos = Vector2Dbl(420 + 1150, 1080 - 230);
		poliIco = LoadGraph("image/policy.png");
		poliPos = Vector2Dbl(420 + 1150 + 10, 1080 - 230 + 20);
		moveIco = LoadGraph("image/move.png");
		movePos = Vector2Dbl(420 + 1150 + 160 + 20, 1080 - 230 + 20);
		attIco = LoadGraph("image/attack.png");
		attPos = Vector2Dbl(420 + 1150 + 10, 1080 - 230 + 53 + 40);
		searIco = LoadGraph("image/search.png");
		searPos = Vector2Dbl(420 + 1150 + 160 + 20, 1080 - 230 + 53 + 40);
		retIco = LoadGraph("image/retreat.png");
		retPos = Vector2Dbl(420 + 1150 + 160 + 20, 1080 - 230 + 53*2 + 20*3);

		uiHide = false;
		mapVis = false;
		mapGra = LoadGraph("image/map.png");
		mapPos = Vector2Dbl((880 / 2), 20);
		disGra = LoadGraph("image/flag.png");
		searFlag = false;
	}

	return 0;
}

void GameScene::FleetMove(void)
{
	// 位地が違う時
	if (f_fleetListF[0]->pos().x > distiPos.x)
	{
		f_fleetListF[0]->SetPos({ f_fleetListF[0]->pos().x - abs(0.5f * sin(f_fleetListF[0]->GetAngle())), f_fleetListF[0]->pos().y });
	}
	if (f_fleetListF[0]->pos().x < distiPos.x)
	{
		f_fleetListF[0]->SetPos({ f_fleetListF[0]->pos().x + abs(0.5f * sin(f_fleetListF[0]->GetAngle())), f_fleetListF[0]->pos().y });
	}
	if (f_fleetListF[0]->pos().y > distiPos.y)
	{
		f_fleetListF[0]->SetPos({ f_fleetListF[0]->pos().x, f_fleetListF[0]->pos().y - abs(0.5f * cos(f_fleetListF[0]->GetAngle())) });
	}
	if (f_fleetListF[0]->pos().y < distiPos.y)
	{
		f_fleetListF[0]->SetPos({ f_fleetListF[0]->pos().x, f_fleetListF[0]->pos().y + abs(0.5f * cos(f_fleetListF[0]->GetAngle())) });
	}

	// 随伴艦の挙動
	for (int no = 1; no < 4; no++)
	{
		f_fleetListF[no]->SetAngle(atan2(f_fleetListF[no - 1]->pos().y - f_fleetListF[no]->pos().y, f_fleetListF[no - 1]->pos().x - f_fleetListF[no]->pos().x) + (PI / 2));
		// 位地が違う時
		if (f_fleetListF[no]->pos().x > f_fleetListF[no - 1]->pos().x + abs((120 * sin(f_fleetListF[no - 1]->GetAngle()))))
		{
			f_fleetListF[no]->SetPos({ f_fleetListF[no]->pos().x - abs(0.5f * (sin(f_fleetListF[no]->GetAngle()))), f_fleetListF[no]->pos().y });
		}
		if (f_fleetListF[no]->pos().x < f_fleetListF[no - 1]->pos().x - abs((120 * sin(f_fleetListF[no - 1]->GetAngle()))))
		{
			f_fleetListF[no]->SetPos({ f_fleetListF[no]->pos().x + abs(0.5f * (sin(f_fleetListF[no]->GetAngle()))), f_fleetListF[no]->pos().y });
		}
		if (f_fleetListF[no]->pos().y > f_fleetListF[no - 1]->pos().y + abs(120 * cos(f_fleetListF[no - 1]->GetAngle())))
		{
			f_fleetListF[no]->SetPos({ f_fleetListF[no]->pos().x, f_fleetListF[no]->pos().y - abs(0.5f * (cos(f_fleetListF[no]->GetAngle()))) });
		}
		if (f_fleetListF[no]->pos().y < f_fleetListF[no - 1]->pos().y - abs(120 * cos(f_fleetListF[no - 1]->GetAngle())))
		{
			f_fleetListF[no]->SetPos({ f_fleetListF[no]->pos().x, f_fleetListF[no]->pos().y + abs(0.5f * (cos(f_fleetListF[no]->GetAngle()))) });
		}
	}

}

void GameScene::CheckDistina(void)
{
	Vector2Dbl testPos = f_fleetListF[0]->pos();
	miniShipPos = Vector2Dbl(mapPos.x + (testPos.x / MAP_RATE) + (viewPos.x / MAP_RATE), mapPos.y + (testPos.y / MAP_RATE) +(viewPos.y / MAP_RATE));
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT))
	{
		mapVis = false;
		uiHide = false;
	}
	// 左ｸﾘｯｸしたとき
	if ((mousePos.x > mapPos.x +20  && mousePos.x < mapPos.x +20 + 1000) && (mousePos.y > mapPos.y+20 && mousePos.y < mapPos.y+20 + 1000))
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT))
		{
			miniDistPos = mousePos;
			distiPos = Vector2Dbl(((mousePos.x - mapPos.x) * MAP_RATE)-viewPos.x, ((mousePos.y - mapPos.y) * MAP_RATE)-viewPos.y);					// ﾏｯﾌﾟ内で選択した地点を復元
			f_fleetListF[0]->SetAngle(atan2(mousePos.y - miniShipPos.y, mousePos.x - miniShipPos.x) + (PI / 2));
			mapVis = false;
			uiHide = false;
			PlaySoundMem(rogerSe, DX_PLAYTYPE_BACK);
		}
	}
}

void GameScene::Searching(void)
{
	Vector2Dbl testPos = f_fleetListF[0]->pos();
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT))
	{
		searFlag = false;
		uiHide = false;
	}
	// 左ｸﾘｯｸしたとき
	if ((mousePos.x > mapPos.x + 20 && mousePos.x < mapPos.x + 20 + 1000) && (mousePos.y > mapPos.y+20 && mousePos.y < mapPos.y+20 + 1000))
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT))
		{
			searDist = mousePos;
			searFlag = false;
			uiHide = false;
			PlaySoundMem(rogerSe, DX_PLAYTYPE_BACK);
		}
	}

}

// 視点移動
void GameScene::ViewMove(void)
{
	if (viewPos.x <= 1920 && mousePos.x > 1920 - 10)
	{
		viewPos.x += viewSpeed;
		distiPos.x -= viewSpeed;
		for (int no = 0; no < 4; no++)
		{
			f_fleetListF[no]->SetPos({ f_fleetListF[no]->pos().x - viewSpeed, f_fleetListF[no]->pos().y });
		}
	}
	if (viewPos.x >= 0 && mousePos.x < 10)
	{
		viewPos.x -= viewSpeed;
		distiPos.x += viewSpeed;

		for (int no = 0; no < 4; no++)
		{
			f_fleetListF[no]->SetPos({ f_fleetListF[no]->pos().x + viewSpeed, f_fleetListF[no]->pos().y });
		}
	}
	if (viewPos.y <= 3840 - 1080 && mousePos.y > 1080 - 10)
	{
		viewPos.y += viewSpeed;
		distiPos.y -= viewSpeed;

		for (int no = 0; no < 4; no++)
		{
			f_fleetListF[no]->SetPos({ f_fleetListF[no]->pos().x, f_fleetListF[no]->pos().y - viewSpeed });
		}
	}
	if (viewPos.y >= 0 && mousePos.y < 10)
	{
		viewPos.y -= viewSpeed;
		distiPos.y += viewSpeed;

		for (int no = 0; no < 4; no++)
		{
			f_fleetListF[no]->SetPos({ f_fleetListF[no]->pos().x, f_fleetListF[no]->pos().y + viewSpeed });
		}
	}
}

bool GameScene::CheckGameEnd(void)
{
	return false;
}

bool GameScene::GameDraw(void)
{
	DrawRotaGraph(960, 540, 2.5f, 0, waveBG, true);

	for (auto& obj : m_objList)
	{
		obj->Obj::Draw();
	}

	for (auto& obj : f_fleetListF)
	{
		obj->Obj::Draw();
	}


	//DrawRotaGraph(500, 500, 0.5f, 90/PI, charaGra, true);
	//DrawCircle(charaPos.x, charaPos.y, 270, GetColor(0, 255, 255), false);
	//if (enemyHP > 0)
	//{
	//	DrawRotaGraph(enemyPos.x, enemyPos.y, 0.5f, 0, LoadGraph("image/enemy.png"), true);
	//	DrawCircle(enemyPos.x, enemyPos.y, 45, GetColor(255, 0, 255), false);
	//}
	if (bulletFlag)
	{
		DrawCircle(bulletPos.x, bulletPos.y, 5, GetColor(255, 255, 255), true);
	}

	DrawRotaGraph(cloPos.x, cloPos.y, 1.0f, 0, cloudGra, true);

	if (!uiHide)
	{
		DrawGraph(miniPos.x, miniPos.y, miniMap, true);
		DrawGraph(infoPos.x, infoPos.y, info, true);
		DrawGraph(taskPos.x, taskPos.y, task, true);
		DrawGraph(poliPos.x, poliPos.y, poliIco, true);
		DrawGraph(movePos.x, movePos.y, moveIco, true);
		DrawGraph(attPos.x, attPos.y, attIco, true);
		DrawGraph(searPos.x, searPos.y, searIco, true);
		DrawGraph(retPos.x, retPos.y, retIco, true);

		DrawCircle(miniFfPos.x, miniFfPos.y, (25 / 5), GetColor(0, 255, 0), true);
		DrawBox(((viewPos.x/MINI_RATE_X) + 33), ((viewPos.y/ MINI_RATE_Y) + 12 +(1080-275)), (((viewPos.x / MINI_RATE_X) + 33) + (1920 / MINI_RATE_X)), (((viewPos.y/ MINI_RATE_Y) + 12 + (1080 - 275)) + (1080 / MINI_RATE_Y)), GetColor(255, 0, 255), false);
	}
	if (mapVis)
	{
		DrawGraph(mapPos.x, mapPos.y, mapGra, true);
		DrawBox(mapPos.x + (viewPos.x / MAP_RATE)+25, mapPos.y +(viewPos.y / MAP_RATE)+25, (mapPos.x + (viewPos.x / MAP_RATE) + (1920 / MAP_RATE))-25, (mapPos.y, +(viewPos.y / MAP_RATE) + (1080 / MAP_RATE))+25, GetColor(255, 0, 255), false);
		DrawCircle(miniShipPos.x, miniShipPos.y+20, (25 / MAP_RATE), GetColor(0, 255, 0), true);
		DrawRotaGraph(miniDistPos.x+20, miniDistPos.y, 0.2f, 0, disGra, true);
	}
	if (searFlag)
	{
		DrawGraph(mapPos.x, mapPos.y, mapGra, true);
	}

	return true;
}
