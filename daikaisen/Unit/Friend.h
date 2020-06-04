#pragma once
#include "Obj.h"


class Friend : public Obj
{
public:
	Friend();
	Friend(Vector2Dbl pos, Vector2 size, SHIP ship, IFF iff, int HP, bool visible);		// �ʒn�A���ށA�͎�A�����A�̗́A����
	~Friend();
	void Updata(void)override;					// ���X�V�̊֐�
	SHIP GetShipType(void)override;				// �Ư�(�G)�̏��擾�̊֐�
	IFF GetIFF(void)override;					// �����̎擾�֐�
	int GetAtInter(void)override;				// �U���͈͂̎擾�֐�
	bool GetDeath(void)override;				// ���S�̎擾�֐�
	Vector2Dbl GetDistPos(void)override;		// �ړI�n�̎擾
	Vector2 GetSize(void);						// �G�̻��ނ��󂯎��֐�

private:
	bool Init(void);							// ������

	Vector2 mousePos;							// ϳ��̈ʒu
	
};

