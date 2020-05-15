#pragma once
#include "Obj.h"


class Friend :	public Obj
{
public:
	Friend();
	Friend(Vector2Dbl pos, Vector2Dbl size, SHIP ship, IFF iff);
	~Friend();
	void Draw(void);
	SHIP GetShipType(void)override;
	void Updata(void)override;
	Vector2 GetSize(void);

private:
	bool Init(void);
	

};

