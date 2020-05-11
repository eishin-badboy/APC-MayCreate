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

	// ���ьn������
	if (SysInit() == false)
	{
		return 0;
	}

	// �ް�ٰ��
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		DrawBox(300,300,350,350,GetColor(255,255,255),true);
	}
}

bool SysInit(void)
{

	// ---------- ���я���
	SetGraphMode(800, 600, 16);  	 // 640 �~�@480�ޯ�65536�FӰ�ނɐݒ�
	ChangeWindowMode(true);  // ����޳ Ӱ�ނŋN��
	SetWindowText("��C��");  // ����޳�̑薼��ύX

	if (DxLib_Init() == -1)
	{
		return -1;  // PG��i�֐��j����E�ނ���
	}
	// DXײ���؂̏�����
	SetDrawScreen(DX_SCREEN_BACK);

	return true;
}

