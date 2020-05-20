#include <stdio.h>
#include <stdlib.h>
#include <DxLib.h>

#include "Collision.h"
#include "../Scene/GameScene.h"

Collision::Collision()
{
}

Collision::~Collision()
{
}

bool Collision::Updata(std::vector<shared_Obj> objList)
{
	for (auto obj : objList)
	{
		if (obj->GetIFF() == IFF::ENEMY)
		{
			for (auto other : objList)
			{
				if (other->GetIFF() == IFF::BULLET)
				{
					/* “àÏ‚Å‚Ì“–‚½‚è”»’è */
					///if (IsHit(objList))
					///{
					///	other->SetAlive(false);
					///	other->SetDeath(true);
					///	obj->SetAlive(false);
					///	obj->animKey(ANIM::DEATH);
					///}

					/* ¦‚±‚Á‚¿‚ðŽg‚¤¦ */
					//if ((((other->pos().y) < (obj->pos().y + 16)) && (((other->pos().y)) > (obj->pos().y))) && ((obj->pos().x - 15 < other->pos().x + 3) && (other->pos().x < obj->pos().x + 15)))
					//{
					//	//other->SetAlive(false);
					//	//other->SetDeath(true);
					//	//obj->SetAlive(false);
					//	//obj->animKey(ANIM::DEATH);
					//	obj->SetDamage(2);
					//}
				}
			}
		}
	}
	return true;
}
