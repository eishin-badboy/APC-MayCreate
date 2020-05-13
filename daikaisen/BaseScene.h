#pragma once
#include <memory>

class BaseScene;
class GameCtl;
using unique_Base = std::unique_ptr<BaseScene>;

class BaseScene
{
public:
	virtual ~BaseScene();

	virtual unique_Base UpDate(unique_Base own, const GameCtl& controller) = 0;		// –ˆÌÚ°Ñˆ—‚·‚é‚à‚Ì‚ğ‚Ü‚Æ‚ß‚½ŠÖ”Astate

private:
	virtual int Init(void) = 0;
};

