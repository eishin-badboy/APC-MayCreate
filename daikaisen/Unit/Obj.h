#pragma once
#include <memory>
#include <vector>
#include <map>
#include "../Common/VECTOR2.h"

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

	VECTOR2 GetShipPos(void);

protected:
	VECTOR2 m_pos;
	VECTOR2 m_distiPos;
	VECTOR2 m_size;
	double m_angle;
	int m_graph;
};

