#include <stdlib.h>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iterator>

#include "Dxlib.h"
#include "SceneMng.h"
#include "GameScene.h"
#include "ResultScene.h"
#include "../Unit/Friend.h"
#include "../Unit/Enemy.h"
#include "../Unit/Bullet.h"
#include "../Unit/Aircraft.h"
#include "../Common/ImageMng.h"
#include "../Common/GameCtl.h"

#define PI (3.1415926535)
#define MAP_RATE (3.84)		// 3840/1000
#define MINI_RATE_X (11.2280701754)	// 3840/342
#define MINI_RATE_Y (16.4806866952)				// 3840/233

GameScene::GameScene()
{
	distList = { Vector2Dbl(0,0),
				 Vector2Dbl(0,0),
				 Vector2Dbl(0,0),
				 Vector2Dbl(0,0),
	};

	Init();
}


GameScene::~GameScene()
{
	//DeleteGraph(waveBG);
	DeleteSoundMem(gameBGM);
	DeleteSoundMem(shotSe);
}

unique_Base GameScene::UpDate(unique_Base own, const GameCtl& controller)
{
	// 描画処理
	GameDraw();

	GetMousePoint(&mousePos.x, &mousePos.y);
	// @@@
	{
		if (!bgmStart)
		{
			PlaySoundMem(gameBGM, DX_PLAYTYPE_LOOP);
			bgmStart = true;
		}
		if (CheckSoundMem(gameBGM) == 0)
		{
			bgmStart = false;
		}
	}

	// 配列に登録されている全ﾕﾆｯﾄの行動更新
	{
		for (auto obj : e_fleetListF)
		{
			obj->Updata();
		}

		for (auto obj : f_fleetListF)
		{
			obj->Updata();
		}
		//for (auto obj : f_fleetListS)@@@
		//{
		//	obj->Updata();
		//}
		//for (auto obj : f_fleetListT)
		//{
		//	obj->Updata();
		//}

		//for (auto obj : m_airList)
		//{
		//	obj->Updata();
		//}
	}

	//for (int num = 0; num < 4; num++)
	//{
	//	float c = sqrt(pow(mousePos.x - miniPosList[num].x, 2) + pow(mousePos.y - miniPosList[num].y, 2));
	//	if (c < (25 / MAP_RATE))
	//	{
	//		selNum = num;
	//	}
	//}

	// 移動ｺﾏﾝﾄﾞを選択
	if (!uiHide && (mousePos.x > movePos.x && mousePos.x < mousePos.x + 160) && (mousePos.y > movePos.y && mousePos.y < movePos.y + 54))
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT))
		{
			uiHide = true;
			mapVis = true;
		}
	}

	// 偵察ｺﾏﾝﾄﾞを選択@@@
	//if (!uiHide && (mousePos.x > searPos.x && mousePos.x < searPos.x + 160) && (mousePos.y > searPos.y && mousePos.y < searPos.y + 54))
	//{
	//	if ((GetMouseInput() & MOUSE_INPUT_LEFT))
	//	{
	//		uiHide = true;
	//		searFlag = true;
	//	}set
	//}


	// ﾐﾆﾏｯﾌﾟ
	//342:235
	Vector2Dbl testFFPos = f_fleetListF[0]->pos();
	miniFfPos = Vector2Dbl((miniPos.x + 33) + (testFFPos.x / MINI_RATE_X)+(viewPos.x / MINI_RATE_X), (miniPos.y + 12) + (testFFPos.y / MINI_RATE_Y)+(viewPos.y/ MINI_RATE_Y));


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

	for (auto obj : e_fleetListF)
	{
		//if (obj->GetIFF() == IFF::ENEMY)
		//{
			for (auto other : f_fleetListF)
			{
				//if (other->GetIFF() == IFF::FRIEND)
				//{
				other->SetAtInter();
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
					if (other->GetAtInter() % (60 * 5) == 0)
					{
						PlaySoundMem(shotSe, DX_PLAYTYPE_BACK);
						//obj->SetDamage(1);
						obj->SetDeath(true);
					}
					//bulAngle = atan2(enemyPos.y - bulletPos.y, enemyPos.x - bulletPos.x)/* + (PI / 2)*/;
					//m_objList.emplace_back(new Bullet(Vector2Dbl(90,90), { 90, 90 }, bulAngle));
					//bulletFlag = true;
				}
			}
		//}
	}
	cloPos.x++;
	cloPos.y--;
	if (cloPos.y < -730)
	{
		cloPos = { -100, 1800 };
	}

	// ﾕﾆｯﾄの削除
	e_fleetListF.erase(std::remove_if(e_fleetListF.begin(), e_fleetListF.end(),
			[](shared_Obj& obj) {return (*obj).isDeath(); }), e_fleetListF.end());
	//m_objList.erase(std::remove_if(m_objList.begin(), m_objList.end(),
	//	[](shared_Obj& obj) {return (*obj).isDeath(); }), m_objList.end());

	//m_airList.erase(std::remove_if(m_airList.begin(), m_airList.end(),
	//	[](shared_Obj& obj) {return (*obj).isDeath(); }), m_airList.end());

	if (CheckGameEnd())
	{
		return std::make_unique<ResultScene>();
	}
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
		f_fleetListF.emplace_back(new Friend({ 500,210}, { 90, 90 }, SHIP::BB, IFF::FRIEND, 5, true));
	}

	//for (int no = 0; no < 4; no++)@@@
	//{
	//	f_fleetListS.emplace_back(new Friend({ 500,500 }, { 90, 90 }, SHIP::BB, IFF::FRIEND, 5, true));
	//}

	//for (int no = 0; no < 4; no++)@@@
	//{
	//	f_fleetListT.emplace_back(new Friend({ 500,730 }, { 90, 90 }, SHIP::BB, IFF::FRIEND, 5, true));
	//}

	for (int no = 0; no < 4; no++)
	{
		e_fleetListF.emplace_back(new Enemy({ 1300, 90 }, { 90, 90 }, SHIP::BB, IFF::ENEMY, 10, false));
	}


	//m_objList.emplace_back(new Enemy({ 1300, 90 }, { 90, 90 }, SHIP::BB, IFF::ENEMY, 10, false));

	waveBG = LoadGraph("image/sea.png");
	cloudGra = LoadGraph("image/cloud.png");
	cloPos = Vector2Dbl(-100, 1800);

	miniDistPos = { 0,0 };
	miniPosList = { {0,0},
					{100,0},
					{0,100},
					{500,1000} };

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
	selNum = 0;

	return 0;
}

void GameScene::FleetMove(void)
{
	// 味方第一艦隊
	{
		// 位地が違う時
		if (f_fleetListF[0]->pos().x > distList[0].x)
		{
			f_fleetListF[0]->SetPos({ f_fleetListF[0]->pos().x - abs(0.5f * sin(f_fleetListF[0]->GetAngle())), f_fleetListF[0]->pos().y });
		}
		if (f_fleetListF[0]->pos().x < distList[0].x)
		{
			f_fleetListF[0]->SetPos({ f_fleetListF[0]->pos().x + abs(0.5f * sin(f_fleetListF[0]->GetAngle())), f_fleetListF[0]->pos().y });
		}
		if (f_fleetListF[0]->pos().y > distList[0].y)
		{
			f_fleetListF[0]->SetPos({ f_fleetListF[0]->pos().x, f_fleetListF[0]->pos().y - abs(0.5f * cos(f_fleetListF[0]->GetAngle())) });
		}
		if (f_fleetListF[0]->pos().y < distList[0].y)
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

	// 味方第二艦隊@@@
	{
	//	// 位地が違う時
	//	if (f_fleetListS[0]->pos().x > distList[1].x)
	//	{
	//		f_fleetListS[0]->SetPos({ f_fleetListS[0]->pos().x - abs(0.5f * sin(f_fleetListS[0]->GetAngle())), f_fleetListS[0]->pos().y });
	//	}
	//	if (f_fleetListS[0]->pos().x < distList[1].x)
	//	{
	//		f_fleetListS[0]->SetPos({ f_fleetListS[0]->pos().x + abs(0.5f * sin(f_fleetListS[0]->GetAngle())), f_fleetListS[0]->pos().y });
	//	}
	//	if (f_fleetListS[0]->pos().y > distList[1].y)
	//	{
	//		f_fleetListS[0]->SetPos({ f_fleetListS[0]->pos().x, f_fleetListS[0]->pos().y - abs(0.5f * cos(f_fleetListS[0]->GetAngle())) });
	//	}
	//	if (f_fleetListS[0]->pos().y < distList[1].y)
	//	{
	//		f_fleetListS[0]->SetPos({ f_fleetListS[0]->pos().x, f_fleetListS[0]->pos().y + abs(0.5f * cos(f_fleetListS[0]->GetAngle())) });
	//	}

	//	// 随伴艦の挙動
	//	for (int no = 1; no < 4; no++)
	//	{
	//		f_fleetListS[no]->SetAngle(atan2(f_fleetListS[no - 1]->pos().y - f_fleetListS[no]->pos().y, f_fleetListS[no - 1]->pos().x - f_fleetListS[no]->pos().x) + (PI / 2));
	//		// 位地が違う時
	//		if (f_fleetListS[no]->pos().x > f_fleetListS[no - 1]->pos().x + abs((120 * sin(f_fleetListS[no - 1]->GetAngle()))))
	//		{
	//			f_fleetListS[no]->SetPos({ f_fleetListS[no]->pos().x - abs(0.5f * (sin(f_fleetListS[no]->GetAngle()))), f_fleetListS[no]->pos().y });
	//		}
	//		if (f_fleetListS[no]->pos().x < f_fleetListS[no - 1]->pos().x - abs((120 * sin(f_fleetListS[no - 1]->GetAngle()))))
	//		{
	//			f_fleetListS[no]->SetPos({ f_fleetListS[no]->pos().x + abs(0.5f * (sin(f_fleetListS[no]->GetAngle()))), f_fleetListS[no]->pos().y });
	//		}
	//		if (f_fleetListS[no]->pos().y > f_fleetListS[no - 1]->pos().y + abs(120 * cos(f_fleetListS[no - 1]->GetAngle())))
	//		{
	//			f_fleetListS[no]->SetPos({ f_fleetListS[no]->pos().x, f_fleetListS[no]->pos().y - abs(0.5f * (cos(f_fleetListS[no]->GetAngle()))) });
	//		}
	//		if (f_fleetListS[no]->pos().y < f_fleetListS[no - 1]->pos().y - abs(120 * cos(f_fleetListS[no - 1]->GetAngle())))
	//		{
	//			f_fleetListS[no]->SetPos({ f_fleetListS[no]->pos().x, f_fleetListS[no]->pos().y + abs(0.5f * (cos(f_fleetListS[no]->GetAngle()))) });
	//		}
	//	}
	}

	// 味方第三艦隊@@@
	{
		//// 位地が違う時
		//if (f_fleetListT[0]->pos().x > distList[2].x)
		//{
		//	f_fleetListT[0]->SetPos({ f_fleetListT[0]->pos().x - abs(0.5f * sin(f_fleetListT[0]->GetAngle())), f_fleetListT[0]->pos().y });
		//}
		//if (f_fleetListT[0]->pos().x < distList[2].x)
		//{
		//	f_fleetListT[0]->SetPos({ f_fleetListT[0]->pos().x + abs(0.5f * sin(f_fleetListT[0]->GetAngle())), f_fleetListT[0]->pos().y });
		//}
		//if (f_fleetListT[0]->pos().y > distList[2].y)
		//{
		//	f_fleetListT[0]->SetPos({ f_fleetListT[0]->pos().x, f_fleetListT[0]->pos().y - abs(0.5f * cos(f_fleetListT[0]->GetAngle())) });
		//}
		//if (f_fleetListT[0]->pos().y < distList[2].y)
		//{
		//	f_fleetListT[0]->SetPos({ f_fleetListT[0]->pos().x, f_fleetListT[0]->pos().y + abs(0.5f * cos(f_fleetListT[0]->GetAngle())) });
		//}

		//// 随伴艦の挙動
		//for (int no = 1; no < 4; no++)
		//{
		//	f_fleetListT[no]->SetAngle(atan2(f_fleetListT[no - 1]->pos().y - f_fleetListT[no]->pos().y, f_fleetListT[no - 1]->pos().x - f_fleetListT[no]->pos().x) + (PI / 2));
		//	// 位地が違う時
		//	if (f_fleetListT[no]->pos().x > f_fleetListT[no - 1]->pos().x + abs((120 * sin(f_fleetListT[no - 1]->GetAngle()))))
		//	{
		//		f_fleetListT[no]->SetPos({ f_fleetListT[no]->pos().x - abs(0.5f * (sin(f_fleetListT[no]->GetAngle()))), f_fleetListT[no]->pos().y });
		//	}
		//	if (f_fleetListT[no]->pos().x < f_fleetListT[no - 1]->pos().x - abs((120 * sin(f_fleetListT[no - 1]->GetAngle()))))
		//	{
		//		f_fleetListT[no]->SetPos({ f_fleetListT[no]->pos().x + abs(0.5f * (sin(f_fleetListT[no]->GetAngle()))), f_fleetListT[no]->pos().y });
		//	}
		//	if (f_fleetListT[no]->pos().y > f_fleetListT[no - 1]->pos().y + abs(120 * cos(f_fleetListT[no - 1]->GetAngle())))
		//	{
		//		f_fleetListT[no]->SetPos({ f_fleetListT[no]->pos().x, f_fleetListT[no]->pos().y - abs(0.5f * (cos(f_fleetListT[no]->GetAngle()))) });
		//	}
		//	if (f_fleetListT[no]->pos().y < f_fleetListT[no - 1]->pos().y - abs(120 * cos(f_fleetListT[no - 1]->GetAngle())))
		//	{
		//		f_fleetListT[no]->SetPos({ f_fleetListT[no]->pos().x, f_fleetListT[no]->pos().y + abs(0.5f * (cos(f_fleetListT[no]->GetAngle()))) });
		//	}
		//}
	}

	// 敵第一艦隊@@@
	{
		//// 位地が違う時
		//if (e_fleetListF[0]->pos().x > distList[3].x)
		//{
		//	e_fleetListF[0]->SetPos({ e_fleetListF[0]->pos().x - abs(0.5f * sin(e_fleetListF[0]->GetAngle())), e_fleetListF[0]->pos().y });
		//}
		//if (e_fleetListF[0]->pos().x < distList[3].x)
		//{
		//	e_fleetListF[0]->SetPos({ e_fleetListF[0]->pos().x + abs(0.5f * sin(e_fleetListF[0]->GetAngle())), e_fleetListF[0]->pos().y });
		//}
		//if (e_fleetListF[0]->pos().y > distList[3].y)
		//{
		//	e_fleetListF[0]->SetPos({ e_fleetListF[0]->pos().x, e_fleetListF[0]->pos().y - abs(0.5f * cos(e_fleetListF[0]->GetAngle())) });
		//}
		//if (e_fleetListF[0]->pos().y < distList[3].y)
		//{
		//	e_fleetListF[0]->SetPos({ e_fleetListF[0]->pos().x, e_fleetListF[0]->pos().y + abs(0.5f * cos(e_fleetListF[0]->GetAngle())) });
		//}

		//// 随伴艦の挙動
		//for (int no = 1; no < 4; no++)
		//{
		//	e_fleetListF[no]->SetAngle(atan2(e_fleetListF[no - 1]->pos().y - e_fleetListF[no]->pos().y, e_fleetListF[no - 1]->pos().x - e_fleetListF[no]->pos().x) + (PI / 2));
		//	// 位地が違う時
		//	if (e_fleetListF[no]->pos().x > e_fleetListF[no - 1]->pos().x + abs((120 * sin(e_fleetListF[no - 1]->GetAngle()))))
		//	{
		//		e_fleetListF[no]->SetPos({ e_fleetListF[no]->pos().x - abs(0.5f * (sin(e_fleetListF[no]->GetAngle()))), e_fleetListF[no]->pos().y });
		//	}
		//	if (e_fleetListF[no]->pos().x < e_fleetListF[no - 1]->pos().x - abs((120 * sin(e_fleetListF[no - 1]->GetAngle()))))
		//	{
		//		e_fleetListF[no]->SetPos({ e_fleetListF[no]->pos().x + abs(0.5f * (sin(e_fleetListF[no]->GetAngle()))), e_fleetListF[no]->pos().y });
		//	}
		//	if (e_fleetListF[no]->pos().y > e_fleetListF[no - 1]->pos().y + abs(120 * cos(e_fleetListF[no - 1]->GetAngle())))
		//	{
		//		e_fleetListF[no]->SetPos({ e_fleetListF[no]->pos().x, e_fleetListF[no]->pos().y - abs(0.5f * (cos(e_fleetListF[no]->GetAngle()))) });
		//	}
		//	if (e_fleetListF[no]->pos().y < e_fleetListF[no - 1]->pos().y - abs(120 * cos(e_fleetListF[no - 1]->GetAngle())))
		//	{
		//		e_fleetListF[no]->SetPos({ e_fleetListF[no]->pos().x, e_fleetListF[no]->pos().y + abs(0.5f * (cos(e_fleetListF[no]->GetAngle()))) });
		//	}
		//}
	}

}

void GameScene::CheckDistina(void)
{
	Vector2Dbl testPos = { 0,0 };
	switch (selNum)
	{
	case 0:
		testPos = f_fleetListF[0]->pos();
		break;
	//case 1:@@@
	//	testPos = f_fleetListS[0]->pos();
	//	break;
	//case 2:
	//	testPos = f_fleetListT[0]->pos();
	//	break;
	}
	miniPosList[selNum] = Vector2Dbl(mapPos.x + (testPos.x / MAP_RATE) + (viewPos.x / MAP_RATE), mapPos.y + (testPos.y / MAP_RATE) +(viewPos.y / MAP_RATE));
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
			distList[selNum] = Vector2Dbl(((mousePos.x - mapPos.x) * MAP_RATE)-viewPos.x, ((mousePos.y - mapPos.y) * MAP_RATE)-viewPos.y);					// ﾏｯﾌﾟ内で選択した地点を復元
			switch (selNum)
			{
			case 0:
				f_fleetListF[0]->SetAngle(atan2(mousePos.y - miniPosList[selNum].y, mousePos.x - miniPosList[selNum].x) + (PI / 2));
				break;
			//case 1:@@@
			//	f_fleetListS[0]->SetAngle(atan2(mousePos.y - miniPosList[selNum].y, mousePos.x - miniPosList[selNum].x) + (PI / 2));
			//	break;
			//case 2:
			//	f_fleetListT[0]->SetAngle(atan2(mousePos.y - miniPosList[selNum].y, mousePos.x - miniPosList[selNum].x) + (PI / 2));
			//	break;
			default:
				break;
			}
			mapVis = false;
			uiHide = false;
			PlaySoundMem(rogerSe, DX_PLAYTYPE_BACK);
		}
	}
}

void GameScene::Searching(void)
{
	Vector2Dbl testPos = f_fleetListF[0]->pos();
	miniShipPos = Vector2Dbl(mapPos.x + (testPos.x / MAP_RATE) + (viewPos.x / MAP_RATE), mapPos.y + (testPos.y / MAP_RATE) + (viewPos.y / MAP_RATE));
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
			//m_airList.emplace_back(new Aircraft({ testPos.x,testPos.y + 100 }, { 30, 30 }, IFF::FRIEND, 5, true, false));
			//m_airList[0]->SetDistPos(Vector2Dbl(((mousePos.x - mapPos.x) * MAP_RATE) - viewPos.x, ((mousePos.y - mapPos.y) * MAP_RATE) - viewPos.y));
			//m_airList[0]->SetAngle(atan2(mousePos.y - miniShipPos.y, mousePos.x - miniShipPos.x) + (PI / 2));
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
		for (int num = 0; num < 4; num++)
		{
			distList[num].x -= viewSpeed;
		}

		for (int no = 0; no < 4; no++)
		{
			f_fleetListF[no]->SetPos({ f_fleetListF[no]->pos().x - viewSpeed, f_fleetListF[no]->pos().y });
		}
		//for (int no = 0; no < 4; no++)@@@
		//{
		//	f_fleetListS[no]->SetPos({ f_fleetListS[no]->pos().x - viewSpeed, f_fleetListS[no]->pos().y });
		//}
		//for (int no = 0; no < 4; no++)
		//{
		//	f_fleetListT[no]->SetPos({ f_fleetListT[no]->pos().x - viewSpeed, f_fleetListT[no]->pos().y });
		//}
		//for (int no = 0; no < 4; no++)
		//{
		//	e_fleetListF[no]->SetPos({ e_fleetListF[no]->pos().x - viewSpeed, e_fleetListF[no]->pos().y });
		//}

	}
	if (viewPos.x >= 0 && mousePos.x < 10)
	{
		viewPos.x -= viewSpeed;
		for (int num = 0; num < 4; num++)
		{
			distList[num].x += viewSpeed;
		}

		for (int no = 0; no < 4; no++)
		{
			f_fleetListF[no]->SetPos({ f_fleetListF[no]->pos().x + viewSpeed, f_fleetListF[no]->pos().y });
		}
		//for (int no = 0; no < 4; no++)@@@
		//{
		//	f_fleetListS[no]->SetPos({ f_fleetListS[no]->pos().x + viewSpeed, f_fleetListS[no]->pos().y });
		//}
		//for (int no = 0; no < 4; no++)
		//{
		//	f_fleetListT[no]->SetPos({ f_fleetListT[no]->pos().x + viewSpeed, f_fleetListT[no]->pos().y });
		//}
		//for (int no = 0; no < 4; no++)
		//{
		//	e_fleetListF[no]->SetPos({ e_fleetListF[no]->pos().x + viewSpeed, e_fleetListF[no]->pos().y });
		//}

	}
	if (viewPos.y <= 3840 - 1080 && mousePos.y > 1080 - 10)
	{
		viewPos.y += viewSpeed;
		for (int num = 0; num < 4; num++)
		{
			distList[num].y -= viewSpeed;
		}

		for (int no = 0; no < 4; no++)
		{
			f_fleetListF[no]->SetPos({ f_fleetListF[no]->pos().x, f_fleetListF[no]->pos().y - viewSpeed });
		}
		//for (int no = 0; no < 4; no++)@@@
		//{
		//	f_fleetListS[no]->SetPos({ f_fleetListS[no]->pos().x, f_fleetListS[no]->pos().y - viewSpeed });
		//}
		//for (int no = 0; no < 4; no++)
		//{
		//	f_fleetListT[no]->SetPos({ f_fleetListT[no]->pos().x, f_fleetListT[no]->pos().y - viewSpeed });
		//}
		//for (int no = 0; no < 4; no++)
		//{
		//	e_fleetListF[no]->SetPos({ e_fleetListF[no]->pos().x, e_fleetListF[no]->pos().y - viewSpeed });
		//}

	}
	if (viewPos.y >= 0 && mousePos.y < 10)
	{
		viewPos.y -= viewSpeed;
		for (int num = 0; num < 4; num++)
		{
			distList[num].y += viewSpeed;
		}

		for (int no = 0; no < 4; no++)
		{
			f_fleetListF[no]->SetPos({ f_fleetListF[no]->pos().x, f_fleetListF[no]->pos().y + viewSpeed });
		}
		//for (int no = 0; no < 4; no++)@@@
		//{
		//	f_fleetListS[no]->SetPos({ f_fleetListS[no]->pos().x, f_fleetListS[no]->pos().y + viewSpeed });
		//}
		//for (int no = 0; no < 4; no++)
		//{
		//	f_fleetListT[no]->SetPos({ f_fleetListT[no]->pos().x, f_fleetListT[no]->pos().y + viewSpeed });
		//}
		//for (int no = 0; no < 4; no++)
		//{
		//	e_fleetListF[no]->SetPos({ e_fleetListF[no]->pos().x, e_fleetListF[no]->pos().y + viewSpeed });
		//}

	}
}

bool GameScene::CheckGameEnd(void)
{
	for (auto &obj: e_fleetListF)
	{
		if (obj != nullptr)
		{
			return false;
		}
	}
	return true;
}

bool GameScene::GameDraw(void)
{
	DrawRotaGraph(960, 540, 2.5f, 0, waveBG, true);

	for (auto& obj : e_fleetListF)
	{
		obj->Obj::Draw();
	}

	for (auto& obj : f_fleetListF)
	{
		obj->Obj::Draw();
	}
	//for (auto& obj : f_fleetListS)@@@
	//{
	//	obj->Obj::Draw();
	//}
	//for (auto& obj : f_fleetListT)
	//{
	//	obj->Obj::Draw();
	//}


	//for (auto& obj : m_airList)@@@
	//{
	//	obj->Obj::Draw();
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
		//for (int num = 0; num < 4; num++)
		//{
			DrawCircle(miniPosList[0].x, miniPosList[0].y + 20, (25 / MAP_RATE), GetColor(0, 255, 0), true);
		//}
		DrawRotaGraph(miniDistPos.x+20, miniDistPos.y, 0.2f, 0, disGra, true);
	}
	if (searFlag)
	{
		DrawGraph(mapPos.x, mapPos.y, mapGra, true);
		//for (int num = 0; num < 4; num++)
		//{
			DrawCircle(miniPosList[0].x, miniPosList[0].y + 20, (25 / MAP_RATE), GetColor(0, 255, 0), true);
		//}
	}

	return true;
}
