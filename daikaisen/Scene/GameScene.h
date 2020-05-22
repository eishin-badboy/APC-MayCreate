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
	unique_Base UpDate(unique_Base own, const GameCtl& controller);


private:
	Vector2 sSize;				// ��ʻ���

	int Init(void);
	bool CheckGameEnd(void);	// ���s���`�F�b�N		
	bool GameDraw(void);		// �`�揈��

	std::vector<shared_Obj> m_objList;		// Obj�p���׽�̉ϔz��(�ؼ���)

	std::vector<shared_Obj> f_fleetListF;	// �������͑��̉ϔz��
	std::vector<shared_Obj> f_fleetListS;	// �������͑��̉ϔz��
	std::vector<shared_Obj> f_fleetListT;	// ������O�͑��̉ϔz��

	std::vector<shared_Obj> e_fleetListF;	// �G���͑��̉ϔz��
	std::vector<shared_Obj> e_fleetListS;	// �G���͑��̉ϔz��
	std::vector<shared_Obj> e_fleetListT;	// �G��O�͑��̉ϔz��



	int charaGra;				// ýėp���̨��
	Vector2Dbl charaPos;		// ýėp�ʒn
	Vector2 mousePos;			// ϳ��̈ʒu
	float charaAngle;			// ýėp�̊p�x
	double rotaAngle;			// ��]�p�x

	Vector2Dbl enemyPos;
	Vector2Dbl bulletPos;
	bool bulletFlag;
	double bulAngle;
	int enemyHP;
	int bulDamage;


	// �w�i�֘A
	int waveBG;					// �w�i�̔g
	int cloudGra;
	Vector2Dbl cloPos;

	// UI�֘A
	int gameBGM;
	bool bgmStart;
	int miniMap;
	Vector2Dbl miniPos;
	int info;
	Vector2Dbl infoPos;
	int task;
	Vector2Dbl taskPos;
	int poliIco;
	Vector2Dbl poliPos;
	int moveIco;
	Vector2Dbl movePos;
	int attIco;
	Vector2Dbl attPos;
	int searIco;
	Vector2Dbl searPos;
	int retIco;
	Vector2Dbl retPos;
	bool uiHide;
};