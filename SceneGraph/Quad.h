#pragma once
#include "Geometry.h"

class Quad :public Geometry
{
protected:
	//N/A
public:
	Quad();
	Quad(gVector3 v1, gVector3 v2, gVector3 v3, gVector3 v4);
	Quad(Quad* copy);
	virtual ~Quad();

	void draw(gMatrix3 T);
};