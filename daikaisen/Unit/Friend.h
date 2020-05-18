#pragma once
#include "Obj.h"


class Friend : public Obj
{
public:
	Friend();
	Friend(Vector2Dbl pos, Vector2 size, SHIP ship, IFF iff);
	~Friend();
	void Draw(void);
	SHIP GetShipType(void)override;
	IFF GetIFF(void)override;
	void Updata(void)override;
	Vector2 GetSize(void);

private:
	bool Init(void);

	Vector2 mousePos;			// Ï³½‚ÌˆÊ’u
	
};

