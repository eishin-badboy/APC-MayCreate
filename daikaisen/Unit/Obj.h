#pragma once
#include <array>
#include <memory>
#include <vector>
#include <map>
#include "../Common/Vector2.h"

enum class IFF		// �G��������
{
	FRIEND,			// ����
	ENEMY,			// �G
	MAX
};

enum class SHIP
{
	BB,		// ���
	CV,		// ���
	CA,		// �d��
	CL,		// �y��
	DD,		// �쒀
	SS,		// ����
	MAX
};


class Obj;
using unique_Obj = std::unique_ptr<Obj>;
using shared_Obj = std::shared_ptr<Obj>;

class Obj
{
public:
	Obj();
	virtual ~Obj();
	virtual void Draw(void);
	virtual IFF GetIFF(void) = 0;
	virtual SHIP GetShipType(void) = 0;
	virtual void Updata(void) = 0;

	Vector2Dbl GetShipPos(void);

protected:
	Vector2Dbl m_pos;
	Vector2Dbl m_distiPos;
	Vector2 m_size;
	double m_angle;
	int m_graph;	// ���u�����������
	SHIP m_ship;													// �͎�p�̕ϐ�
	std::array<int, static_cast<int>(SHIP::MAX)> m_shipGra;			// �͎킲�Ƃ̉摜
	std::array<double, static_cast<int>(SHIP::MAX)> m_speedTbl;		// �͎킲�Ƃ̑��x
};

