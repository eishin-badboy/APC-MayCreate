#pragma once
#include <array>
#include "../Common/Vector2.h"

enum class SHIP_TYPE
{
	BB,		// ���
	CV,		// ���
	CA,		// �d��
	CL,		// �y��
	DD,		// �쒀
	SS,		// ����
	MAX
};


class Ship
{
public:
	Ship();
	~Ship();
	void Draw(void);
	void Updata(void);

	Vector2 GetSize(void);

private:
	bool Init(void);
	double m_speed;

};

