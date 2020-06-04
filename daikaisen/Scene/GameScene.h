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
	unique_Base UpDate(unique_Base own, const GameCtl& controller);		// 情報更新


private:
	Vector2 sSize;				// 画面ｻｲｽﾞ

	int Init(void);				// 初期化
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

	std::vector<shared_Obj> m_airList;	// 航空機の可変配列



	int charaGra;							// ﾃｽﾄ用ｸﾞﾗﾌｨｯｸ
	Vector2Dbl charaPos;					// ﾃｽﾄ用位地
	Vector2 mousePos;						// ﾏｳｽの位置
	Vector2Dbl distiPos;					// 目的地
	Vector2 miniDistPos;					// ﾏｯﾌﾟ上の目的地
	float charaAngle;						// ﾃｽﾄ用の角度
	double rotaAngle;						// 回転角度

	Vector2Dbl enemyPos;					// 敵の位置
	Vector2Dbl bulletPos;					// 弾の位置
	bool bulletFlag;						// 弾の出現ﾌﾗｸﾞ
	double bulAngle;						// 弾の発射角度
	int enemyHP;							// 敵の体力
	int bulDamage;							// 弾によるﾀﾞﾒｰｼﾞ


	// 背景関連
	int waveBG;								// 背景の波
	int cloudGra;							// 雲の画像
	Vector2Dbl cloPos;						// 雲の位置

	// UI関連
	int gameBGM;							// ｹﾞｰﾑ中のBGM
	int shotSe;								// 砲撃の効果音
	bool bgmStart;							// BGMの再生許可ﾌﾗｸﾞ
	int miniMap;							// ﾐﾆﾏｯﾌﾟの画像
	Vector2Dbl miniPos;						// ﾐﾆﾏｯﾌﾟの位置
	int info;								// 情報ﾊﾞｰの画像
	Vector2Dbl infoPos;						// 情報ﾊﾞｰの位置
	int task;								// ﾀｸｽﾊﾞｰの画像
	Vector2Dbl taskPos;						// ﾀｽｸﾊﾞｰの位置
	int poliIco;							// 方針ﾎﾞﾀﾝの画像
	Vector2Dbl poliPos;						// 方針ﾎﾞﾀﾝの位置
	int moveIco;							// 移動ﾎﾞﾀﾝの画像
	Vector2Dbl movePos;						// 移動ﾎﾞﾀﾝの位置
	int attIco;								// 攻撃ﾎﾞﾀﾝの画像
	Vector2Dbl attPos;						// 攻撃ﾎﾞﾀﾝの位置
	int searIco;							// 偵察ﾎﾞﾀﾝの画像
	Vector2Dbl searPos;						// 偵察ﾎﾞﾀﾝの位置
	int retIco;								// 撤退ﾎﾞﾀﾝの画像
	Vector2Dbl retPos;						// 撤退ﾎﾞﾀﾝの位地

	bool uiHide;							// UIの非表示ﾌﾗｸﾞ

	int mapGra;								// 大ﾏｯﾌﾟの画像
	int disGra;								// 大ﾏｯﾌﾟ上の目的地ﾋﾟﾝ
	bool mapVis;							// 大ﾏｯﾌﾟの表示ﾌﾗｸﾞ
	Vector2Dbl mapPos;						// 大ﾏｯﾌﾟの位置
	Vector2Dbl miniShipPos;					// 大ﾏｯﾌﾟ上の艦隊の位置
	Vector2Dbl miniFfPos;					// ﾐﾆﾏｯﾌﾟ上の艦隊の位置

	Vector2Dbl viewPos;						// 視界の位置
	double viewSpeed;						// 視点移動量
			
	bool searFlag;							// 偵察ﾓｰﾄﾞの表示ﾌﾗｸﾞ
	Vector2 searDist;						// 偵察ﾏｯﾌﾟ上の目的地

	int rogerSe;							// 行動設定時の効果音

	int selNum;								// 選択している艦隊の番号	
	std::vector<Vector2Dbl> distList;		// 各艦隊の目的地の配列
	std::vector<Vector2Dbl> miniPosList;	// 各艦隊のﾐﾆﾏｯﾌﾟ上の位置
};