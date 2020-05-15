#pragma once
#include <array>
#include <vector>
#include "BaseScene.h"
#include "../Unit/Obj.h"
#include "../Common/VECTOR2.h"


class GameScene : public BaseScene
{
public:
	GameScene();
	~GameScene();
	unique_Base UpDate(unique_Base own, const GameCtl& controller);


private:
	VECTOR2 sSize;				// ��ʻ���

	int Init(void);
	bool CheckGameEnd(void);	// ���s���`�F�b�N		
	bool GameDraw(void);		// �`�揈��

	std::vector<shared_Obj> m_objList;		// Obj�p���׽�̉ϔz��

	int charaGra;				// ýėp���̨��
	VECTOR2 charaPos;			// ýėp�ʒn
	VECTOR2 mousePos;			// ϳ��̈ʒu
	float charaAngle;			// ýėp�̊p�x
	double rotaAngle;			// ��]�p�x

	VECTOR2 enemyPos;
	VECTOR2 bulletPos;
	bool bulletFlag;
	double bulAngle;
	int enemyHP;
	int bulDamage;
};