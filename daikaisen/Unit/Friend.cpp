#include <DxLib.h>
#include "Friend.h"
#include "../Common/ImageMng.h"
#include "../Scene/SceneMng.h"


Friend::Friend()
{
	Init();
}

Friend::Friend(Vector2Dbl pos, Vector2 size, SHIP ship, IFF iff , int HP, bool visible)
{
	m_pos = pos;
	m_size = size;
	m_ship = ship;
	m_HP = HP;
	Init();
}

Friend::~Friend()
{
}

void Friend::Draw(void)
{
	//DrawRotaGraph(m_pos.x, m_pos.y, 1.0, m_angle, m_graph, true);
}

SHIP Friend::GetShipType(void)
{
	return m_ship;
}

IFF Friend::GetIFF(void)
{
	return IFF::FRIEND;
}

void Friend::Updata(void)
{
	//// ¶¸Ø¯¸‚µ‚½‚Æ‚«
	//if ((GetMouseInput() & MOUSE_INPUT_LEFT))
	//{
	//	GetMousePoint(&mousePos.x, &mousePos.y);
	//	m_angle = atan2(mousePos.y - m_pos.y, mousePos.x - m_pos.x) + (PI / 2);
	//}

	//// ˆÊ’n‚ªˆá‚¤Žž
	//if (m_pos.x > mousePos.x)
	//{
	//	m_pos.x -= 1 * abs(sin(m_angle));
	//}
	//if (m_pos.x < mousePos.x)
	//{
	//	m_pos.x += 1 * abs(sin(m_angle));
	//}
	//if (m_pos.y > mousePos.y)
	//{
	//	m_pos.y -= 1 * abs(cos(m_angle));
	//}
	//if (m_pos.y < mousePos.y)
	//{
	//	m_pos.y += 1 * abs(cos(m_angle));
	//}

	//float c = sqrt(pow(charaPos.x - enemyPos.x, 2) + pow(charaPos.y - enemyPos.y, 2));
	//float hit = sqrt(pow(bulletPos.x - enemyPos.x, 2) + pow(bulletPos.y - enemyPos.y, 2));
	//if (c <= 270 + 45)
	//{
	//	bulletFlag = true;
	//}

	//// –½’†
	//if (hit <= 45)
	//{
	//	enemyHP -= bulDamage;
	//	bulletFlag = false;
	//}

	//// –C’eˆ—
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

Vector2 Friend::GetSize(void)
{
	return m_size;
}

bool Friend::Init(void)
{
	m_graph = LoadGraph("image/player.png");
	m_angle = 0;
	m_death = false;

	return true;
}
