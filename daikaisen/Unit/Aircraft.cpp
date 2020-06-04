#include <DxLib.h>
#include "Aircraft.h"
#include "../Common/ImageMng.h"
#include "../Scene/SceneMng.h"


Aircraft::Aircraft()
{
}

Aircraft::Aircraft(Vector2Dbl pos, Vector2 size, IFF iff, int HP, bool visible, bool turn)
{
	m_pos = pos;
	m_size = size;
	m_iff = iff;
	m_HP = HP;
	m_visible = visible;
	m_turnFlag = turn;
	Init();
}

Aircraft::~Aircraft()
{
}

IFF Aircraft::GetIFF(void)
{
	return m_iff;
}

void Aircraft::Updata(void)
{
	// ˆÊ’n‚ªˆá‚¤Žž
	if (GetTurn() == false && m_animCnt < (60 * 4))
	{
		if (m_pos.x > GetDistPos().x)
		{
			SetPos({ m_pos.x - abs(2 * sin(GetAngle())), m_pos.y });
		}
		if (m_pos.x < GetDistPos().x)
		{
			SetPos({ m_pos.x + abs(2 * sin(GetAngle())), m_pos.y });
		}
		if (m_pos.y > GetDistPos().y)
		{
			SetPos({ m_pos.x, m_pos.y - abs(2 * cos(GetAngle())) });
		}
		if (m_pos.y < GetDistPos().y)
		{
			SetPos({ m_pos.x, m_pos.y + abs(2 * cos(GetAngle())) });
		}
		if (m_pos == GetDistPos())
		{
			m_turnFlag = true; 
		}
		m_animCnt++;
	}
	if (m_animCnt >= (60 * 4))
	{
		SetTurn(true);
		SetAngle(-GetAngle());
	}
	if (m_animCnt >= 0 && GetTurn() == true)
	{
		if (m_pos.x >= GetDistPos().x)
		{
			SetPos({ m_pos.x - abs(2 * sin(GetAngle())), m_pos.y });
		}
		if (m_pos.x < GetDistPos().x)
		{
			SetPos({ m_pos.x + abs(2 * sin(GetAngle())), m_pos.y });
		}
		if (m_pos.y >= GetDistPos().y)
		{
			SetPos({ m_pos.x, m_pos.y - abs(2 * cos(GetAngle())) });
		}
		if (m_pos.y < GetDistPos().y)
		{
			SetPos({ m_pos.x, m_pos.y + abs(2 * cos(GetAngle())) });
		}
		m_animCnt--;
	}
}

bool Aircraft::GetDeath(void)
{
	return m_death;
}

Vector2Dbl Aircraft::GetDistPos(void)
{
	return m_distPos;
}

SHIP Aircraft::GetShipType(void)
{
	return SHIP();
}

int Aircraft::GetAtInter(void)
{
	return 0;
}

bool Aircraft::Init(void)
{
	m_graph = LoadGraph("image/enemy.png");
	m_death = false;
	m_animCnt = 0;
	return true;
}
