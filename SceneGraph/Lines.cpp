#include "Lines.h"

Lines::Lines() :Geometry()
{
	//defaults a two vertex line segment
	v.push_back(gVector3(-1, -1, 1));
	v.push_back(gVector3(1, 1, 1));
	shape = "lines";
}

Lines::Lines(list<gVector3> V) : Geometry()
{
	list<gVector3>::iterator it;
	for (it = V.begin(); it != V.end(); it++)
	{
		v.push_back(*it);
	}
	shape = "lines";
}

Lines::Lines(Lines* copy)
{
	v = copy->v;
	color[0] = copy->color[0];
	color[1] = copy->color[1];
	color[2] = copy->color[2];
	shape = "lines";
}

Lines::~Lines()
{

}

void Lines::draw(gMatrix3 T)
{
	list<gVector3>::iterator it;
	glColor3f(color[0], color[1], color[2]);
	glBegin(GL_LINE_STRIP);
	for (it = v.begin(); it != v.end(); it++)
	{
		gVector3 vert = T * (*it);
		glVertex3f(vert[0], vert[1], vert[2]);
	}
	glEnd();
}