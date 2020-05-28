#include <DxLib.h>
#include "Obj.h"

Obj::Obj()
{
}

Obj::~Obj()
{
}

void Obj::Draw(void)
{
	if (m_visible)
	{
		DrawRotaGraph(m_pos.x, m_pos.y, 1.0f, m_angle, m_graph, true);
	}
	DrawCircle(m_pos.x, m_pos.y, 400, GetColor(0, 255, 255), false);
	DrawCircle(m_pos.x, m_pos.y, 500, GetColor(255, 0, 0), false);

}

const Vector2Dbl Obj::pos(void) const
{
	return m_pos;
}

double Obj::GetAngle(void)
{
	return m_angle;
}

void Obj::SetPos(Vector2Dbl pos)
{
	m_pos = pos;
}

void Obj::SetAngle(double angle)
{
	m_angle = angle;
}

void Obj::SetDamage(int damage)
{
	m_HP -= damage;
}

void Obj::SetDeath(bool death)
{
	m_death = death;
}

void Obj::SetVisible(bool visible)
{
	m_visible = visible;
}

void Obj::SetAtInter(void)
{
	m_atInter++;
}

Vector2Dbl Obj::GetShipPos(void)
{
	return m_pos;
}
