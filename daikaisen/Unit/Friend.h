#pragma once
#include "Obj.h"


class Friend :	public Obj
{
public:
	Friend();
	Friend(VECTOR2 pos, VECTOR2 size, SHIP ship, IFF iff);
	~Friend();
	void Draw(void);
	SHIP GetShipType(void)override;
	void Updata(void)override;
	VECTOR2 GetSize(void);

private:
	bool Init(void);
	

};

