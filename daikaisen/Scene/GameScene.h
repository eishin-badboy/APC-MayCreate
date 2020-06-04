#pragma once
#include <list>
#include <array>
#include <vector>
#include <memory>
#include "BaseScene.h"
#include "../Unit/Obj.h"
#include "../Common/Vector2.h"


class GameScene : public BaseScene
{
public:
	GameScene();
	~GameScene();
	unique_Base UpDate(unique_Base own, const GameCtl& controller);		// ���X�V


private:
	Vector2 sSize;				// ��ʻ���

	int Init(void);				// ������
	void FleetMove(void);		// �͑��ړ�����
	void CheckDistina(void);	// �ړI�n
	void Searching(void);		// ��@�@���i
	void ViewMove(void);		// ���_�ړ�
	bool CheckGameEnd(void);	// ���s���`�F�b�N		
	bool GameDraw(void);		// �`�揈��

	std::vector<shared_Obj> m_objList;		// Obj�p���׽�̉ϔz��(�ؼ���)

	std::vector<shared_Obj> f_fleetListF;	// �������͑��̉ϔz��
	std::vector<shared_Obj> f_fleetListS;	// �������͑��̉ϔz��
	std::vector<shared_Obj> f_fleetListT;	// ������O�͑��̉ϔz��

	std::vector<shared_Obj> e_fleetListF;	// �G���͑��̉ϔz��
	std::vector<shared_Obj> e_fleetListS;	// �G���͑��̉ϔz��
	std::vector<shared_Obj> e_fleetListT;	// �G��O�͑��̉ϔz��

	std::vector<shared_Obj> m_airList;	// �q��@�̉ϔz��



	int charaGra;							// ýėp���̨��
	Vector2Dbl charaPos;					// ýėp�ʒn
	Vector2 mousePos;						// ϳ��̈ʒu
	Vector2Dbl distiPos;					// �ړI�n
	Vector2 miniDistPos;					// ϯ�ߏ�̖ړI�n
	float charaAngle;						// ýėp�̊p�x
	double rotaAngle;						// ��]�p�x

	Vector2Dbl enemyPos;					// �G�̈ʒu
	Vector2Dbl bulletPos;					// �e�̈ʒu
	bool bulletFlag;						// �e�̏o���׸�
	double bulAngle;						// �e�̔��ˊp�x
	int enemyHP;							// �G�̗̑�
	int bulDamage;							// �e�ɂ����Ұ��


	// �w�i�֘A
	int waveBG;								// �w�i�̔g
	int cloudGra;							// �_�̉摜
	Vector2Dbl cloPos;						// �_�̈ʒu

	// UI�֘A
	int gameBGM;							// �ްђ���BGM
	int shotSe;								// �C���̌��ʉ�
	bool bgmStart;							// BGM�̍Đ������׸�
	int miniMap;							// ��ϯ�߂̉摜
	Vector2Dbl miniPos;						// ��ϯ�߂̈ʒu
	int info;								// ����ް�̉摜
	Vector2Dbl infoPos;						// ����ް�̈ʒu
	int task;								// ����ް�̉摜
	Vector2Dbl taskPos;						// ����ް�̈ʒu
	int poliIco;							// ���j���݂̉摜
	Vector2Dbl poliPos;						// ���j���݂̈ʒu
	int moveIco;							// �ړ����݂̉摜
	Vector2Dbl movePos;						// �ړ����݂̈ʒu
	int attIco;								// �U�����݂̉摜
	Vector2Dbl attPos;						// �U�����݂̈ʒu
	int searIco;							// ��@���݂̉摜
	Vector2Dbl searPos;						// ��@���݂̈ʒu
	int retIco;								// �P�����݂̉摜
	Vector2Dbl retPos;						// �P�����݂̈ʒn

	bool uiHide;							// UI�̔�\���׸�

	int mapGra;								// ��ϯ�߂̉摜
	int disGra;								// ��ϯ�ߏ�̖ړI�n���
	bool mapVis;							// ��ϯ�߂̕\���׸�
	Vector2Dbl mapPos;						// ��ϯ�߂̈ʒu
	Vector2Dbl miniShipPos;					// ��ϯ�ߏ�̊͑��̈ʒu
	Vector2Dbl miniFfPos;					// ��ϯ�ߏ�̊͑��̈ʒu

	Vector2Dbl viewPos;						// ���E�̈ʒu
	double viewSpeed;						// ���_�ړ���
			
	bool searFlag;							// ��@Ӱ�ނ̕\���׸�
	Vector2 searDist;						// ��@ϯ�ߏ�̖ړI�n

	int rogerSe;							// �s���ݒ莞�̌��ʉ�

	int selNum;								// �I�����Ă���͑��̔ԍ�	
	std::vector<Vector2Dbl> distList;		// �e�͑��̖ړI�n�̔z��
	std::vector<Vector2Dbl> miniPosList;	// �e�͑�����ϯ�ߏ�̈ʒu
};