#include "Quad.h"

Quad::Quad() :Geometry()
{
	v.push_back(gVector3(-1, -1, 1));
	v.push_back(gVector3(1, -1, 1));
	v.push_back(gVector3(1, 1, 1));
	v.push_back(gVector3(-1, 1, 1));
	shape = "quad";
}

Quad::Quad(gVector3 v1, gVector3 v2, gVector3 v3, gVector3 v4) : Geometry()
{
	v.push_back(v1); v.push_back(v2); v.push_back(v3); v.push_back(v4);
	shape = "quad";
}

Quad::Quad(Quad* copy)
{
	v = copy->v;
	color[0] = copy->color[0];
	color[1] = copy->color[1];
	color[2] = copy->color[2];
	shape = "quad";
}

Quad::~Quad()
{

}

void Quad::draw(gMatrix3 T)
{
	list<gVector3>::iterator it;
	glColor3f(color[0], color[1], color[2]);
	glBegin(GL_QUADS);
	for (it = v.begin(); it != v.end(); it++)
	{
		gVector3 vert = T * (*it);
		glVertex3f(vert[0], vert[1], vert[2]);
	}
	glEnd();
}