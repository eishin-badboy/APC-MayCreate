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

	std::vector<shared_Obj> m_objList;		// Obj�p���׽�̉ϔz��

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
};