#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <cmath>

#include <DxLib.h>
#include "math.h"
#include "VECTOR2.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	DxLib_Init();
	// ---------- ｼｽﾃﾑ処理
	SetGraphMode(800, 600, 16);  	 // 640 ×　480ﾄﾞｯﾄ65536色ﾓｰﾄﾞに設定
	ChangeWindowMode(true);  // ｳｨﾝﾄﾞｳ ﾓｰﾄﾞで起動
		// DXﾗｲﾌﾞﾗﾘの初期化
	SetDrawScreen(DX_SCREEN_BACK);
	SetWindowText("大海戦");
	if (DxLib_Init() == -1)
	{
		return -1;  // PG塊（関数）から脱退する
	}

	// ｹﾞｰﾑﾙｰﾌﾟ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		DrawBox(300,300,350,350,GetColor(255,255,255),true);
	}

	return 0;
}