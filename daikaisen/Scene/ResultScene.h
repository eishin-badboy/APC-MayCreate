#pragma once
#include "BaseScene.h"
#include "../Common/Vector2.h"

class ResultScene : public BaseScene
{
public:
	ResultScene();
	~ResultScene();
	unique_Base UpDate(unique_Base own, const GameCtl& controller);		// ���X�V


private:
	int Init(void);			// ������
	void Draw(void);		// �`��

	Vector2 sSize;			// ��ʻ���
	int backGra;			// �w�i�摜
};

