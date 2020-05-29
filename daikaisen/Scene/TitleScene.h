#pragma once
#include "BaseScene.h"
#include "../Common/Vector2.h"


class TitleScene : public BaseScene
{
public:
	TitleScene();
	~TitleScene();
	unique_Base UpDate(unique_Base own, const GameCtl& controller);


private:
	Vector2 sSize;				// ‰æ–Ê»²½Þ

	int Init(void);
	void Draw(void);

	int titMov;
	int rogo;
	int titBGM;
	bool fadeFlag;

	int flash;
	int flashCnt;
	int moveEffect;
	double angle;
	double rate;
	int fadeCnt;
};

