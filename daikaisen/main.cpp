/* ��C�� */

#include "DxLib.h"
#include "Scene/SceneMng.h"

// ---------- WinMain�֐�
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	lpSceneMng.Run();
	DxLib_End();	// DXײ���؂̏I������
	return 0;
}