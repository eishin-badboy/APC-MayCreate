#pragma once
#include "Obj.h"


class Bullet : public Obj
{
public:
	Bullet();
	Bullet(Vector2Dbl pos, Vector2 size, double angle);		// �ʒn�A���ށA�p�x
	~Bullet();
	void Updata(void)override;				// ���̍X�V�֐�
	IFF GetIFF(void)override;				// �����̎擾�֐�
	SHIP GetShipType(void)override;			// �ƯĎ�ނ̎擾�֐�
	void Draw(void);						// �`��p�̊֐�

	Vector2 GetSize(void);					// ���ގ擾�֐�

private:
	bool Init(void);						// �������p
};

