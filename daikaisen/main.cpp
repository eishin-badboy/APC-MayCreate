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
	// ---------- ���я���
	SetGraphMode(800, 600, 16);  	 // 640 �~�@480�ޯ�65536�FӰ�ނɐݒ�
	ChangeWindowMode(true);  // ����޳ Ӱ�ނŋN��
		// DXײ���؂̏�����
	SetDrawScreen(DX_SCREEN_BACK);
	SetWindowText("��C��");
	if (DxLib_Init() == -1)
	{
		return -1;  // PG��i�֐��j����E�ނ���
	}

	// �ް�ٰ��
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		DrawBox(300,300,350,350,GetColor(255,255,255),true);
	}

	return 0;
}