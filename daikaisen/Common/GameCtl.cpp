#include "Dxlib.h"
#include "GameCtl.h"



GameCtl::GameCtl()
{
}


GameCtl::~GameCtl()
{
}

bool GameCtl::UpDate(void)
{
	keyDataOld = keyData;
	GetHitKeyStateAll(&keyData[0]);

	return true;
}

const KEY_ARRAY& GameCtl::GetCtrl(KEY_TYPE type) const
{
	if (type == KEY_TYPE_OLD)
	{
		return keyDataOld;
	}

	return keyData;
}
