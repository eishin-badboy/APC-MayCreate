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

SHIP Friend::GetShipType(void)
{
	return m_ship;
}

IFF Friend::GetIFF(void)
{
	return IFF::FRIEND;
}

int Friend::GetAtInter(void)
{
	return m_atInter;
}

void Friend::Updata(void)
{

}

Vector2 Friend::GetSize(void)
{
	return m_size;
}

bool Friend::GetDeath(void)
{
	return m_death;
}

Vector2Dbl Friend::GetDistPos(void)
{
	return m_distPos;
}

bool Friend::Init(void)
{
	m_graph = LoadGraph("image/bb.png");
	m_explo = LoadGraph("image/blast.png");
	m_atInter = 0;
	m_angle = 0;
	m_death = false;
	m_animCnt = 0;
	return true;
}
