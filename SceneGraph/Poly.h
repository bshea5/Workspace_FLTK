#pragma once
#include "Geometry.h"

class Poly :public Geometry
{
protected:
	//N/A
public:
	Poly();
	Poly(list<gVector3> V);
	Poly(Poly* copy);
	virtual ~Poly();

	void draw(gMatrix3 T);
};