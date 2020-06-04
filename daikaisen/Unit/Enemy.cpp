#include <DxLib.h>
#include "Enemy.h"
#include "../Common/ImageMng.h"
#include "../Scene/SceneMng.h"

Enemy::Enemy()
{
}

Enemy::Enemy(Vector2Dbl pos, Vector2 size, SHIP ship, IFF iff, int HP, bool visible)
{
	m_pos = pos;
	m_size = size;
	m_ship = ship;
	m_HP = HP;
	m_visible = visible;
	Init();
}

Enemy::~Enemy()
{
}

SHIP Enemy::GetShipType(void)
{
	return m_ship;
}

IFF Enemy::GetIFF(void)
{
	return IFF::ENEMY;
}

int Enemy::GetAtInter(void)
{
	return m_atInter;
}

void Enemy::Updata(void)
{
	//if (m_HP <= 0)
	//{
	//	SetDeath(true);
	//}
}

bool Enemy::GetDeath(void)
{
	return m_death;
}

Vector2Dbl Enemy::GetDistPos(void)
{
	return m_distPos;
}

Vector2 Enemy::GetSize(void)
{
	return m_size;
}

bool Enemy::Init(void)
{
	m_graph = LoadGraph("image/air.png");
	m_explo = LoadGraph("image/blast.png");
	m_atInter = 0;

	m_angle = 0;
	m_death = false;
	m_animCnt = 0;

	return false;
}
