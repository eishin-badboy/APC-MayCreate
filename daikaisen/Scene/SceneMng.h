#pragma once
#include "BaseScene.h"
#include "../Common/GameCtl.h"
#include "../Common/Vector2.h"


#define lpSceneMng SceneMng::GetInstance()

class GameCtl;

class SceneMng
{
public:
	static SceneMng& GetInstance(void)			// ���̸׽���߲�����擾����A�����żݸ���݂̏�Ԃɂ��Ă���
	{
		static SceneMng s_Instance;
		return s_Instance;
	}
	void Run(void);
	Vector2 GetScreenSize(void);						// ��ذݻ��ނ��擾����


private:
	SceneMng();
	~SceneMng();

	unique_Base activeScene;	// �e��݂ɱ������邽�߂��ư��߲���

	std::shared_ptr<GameCtl> gameCtl;		// GameController�׽���߲���i�[�p�ϐ�

	bool SysInit(void);			// ���ѓI�ȕϐ��̏��������s��
};

