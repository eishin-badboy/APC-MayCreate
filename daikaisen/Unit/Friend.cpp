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

}

Vector2 Friend::GetSize(void)
{
	return m_size;
}

bool Friend::Init(void)
{
	m_graph = LoadGraph("image/bb.png");
	m_angle = 0;
	m_death = false;

	return true;
}
