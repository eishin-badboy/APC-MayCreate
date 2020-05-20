#pragma once
#include <vector>
#include "../Unit/Obj.h"
#include "../Unit/Friend.h"
#include "../Unit/Enemy.h"
#include "../Unit/Bullet.h"
#include "../Common/Vector2.h"


class Collision
{
public:
	Collision();
	~Collision();
	bool Updata(std::vector<shared_Obj> objList);
};

