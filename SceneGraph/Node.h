#pragma once
#include "Quad.h"
#include "Triangle.h"
#include "Lines.h"
#include "Poly.h"
#include <string>
//#include "gMatrix3.h"

class Node
{
protected:
	string nodeName = "foo";
	list<Node*> children;		//list of pointers to children nodes
	gMatrix3 transformation;	//transformation matrix
	Geometry* G = NULL;			//holds a primitive shape to draw
public:
	Node();
	Node(string name, gMatrix3 t);
	Node(string name, gMatrix3 t, Geometry* g);
	Node(Node* n);	//make a copy of Node n
	~Node();

	string getName();
	gMatrix3 getTransformation;
	list<Node*> getChildren();
	Geometry* getGeometry();

	//methods
	void addNode(Node* parent, Node* child);
	//void addNode(Node* parent, gMatrix3 t);	//transformation node
	void addNode(Node* parent, string s, gMatrix3 t, Geometry* g);//geometry node
	
	void transform(gMatrix3 m); //transform for scales and rotates
	void translate(gMatrix3 m); //transform for translates
	
	void traverse(Node* N, gMatrix3 T);

	void buildGraph(); //builds a default scene graph with this node as root

	void removeNode(Node* parent, Node* child);

	void clearScene();

	void print();

	static void printAllNodes(Node* root);

	static void copyScene(Node* copy, Node* orig);
};
