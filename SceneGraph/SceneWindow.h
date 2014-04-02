#pragma once
#include <FL/Fl.H>
#include <FL/Gl.H>
#include <Fl/Fl_Gl_Window.H>
#include <iostream>
#include "Node.h"
#include <sstream>
#include <jpeg/jpeglib.h>

// The class SceneWindow has a method for drawing things to the screen 
// (so to speak).
// The SceneWindow class is the only class that has any methods called from main
// SceneWindow has a pointer to Node* Root 
// which in turn has a pointer to Geometry* shape
class SceneWindow:public Fl_Gl_Window { // Create a subclass of the FL_GL_Window class
protected:
	Node* root = new Node();		//pointer to root Node
	string name = "";
	list<Node*> frames;				//a list of root nodes to scenegraphs
public:
	SceneWindow(int x, int y, int w, int h, char* c);
	SceneWindow(SceneWindow* s, string n); //clone a scene
	virtual ~SceneWindow();

	void buildFrames(int n);		//build a list of n scene graphs
	void switchToFrame(int i);		//change to frame of index i
	void clearFrames();				//clear list of frames.

	void draw();
	void renderDraw();

	void resetWindow();

	void setRoot(Node* r);
	Node* getRoot();
	string getName();
};