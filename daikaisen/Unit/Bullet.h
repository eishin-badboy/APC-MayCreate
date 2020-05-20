#pragma once
#include "Obj.h"


class Bullet : public Obj
{
public:
	Bullet();
	Bullet(Vector2Dbl pos, Vector2 size, double angle);
	~Bullet();
	void Updata(void)override;
	IFF GetIFF(void)override;
	SHIP GetShipType(void)override;
	void Draw(void);

	Vector2 GetSize(void);

private:
	bool Init(void);
};

