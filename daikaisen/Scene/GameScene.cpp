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

	// Ç†Ç∆Ç≈âèú@@@
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

	// îzóÒÇ…ìoò^Ç≥ÇÍÇƒÇ¢ÇÈëS’∆ØƒÇÃçsìÆçXêV
	for (auto obj : m_objList)
	{
		obj->Updata();
	}

	for (auto obj : f_fleetListF)
	{
		obj->Updata();
	}

	FleetMove();		// äÕë‡à⁄ìÆ

	// à⁄ìÆ∫œ›ƒﬁÇëIë
	if (!uiHide && (mousePos.x > movePos.x && mousePos.x < mousePos.x + 160) && (mousePos.y > movePos.y && mousePos.y < movePos.y + 54))
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT))
		{
			uiHide = true;
			mapVis = true;
		}
	}

	//342:235
	Vector2Dbl testPos = f_fleetListF[0]->pos();
	miniFfPos = Vector2Dbl((miniPos.x + 33) + (testPos.x / 11.22), (miniPos.y + 33) + (testPos.y / 16.34));
	// –∆œØÃﬂ


	// à⁄ìÆínì_åàÇﬂ
	if (mapVis)
	{
		CheckDistina();
	}

	for (auto obj : m_objList)
	{
		if (obj->GetIFF() == IFF::ENEMY)
		{
			for (auto other : f_fleetListF)
			{
				//if (other->GetIFF() == IFF::FRIEND)
				//{

					float c = sqrt(pow(other->pos().x - obj->pos().x, 2) + pow(other->pos().y - obj->pos().y, 2));
					// çıìGîÕàÕì‡
					if (c > 900 + 45)
					{
						obj->SetVisible(false);
					}
					if (c <= 500 + 45)
					{
						obj->SetVisible(true);
					}
					// çUåÇîÕàÕì‡
					if (c <= 400 + 45)
					{
						obj->SetDamage(1);
						//bulAngle = atan2(enemyPos.y - bulletPos.y, enemyPos.x - bulletPos.x)/* + (PI / 2)*/;
						//m_objList.emplace_back(new Bullet(Vector2Dbl(90,90), { 90, 90 }, bulAngle));
						//bulletFlag = true;
					}
					{
						//for (auto bul : m_objList)
						//{
						//	if (bul->GetIFF() == IFF::BULLET)
						//	{
						//		float hit = sqrt(pow(bul->pos().x - obj->pos().x, 2) + pow(bul->pos().y - obj->pos().y, 2));
						//		//// ñΩíÜ
						//		if (hit <= 45)
						//		{
						//			obj->SetDamage(2);
						//			//	bul->SetDeath(true);
						//			//	bulletFlag = false;
						//		}
						//	}
						//}
					}
				//}
				{
					// ñCíeèàóù
//if (bulletFlag)
//{
//	bulAngle = atan2(enemyPos.y - bulletPos.y, enemyPos.x - bulletPos.x)/* + (PI / 2)*/;

//	bulletPos.x += cos(bulAngle) * 6;
//	bulletPos.y += sin(bulAngle) * 6;
//	//if (bulletPos.x > enemyPos.x)
//	//{
//	//	bulletPos.x -= 15 * abs(cos(bulAngle));
//	//}
//	//if (bulletPos.x < enemyPos.x)
//	//{
//	//	bulletPos.x += 15 * abs(cos(bulAngle));
//	//}
//	//if (bulletPos.y > enemyPos.y)
//	//{
//	//	bulletPos.y -= 15 * abs(sin(bulAngle));
//	//}
//	//if (bulletPos.y < enemyPos.y)
//	//{
//	//	bulletPos.y += 15 * abs(sin(bulAngle));
//	//}
//}
//else
//{
//	bulletPos = charaPos;
//}

//if (bulletPos.x > 1280 || bulletPos.x < 0 || bulletPos.y > 800 || bulletPos.y < 0)
//{
//	bulletFlag = false;
//}
				}
			}
		}
	}
	{
		//if (c <= 270 + 45)
		//{
		//	bulletFlag = true;
		//}

		//// ñΩíÜ
		//if (hit <= 45)
		//{
		//	enemyHP -= bulDamage;
		//	bulletFlag = false;
		//}

		//// ñCíeèàóù
		//if (bulletFlag)
		//{
		//	bulAngle = atan2(enemyPos.y - bulletPos.y, enemyPos.x - bulletPos.x)/* + (PI / 2)*/;

		//	bulletPos.x += cos(bulAngle) * 6;
		//	bulletPos.y += sin(bulAngle) * 6;
		//	//if (bulletPos.x > enemyPos.x)
		//	//{
		//	//	bulletPos.x -= 15 * abs(cos(bulAngle));
		//	//}
		//	//if (bulletPos.x < enemyPos.x)
		//	//{
		//	//	bulletPos.x += 15 * abs(cos(bulAngle));
		//	//}
		//	//if (bulletPos.y > enemyPos.y)
		//	//{
		//	//	bulletPos.y -= 15 * abs(sin(bulAngle));
		//	//}
		//	//if (bulletPos.y < enemyPos.y)
		//	//{
		//	//	bulletPos.y += 15 * abs(sin(bulAngle));
		//	//}
		//}
		//else
		//{
		//	bulletPos = charaPos;
		//}

		//if (bulletPos.x > 1280 || bulletPos.x < 0 || bulletPos.y > 800 || bulletPos.y < 0)
		//{
		//	bulletFlag = false;
		//}
	}

	cloPos.x++;
	cloPos.y--;
	if (cloPos.y < -730)
	{
		cloPos = { -100, 1800 };
	}

	m_objList.erase(std::remove_if(m_objList.begin(), m_objList.end(),
		[](shared_Obj& obj) {return (*obj).isDeath(); }), m_objList.end());

	// ï`âÊèàóù
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
	//m_objList.emplace_back(new Friend({ 500,210 }, { 90, 90 }, SHIP::BB, IFF::FRIEND, 5, true));
	//m_objList.emplace_back(new Friend({ 700,210 }, { 90, 90 }, SHIP::BB, IFF::FRIEND, 5, true));

	for (int no = 0; no < 4; no++)
	{
		f_fleetListF.emplace_back(new Friend({ 500,210}, { 90, 90 }, SHIP::BB, IFF::FRIEND, 5, true));;
	}

	m_objList.emplace_back(new Enemy({ 1300, 90 }, { 90, 90 }, SHIP::BB, IFF::ENEMY, 5, false));

	waveBG = LoadGraph("image/sea.png");
	cloudGra = LoadGraph("image/cloud.png");
	cloPos = Vector2Dbl(-100, 1800);
	//PlayMovieToGraph(waveBG);

	miniDistPos = { 0,0 };

	gameBGM = LoadSoundMem("bgm/game.mp3");
	bgmStart = false;
	// UIä÷òA
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
		mapPos = Vector2Dbl((920 / 2), 40);
		disGra = LoadGraph("image/flag.png");
	}

	return 0;
}

void GameScene::FleetMove(void)
{
	// à ínÇ™à·Ç§éû
	if (f_fleetListF[0]->pos().x > distiPos.x)
	{
		f_fleetListF[0]->SetPos({ f_fleetListF[0]->pos().x - 1 * abs(sin(f_fleetListF[0]->GetAngle())), f_fleetListF[0]->pos().y });
	}
	if (f_fleetListF[0]->pos().x < distiPos.x)
	{
		f_fleetListF[0]->SetPos({ f_fleetListF[0]->pos().x + 1 * abs(sin(f_fleetListF[0]->GetAngle())), f_fleetListF[0]->pos().y });
	}
	if (f_fleetListF[0]->pos().y > distiPos.y)
	{
		f_fleetListF[0]->SetPos({ f_fleetListF[0]->pos().x, f_fleetListF[0]->pos().y - 1 * abs(cos(f_fleetListF[0]->GetAngle())) });
	}
	if (f_fleetListF[0]->pos().y < distiPos.y)
	{
		f_fleetListF[0]->SetPos({ f_fleetListF[0]->pos().x, f_fleetListF[0]->pos().y + 1 * abs(cos(f_fleetListF[0]->GetAngle())) });
	}

	// êèî∫äÕÇÃãììÆ
	for (int no = 1; no < 4; no++)
	{
		f_fleetListF[no]->SetAngle(atan2(f_fleetListF[no - 1]->pos().y - f_fleetListF[no]->pos().y, f_fleetListF[no - 1]->pos().x - f_fleetListF[no]->pos().x) + (PI / 2));
		// à ínÇ™à·Ç§éû
		if (f_fleetListF[no]->pos().x > f_fleetListF[0]->pos().x + (120 * no) * abs(sin(f_fleetListF[0]->GetAngle())))
		{
			f_fleetListF[no]->SetPos({ f_fleetListF[no]->pos().x - 1 * abs(sin(f_fleetListF[no]->GetAngle())), f_fleetListF[no]->pos().y });
		}
		if (f_fleetListF[no]->pos().x < f_fleetListF[0]->pos().x - (120 * no) * abs(sin(f_fleetListF[0]->GetAngle())))
		{
			f_fleetListF[no]->SetPos({ f_fleetListF[no]->pos().x + 1 * abs(sin(f_fleetListF[no]->GetAngle())), f_fleetListF[no]->pos().y });
		}
		if (f_fleetListF[no]->pos().y > f_fleetListF[0]->pos().y + (120 * no) * abs(cos(f_fleetListF[0]->GetAngle())))
		{
			f_fleetListF[no]->SetPos({ f_fleetListF[no]->pos().x, f_fleetListF[no]->pos().y - 1 * abs(cos(f_fleetListF[no]->GetAngle())) });
		}
		if (f_fleetListF[no]->pos().y < f_fleetListF[0]->pos().y - (120 * no) * abs(cos(f_fleetListF[0]->GetAngle())))
		{
			f_fleetListF[no]->SetPos({ f_fleetListF[no]->pos().x, f_fleetListF[no]->pos().y + 1 * abs(cos(f_fleetListF[no]->GetAngle())) });
		}
	}

}

void GameScene::CheckDistina(void)
{
	Vector2Dbl testPos = f_fleetListF[0]->pos();
	miniShipPos = Vector2Dbl(mapPos.x + (testPos.x / 3.84), mapPos.y + (testPos.y / 3.84));
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT))
	{
		mapVis = false;
		uiHide = false;
	}
	// ç∂∏ÿØ∏ÇµÇΩÇ∆Ç´
	if ((mousePos.x > mapPos.x && mousePos.x < mapPos.x + 1000) && (mousePos.y > mapPos.y && mousePos.y < mapPos.y + 1000))
	{
		if ((GetMouseInput() & MOUSE_INPUT_LEFT))
		{
			miniDistPos = mousePos;
			distiPos = Vector2Dbl((mousePos.x - mapPos.x) * 3.84, (mousePos.y - mapPos.y) * 3.84);					// œØÃﬂì‡Ç≈ëIëÇµÇΩínì_Çïúå≥
			f_fleetListF[0]->SetAngle(atan2(mousePos.y - miniShipPos.y, mousePos.x - miniShipPos.x) + (PI / 2));
			mapVis = false;
			uiHide = false;
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

	//if(GetMovieStateToGraph(waveBG) == 1)
	//{
	//	// ÉÄÅ[ÉrÅ[âfëúÇâÊñ Ç¢Ç¡ÇœÇ¢Ç…ï`âÊÇµÇ‹Ç∑
	//	DrawExtendGraph(0, 0, 1920, 1080, waveBG, FALSE);

	//	// ÉEÉGÉCÉgÇÇ©ÇØÇ‹Ç∑ÅAÇ†Ç‹ÇËë¨Ç≠ï`âÊÇ∑ÇÈÇ∆âÊñ Ç™ÇøÇÁÇ¬Ç≠Ç©ÇÁÇ≈Ç∑
	//	WaitTimer(17);
	//}

	for (auto& obj : m_objList)
	{
		obj->Obj::Draw();
	}

	for (auto& obj : f_fleetListF)
	{
		obj->Obj::Draw();
	}


	//DrawRotaGraph(charaPos.x, charaPos.y, 0.5f, charaAngle, charaGra, true);
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
	}
	if (mapVis)
	{
		DrawGraph(mapPos.x, mapPos.y, mapGra, true);
		DrawCircle(miniShipPos.x, miniShipPos.y, (25 / 3.84), GetColor(0, 255, 0), true);
		DrawRotaGraph(miniDistPos.x+20, miniDistPos.y-20, 0.2f, 0, disGra, true);
	}

	return true;
}
