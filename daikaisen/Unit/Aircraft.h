#pragma once
#include "Obj.h"


class Aircraft : public Obj
{
public:
	Aircraft();
	Aircraft(Vector2Dbl pos, Vector2 size, IFF iff, int HP, bool visible, bool turn);	// �ʒn�A���ށA�G�������ʁA�̗́A�����A�A���׸�
	~Aircraft();
	void Updata(void)override;					// ���X�V�̊֐�
	IFF GetIFF(void)override;					// �����̎擾�֐�
	bool GetDeath(void)override;				// ���S���̎擾�֐�
	Vector2Dbl GetDistPos(void)override;		// �ړI�n�̎擾�֐�

	SHIP GetShipType(void)override;				// �Ư�(�G)�̏��擾�̊֐��i���g�p�j
	int GetAtInter(void)override;				// �U���͈͂̎擾�֐��i���g�p�j

private:
	bool Init(void);							// �������̊֐�
};

