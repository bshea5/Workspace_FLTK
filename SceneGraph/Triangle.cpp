#include "Triangle.h"

Triangle::Triangle() :Geometry()
{
	v.push_back(gVector3(-0.5, 0, 1));
	v.push_back(gVector3(0.5, 0, 1));
	v.push_back(gVector3(0, 1, 1));
	shape = "triangle";
}

Triangle::Triangle(gVector3 v1, gVector3 v2, gVector3 v3) :Geometry()
{
	v.push_back(v1); v.push_back(v2); v.push_back(v3);
	shape = "triangle";
}

Triangle::Triangle(Triangle* copy)
{
	v = copy->v;
	color[0] = copy->color[0];
	color[1] = copy->color[1];
	color[2] = copy->color[2];
	shape = "triangle";
}

Triangle::~Triangle()
{

}

void Triangle::draw(gMatrix3 T)
{
	list<gVector3>::iterator it;
	glColor3f(color[0], color[1], color[2]);
	glBegin(GL_TRIANGLES);
	for (it = v.begin(); it != v.end(); it++)
	{
		gVector3 vert = T * (*it);
		glVertex3f(vert[0], vert[1], vert[2]);
	}
	glEnd();
}