#pragma once
#include "BaseScene.h"
#include "../Common/Vector2.h"


class TitleScene : public BaseScene
{
public:
	TitleScene();
	~TitleScene();
	unique_Base UpDate(unique_Base own, const GameCtl& controller);		// ���X�V


private:
	Vector2 sSize;			// ��ʻ���

	int Init(void);			// ������
	void Draw(void);		// �`��

	int titMov;				// �w�i�̓���
	int rogo;				// �ްт�����ۺ�
	int titBGM;				// ���ى�ʂ�BGM
	bool fadeFlag;			// ̪����׸�

	int flash;				// �د��Ñ��̉摜
	int flashCnt;			// �Ñ��̓_�Ŷ���
	int moveEffect;			// ��ݑJ�ڂ̴̪��
	double angle;			// �p�x
	double rate;			// �g��䗦
	int fadeCnt;			// ̪��ގ���
};

