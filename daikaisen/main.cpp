#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <cmath>

#include "DxLib.h"
#include "math.h"
#include "VECTOR2.h"

bool SysInit(void);

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	DxLib_Init();

	// ｼｽﾃﾑ系初期化
	if (SysInit() == false)
	{
		return 0;
	}

	// ｹﾞｰﾑﾙｰﾌﾟ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		DrawBox(300,300,350,350,GetColor(255,255,255),true);
	}
}

bool SysInit(void)
{

	// ---------- ｼｽﾃﾑ処理
	SetGraphMode(800, 600, 16);  	 // 640 ×　480ﾄﾞｯﾄ65536色ﾓｰﾄﾞに設定
	ChangeWindowMode(true);  // ｳｨﾝﾄﾞｳ ﾓｰﾄﾞで起動
	SetWindowText("大海戦");  // ｳｨﾝﾄﾞｳの題名を変更

	if (DxLib_Init() == -1)
	{
		return -1;  // PG塊（関数）から脱退する
	}
	// DXﾗｲﾌﾞﾗﾘの初期化
	SetDrawScreen(DX_SCREEN_BACK);

	return true;
}

