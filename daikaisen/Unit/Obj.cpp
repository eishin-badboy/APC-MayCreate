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
	DrawRotaGraph(m_pos.x, m_pos.y, 1.0f, m_angle, m_graph, true);
}

Vector2Dbl Obj::GetShipPos(void)
{
	return m_pos;
}
