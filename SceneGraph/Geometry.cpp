#include "Geometry.h"

Geometry::Geometry()
{
	color[0] = 0;
	color[1] = 0;
	color[2] = 0;
}

Geometry::~Geometry()
{

}

void Geometry::setColor(float r, float g, float b)
{
	color[0] = r; color[1] = g; color[2] = b;
}

float Geometry::red()
{
	return color[0];
}

float Geometry::green()
{
	return color[1];
}

float Geometry::blue()
{
	return color[2];
}

string Geometry::getShape()
{
	return shape;
}

void Geometry::print()
{
	list<gVector3>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
	{
		it->print();
	}
}

//problem here with setting when multiple nodes point to one node
//since this permently changes the geometry vertices
//not using this
void Geometry::transform(gMatrix3 T)
{
	list<gVector3>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
	{
		*it = T * *it;
	}
	//this->draw();
}