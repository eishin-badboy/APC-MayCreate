#pragma once
#include "BaseScene.h"
#include "../Common/Vector2.h"

class ResultScene : public BaseScene
{
public:
	ResultScene();
	~ResultScene();
	unique_Base UpDate(unique_Base own, const GameCtl& controller);		// î•ñXV


private:
	int Init(void);			// ‰Šú‰»
	void Draw(void);		// •`‰æ

	Vector2 sSize;			// ‰æ–Ê»²½Ş
	int backGra;			// ”wŒi‰æ‘œ
};

