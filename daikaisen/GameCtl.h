#pragma once
#include <array>

using KEY_ARRAY = std::array<char, 256>;

enum KEY_TYPE
{
	KEY_TYPE_NOW,
	KEY_TYPE_OLD,
	KEY_TYPE_MAX
};

class GameCtl
{
public:
	GameCtl();
	~GameCtl();
	bool UpDate(void);		// ���̓��͏��̍X�V������

	const KEY_ARRAY& GetCtrl(KEY_TYPE type) const;		// �����ɑΉ��������ݸނ̷����͏����擾����

private:
	KEY_ARRAY keyData;			// ���݂��ڰт̷����͏����i�[����
	KEY_ARRAY keyDataOld;		// 1�ڰёO���ڰт̷����͏����i�[����
};

