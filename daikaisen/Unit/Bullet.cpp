#include <DxLib.h>
#include "Bullet.h"
#include "Friend.h"
#include "Enemy.h"
#include "../Scene/SceneMng.h"
#include "../Common/ImageMng.h"


Bullet::Bullet()
{
}

Bullet::Bullet(Vector2Dbl pos, Vector2 size, double angle)
{
	m_pos = pos;
	m_size = size;
	m_angle = angle;
	Init();
}

Bullet::~Bullet()
{
}

void Bullet::Updata(void)
{
	
}

IFF Bullet::GetIFF(void)
{
	return IFF::BULLET;
}

SHIP Bullet::GetShipType(void)
{
	return m_ship;
}

void Bullet::Draw(void)
{

}

Vector2 Bullet::GetSize(void)
{
	return m_size;
}

bool Bullet::Init(void)
{
	m_death = false;

	return false;
}
