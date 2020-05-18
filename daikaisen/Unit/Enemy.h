#pragma once
#include <array>
#include "Obj.h"


class Enemy : public Obj
{
public:
	Enemy();
	Enemy(Vector2Dbl pos, Vector2Dbl size, SHIP ship, IFF iff);
	~Enemy();
	SHIP GetShipType(void)override;		// ÕÆ¯Ä(“G)‚Ìî•ñæ“¾‚ÌŠÖ”
	IFF GetIFF(void)override;
	void Updata(void)override;			// î•ñXV‚ÌŠÖ”

	Vector2 GetSize(void);				// “G‚Ì»²½Ş‚ğó‚¯æ‚éŠÖ”

private:
	bool Init(void);

};

