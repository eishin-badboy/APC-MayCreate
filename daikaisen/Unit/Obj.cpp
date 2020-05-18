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
	DrawRotaGraph(m_pos.x, m_pos.y, 0.5f, m_angle, m_graph, true);
	DrawCircle(m_pos.x, m_pos.y, 270, GetColor(0, 255, 255), false);
}

Vector2Dbl Obj::GetShipPos(void)
{
	return m_pos;
}
