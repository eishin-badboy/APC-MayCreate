#pragma once
#include <array>
#include <memory>
#include <vector>
#include <map>
#include "../Common/Vector2.h"

#define PI (3.1415926535)

enum class IFF		// �G��������
{
	FRIEND,			// ����
	ENEMY,			// �G
	BULLET,			// �C�e
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
	virtual void Draw(void);					// �`��
	virtual IFF GetIFF(void) = 0;				// �����擾�֐�
	virtual SHIP GetShipType(void) = 0;			// �͎�擾�֐�
	virtual int GetAtInter(void) = 0;			// �U���͈͎擾�֐�
	virtual void Updata(void) = 0;				// ���X�V�֐�
	virtual bool GetDeath(void) = 0;			// ���S�擾�֐�
	virtual Vector2Dbl GetDistPos(void) = 0;	// �ړI�n�擾�֐�
	double GetAngle(void);						// �p�x�̎擾�֐�

	const Vector2Dbl pos(void) const;			// �ʒn�̎擾�֐�
	void SetDistPos(Vector2Dbl distPos);		// �ړI�n�̐ݒ�֐�
	void SetPos(Vector2Dbl pos);				// �ʒn�̐ݒ�֐�
	void SetAngle(double angle);				// �p�x�̐ݒ�֐�
	void SetDamage(int damage);					// ��Ұ�ނ̐ݒ�֐�
	void SetDeath(bool death);					// ���S�̐ݒ�֐�
	void SetVisible(bool visible);				// �����̐ݒ�֐�
	void SetAtInter(void);						// �U���͈͂̐ݒ�֐�
	bool isDeath(void) { return m_death; };		// m_death��Get�֐�

	Vector2Dbl GetShipPos(void);				// �ʒn�̎擾�֐�

	void SetTurn(bool turn);					// �A���׸ނ̐ݒ�֐�
	bool GetTurn(void);							// �A���׸ނ̎擾�֐�

protected:
	Vector2Dbl m_pos;												// �ʒn
	Vector2Dbl m_distPos;											// �ړI�n
	Vector2 m_size;													// ����
	double m_angle;													// �p�x
	int m_graph;													// ���u���摜
	SHIP m_ship;													// �͎�p�̕ϐ�
	IFF m_iff;														// ����
	std::array<int, static_cast<int>(SHIP::MAX)> m_shipGra;			// �͎킲�Ƃ̉摜
	std::array<double, static_cast<int>(SHIP::MAX)> m_speedTbl;		// �͎킲�Ƃ̑��x
	int m_HP;														// �ϋv�l
	bool m_death;													// ��������׸�
	bool m_visible;													// �����׸�
	int m_atInter;													// �U���p�������
	int m_atGra;													// �U���摜
	int m_explo;													// �����摜
	int m_animCnt;													// ��Ұ��݂̺϶��ĕϐ�
	bool m_turnFlag;												// �q��@�p�A���׸�
};

