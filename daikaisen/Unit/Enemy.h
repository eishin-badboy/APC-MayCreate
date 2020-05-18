#pragma once
#include <array>
#include "Obj.h"


class Enemy : public Obj
{
public:
	Enemy();
	Enemy(Vector2Dbl pos, Vector2Dbl size, SHIP ship, IFF iff);
	~Enemy();
	SHIP GetShipType(void)override;		// �Ư�(�G)�̏��擾�̊֐�
	IFF GetIFF(void)override;
	void Updata(void)override;			// ���X�V�̊֐�

	Vector2 GetSize(void);				// �G�̻��ނ��󂯎��֐�

private:
	bool Init(void);

};

