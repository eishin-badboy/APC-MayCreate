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

void Enemy::Updata(void)
{
	if (m_HP <= 0)
	{
		m_death = true;
	}
}

Vector2 Enemy::GetSize(void)
{
	return m_size;
}

bool Enemy::Init(void)
{
	m_graph = LoadGraph("image/enemy.png");
	m_angle = 0;
	m_death = false;

	return false;
}
