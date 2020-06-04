#pragma once
#include "BaseScene.h"
#include "../Common/Vector2.h"


class TitleScene : public BaseScene
{
public:
	TitleScene();
	~TitleScene();
	unique_Base UpDate(unique_Base own, const GameCtl& controller);		// î•ñXV


private:
	Vector2 sSize;			// ‰æ–Ê»²½Ş

	int Init(void);			// ‰Šú‰»
	void Draw(void);		// •`‰æ

	int titMov;				// ”wŒi‚Ì“®‰æ
	int rogo;				// ¹Ş°Ñ‚ÌÀ²ÄÙÛºŞ
	int titBGM;				// À²ÄÙ‰æ–Ê‚ÌBGM
	bool fadeFlag;			// Ìª°ÄŞÌ×¸Ş

	int flash;				// ¸Ø¯¸Ã‘£‚Ì‰æ‘œ
	int flashCnt;			// Ã‘£‚Ì“_–Å¶³İÄ
	int moveEffect;			// ¼°İ‘JˆÚ‚Ì´Ìª¸Ä
	double angle;			// Šp“x
	double rate;			// Šg‘å”ä—¦
	int fadeCnt;			// Ìª°ÄŞŠÔ
};

