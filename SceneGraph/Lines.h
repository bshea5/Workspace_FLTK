#pragma once
#include "Geometry.h"

class Lines :public Geometry
{
protected:
	//N/A
public:
	Lines();
	Lines(list<gVector3> v);
	Lines(Lines* copy);
	virtual ~Lines();

	void draw(gMatrix3 T);
};