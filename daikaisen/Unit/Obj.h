#pragma once
#include <memory>
#include <vector>
#include <map>
#include "../Common/Vector2.h"

enum class IFF		// “G–¡•û¯•Ê
{
	FRIEND,			// –¡•û
	ENEMY,			// “G
	MAX
};

enum class SHIP
{
	BB,		// íŠÍ
	CV,		// ‹ó•ê
	CA,		// d„
	CL,		// Œy„
	DD,		// ‹ì’€
	SS,		// ö…
	MAX
};


class Obj;
using unique_Obj = std::unique_ptr<Obj>;
using shared_Obj = std::shared_ptr<Obj>;

class Obj
{
public:
	Obj();
	virtual ~Obj();
	virtual void Draw(void);
	virtual IFF GetIFF(void) = 0;
	virtual SHIP GetShipType(void) = 0;
	virtual void Updata(void) = 0;

	Vector2Dbl GetShipPos(void);

protected:
	Vector2Dbl m_pos;
	Vector2Dbl m_distiPos;
	Vector2 m_size;
	double m_angle;
	int m_graph;
};

