#include "Poly.h"

Poly::Poly() :Geometry()
{
	//defaults a two vertex line segment
	v.push_back(gVector3(-1, 0, 1));
	v.push_back(gVector3(-0.5, -0.5, 1));
	v.push_back(gVector3(0.5, -0.5, 1));
	v.push_back(gVector3(1, 0, 1));
	v.push_back(gVector3(0.5, 0.5, 1));
	v.push_back(gVector3(-0.5, 0.5, 1));
	shape = "poly";
}

Poly::Poly(list<gVector3> V) : Geometry()
{
	list<gVector3>::iterator it;
	for (it = V.begin(); it != V.end(); it++)
	{
		v.push_back(*it);
	}
	shape = "poly";
}

Poly::Poly(Poly* copy)
{
	v = copy->v;
	color[0] = copy->color[0];
	color[1] = copy->color[1];
	color[2] = copy->color[2];
	shape = "poly";
}

Poly::~Poly()
{
	free(this);
}

void Poly::draw(gMatrix3 T)
{
	list<gVector3>::iterator it;
	glColor3f(color[0], color[1], color[2]);
	glBegin(GL_POLYGON);
	for (it = v.begin(); it != v.end(); it++)
	{
		gVector3 vert = T * (*it);
		glVertex3f(vert[0], vert[1], vert[2]);
	}
	glEnd();
}