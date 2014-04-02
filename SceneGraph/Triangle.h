#pragma once
#include "Geometry.h"

class Triangle :public Geometry
{
protected:
	//N/A
public:
	Triangle();
	Triangle(gVector3 v1, gVector3 v2, gVector3 v3);
	Triangle(Triangle* copy);
	virtual ~Triangle();

	void draw(gMatrix3 T);
};