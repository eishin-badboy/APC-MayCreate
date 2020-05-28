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
	Vector2 sSize;				// æÊ»²½Þ

	int Init(void);
	void FleetMove(void);		// ÍàÚ®
	void CheckDistina(void);	// ÚIn
	void Searching(void);		// ã@@­i
	void ViewMove(void);		// _Ú®
	bool CheckGameEnd(void);	// sð`FbN		
	bool GameDraw(void);		// `æ

	std::vector<shared_Obj> m_objList;		// Objp³¸×½ÌÂÏzñ(µØ¼ÞÅÙ)

	std::vector<shared_Obj> f_fleetListF;	// ¡ûæêÍàÌÂÏzñ
	std::vector<shared_Obj> f_fleetListS;	// ¡ûæñÍàÌÂÏzñ
	std::vector<shared_Obj> f_fleetListT;	// ¡ûæOÍàÌÂÏzñ

	std::vector<shared_Obj> e_fleetListF;	// GæêÍàÌÂÏzñ
	std::vector<shared_Obj> e_fleetListS;	// GæñÍàÌÂÏzñ
	std::vector<shared_Obj> e_fleetListT;	// GæOÍàÌÂÏzñ



	int charaGra;				// Ã½Äp¸Þ×Ì¨¯¸
	Vector2Dbl charaPos;		// Ã½ÄpÊn
	Vector2 mousePos;			// Ï³½ÌÊu
	Vector2Dbl distiPos;		// ÚIn
	Vector2 miniDistPos;		// Ï¯ÌßãÌÚIn
	float charaAngle;			// Ã½ÄpÌpx
	double rotaAngle;			// ñ]px

	Vector2Dbl enemyPos;
	Vector2Dbl bulletPos;
	bool bulletFlag;
	double bulAngle;
	int enemyHP;
	int bulDamage;


	// wiÖA
	int waveBG;					// wiÌg
	int cloudGra;
	Vector2Dbl cloPos;

	// UIÖA
	int gameBGM;
	int shotSe;
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

	int mapGra;
	int disGra;
	bool mapVis;
	Vector2Dbl mapPos;
	Vector2Dbl miniShipPos;
	Vector2Dbl miniFfPos;

	Vector2Dbl viewPos;		// E
	double viewSpeed;

	bool searFlag;			// ã@p
	Vector2 searDist;

	int rogerSe;
};