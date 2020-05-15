#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(Vector2Dbl pos, Vector2Dbl size, SHIP ship, IFF iff)
{
}

Enemy::~Enemy()
{
}

SHIP Enemy::GetShipType(void)
{
	return SHIP();
}

void Enemy::Updata(void)
{
}

Vector2 Enemy::GetSize(void)
{
	return Vector2();
}

bool Enemy::Init(void)
{
	return false;
}
