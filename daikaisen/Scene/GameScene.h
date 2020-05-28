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
	Vector2 sSize;				// 画面ｻｲｽﾞ

	int Init(void);
	void FleetMove(void);		// 艦隊移動処理
	void CheckDistina(void);	// 目的地
	void Searching(void);		// 偵察機発進
	void ViewMove(void);		// 視点移動
	bool CheckGameEnd(void);	// 勝敗をチェック		
	bool GameDraw(void);		// 描画処理

	std::vector<shared_Obj> m_objList;		// Obj継承ｸﾗｽの可変配列(ｵﾘｼﾞﾅﾙ)

	std::vector<shared_Obj> f_fleetListF;	// 味方第一艦隊の可変配列
	std::vector<shared_Obj> f_fleetListS;	// 味方第二艦隊の可変配列
	std::vector<shared_Obj> f_fleetListT;	// 味方第三艦隊の可変配列

	std::vector<shared_Obj> e_fleetListF;	// 敵第一艦隊の可変配列
	std::vector<shared_Obj> e_fleetListS;	// 敵第二艦隊の可変配列
	std::vector<shared_Obj> e_fleetListT;	// 敵第三艦隊の可変配列



	int charaGra;				// ﾃｽﾄ用ｸﾞﾗﾌｨｯｸ
	Vector2Dbl charaPos;		// ﾃｽﾄ用位地
	Vector2 mousePos;			// ﾏｳｽの位置
	Vector2Dbl distiPos;		// 目的地
	Vector2 miniDistPos;		// ﾏｯﾌﾟ上の目的地
	float charaAngle;			// ﾃｽﾄ用の角度
	double rotaAngle;			// 回転角度

	Vector2Dbl enemyPos;
	Vector2Dbl bulletPos;
	bool bulletFlag;
	double bulAngle;
	int enemyHP;
	int bulDamage;


	// 背景関連
	int waveBG;					// 背景の波
	int cloudGra;
	Vector2Dbl cloPos;

	// UI関連
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

	Vector2Dbl viewPos;		// 視界
	double viewSpeed;

	bool searFlag;			// 偵察用
	Vector2 searDist;

	int rogerSe;
};