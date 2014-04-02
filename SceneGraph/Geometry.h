#pragma once
#include <list>
#include "gMatrix3.h"
#include <FL/Fl.H>
#include <FL/Gl.H>

/*  //Remember//
	The 2D shapes will be represented with vertices
	that consist of 3 values(not 2). 
	e.g. vertex 1 = gVector3(0,0,1) //orgin point
	there must be a 1 in the last point for translation
*/

//abstract class
class Geometry
{
protected:
	float color[3];
	list<gVector3> v;
	string shape = "geometry";
public:
	Geometry();				//constructor
	//Geometry(Geometry* g);	//copy g
	virtual ~Geometry();	//deconstructor

	void setColor(float r, float g, float b);
	float red();
	float green();
	float blue();

	string getShape();

	void transform(gMatrix3 T);

	void print();

	virtual void draw(gMatrix3 T) = 0;	//a pure virtual method
										//making the class abstract
};