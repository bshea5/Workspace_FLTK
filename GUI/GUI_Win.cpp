#pragma once
#include "GUI_Win.h"

//Constructor
GUI_Win::GUI_Win(int x, int y, int w, int h, char* c) :Fl_Window(x, y, w, h, c)
{
	// Set up the window components
	gWin = new SceneWindow(300, 20, 500, 500, "Display");	// OpenGL window
	//original_scene = new SceneWindow(gWin, "Display0");
	// Set up tree view based of scene graph
	tWin = new Fl_Tree(125, 20, 170, 500);
	tWin->begin();
	growTree(gWin->getRoot(), "");
	tWin->end();
	tWin->root()->user_data(new Node());
	tWin->select(tWin->root());
	tWin->callback(this->treeCB, this);

	//add node w/o geometry
	addB = new Fl_Button(10, 20, 100, 40, "Add");
	addB->callback(this->addCB, this);

	//add node with Quad
	addQB = new Fl_Button(10, 70, 100, 40, "Quad");
	addQB->callback(this->addQCB, this);

	//add node with Triangle
	addTB = new Fl_Button(10, 120, 100, 40, "Triangle");
	addTB->callback(this->addTCB, this);

	//add node with Polygon
	addPB = new Fl_Button(10, 170, 100, 40, "Polygon");
	addPB->callback(this->addPCB, this);

	//add node with Polyline
	addLB = new Fl_Button(10, 220, 100, 40, "Polyline");
	addLB->callback(this->addLCB, this);

	//remove node if it is a leaf
	rmB = new Fl_Button(10, 270, 100, 40, "Remove");
	rmB->callback(this->rmCB, this);

	//button to print all nodes and their matrices
	printB = new Fl_Button(10, 320, 100, 40, "Print All");
	printB->callback(this->printCB, gWin);

	//Select Mode Button
	modeB = new Fl_Button(10, 370, 100, 40, "Model Mode");
	modeB->color(FL_YELLOW);
	modeB->callback(this->modeCB, this);

	//button to clear the tree and scene
	clrB = new Fl_Button(700, 770, 50, 20, "Clear");
	clrB->callback(this->clrCB, this);

	//button to exit the program
	exitB = new Fl_Button(760, 770, 50, 20, "Exit");
	exitB->callback(this->exitCB, 0);

	//button to reset to default cat thing image
	resetB = new Fl_Button(640, 770, 50, 20, "Reset");	// magic button
	resetB->callback(this->resetCB, this);

	//Rotation Button
	rotB = new Fl_Dial(280, 550, 125, 125, "Rotation");
	rotB->type(FL_LINE_DIAL);
	rotB->value(0);
	rotB->range(0.0, 360.0);
	rotB->angle1(0.0); rotB->angle2(360.0);
	rotB->callback(this->rotCB, this);
	
	//Scale X value dial
	scaleXB = new Fl_Dial(430, 550, 100, 100, "ScaleX");
	scaleXB->type(FL_LINE_DIAL);
	scaleXB->range(0.5, 2.0);
	scaleXB->value(1.0);
	scaleXB->callback(this->scaleXCB, this);

	//Scale Y value dial
	scaleYB = new Fl_Dial(545, 550, 100, 100, "ScaleY");
	scaleYB->type(FL_LINE_DIAL);
	scaleYB->range(0.5, 2.0);
	scaleYB->value(1.0);
	scaleYB->callback(this->scaleYCB, this);

	//Translate x value roller
	transXB = new Fl_Roller(675, 550, 20, 100, "TransX");
	transXB->range(-0.5, 0.5);
	transXB->value(0);
	transXB->callback(this->transXCB, this);

	//translate y value roller
	transYB = new Fl_Roller(750, 550, 20, 100, "TransY");
	transYB->range(-0.5, 0.5);
	transYB->value(0);
	transYB->callback(this->transYCB, this);

	//RGB color chooser
	rgbB = new Fl_Color_Chooser(15, 550, 200, 95, "RGB");
	rgbB->callback(this->rgbCB, this);

	//key frame slider
	//hide until in animate mode
	keySlider = new Fl_Hor_Nice_Slider(50, 725, 400, 25, "Frame");
	keySlider->range(1, num_frames);
	keySlider->value(1);
	keySlider->callback(this->keySliderCB, this);
	keySlider->hide();

	//key frame counter
	//hide until in animate mode
	frameCounter = new Fl_Simple_Counter(500, 725, 175, 20, "Frame");
	frameCounter->range(1, num_frames);
	frameCounter->value(1);
	frameCounter->step(1);
	frameCounter->callback(this->frameCounterCB, this);
	frameCounter->hide();

	//render button
	//hide until in animate mode
	renderB = new Fl_Button(700, 700, 100, 40, "RENDER");
	renderB->color(FL_DARK_GREEN);
	renderB->callback(this->renderCB, this);
	renderB->hide();

	prevVals[0] = rotB->value();		//previous value of the rotation widget
	prevVals[1] = scaleXB->value();		//previous value of the scaleX widget
	prevVals[2] = scaleYB->value();		//previous value of the scaleY widget
	prevVals[3] = transXB->value();		//previous value of the transX widget
	prevVals[4] = transYB->value();		//previous value of the transY widget

	// For playback
	Fl::add_timeout(1.0 / 5.0, playCB, this); // 5 fps
}

GUI_Win::~GUI_Win()
{
	// clean up memory
	delete(addB);
	delete(addQB);
	delete(addTB);
	delete(addPB);
	delete(addLB);
	delete(rmB);
	delete(printB);
	delete(resetB);
	delete(rotB);
	delete(scaleXB);
	delete(scaleYB);
	delete(transXB);
	delete(transYB);
	delete(tWin);
	delete(gWin);
	delete(clrB);
	delete(exitB);
	delete(modeB);
	delete(renderB);
	delete(keySlider);
	delete(frameCounter);
	addB = NULL;
	addQB = NULL;
	addTB = NULL;
	addPB = NULL;
	addLB = NULL;
	rmB = NULL;
	printB = NULL;
	resetB = NULL;
	rotB = NULL;
	scaleXB = NULL;
	scaleYB = NULL;
	transXB = NULL;
	transYB = NULL;
	tWin = NULL;
	gWin = NULL;
	clrB = NULL;
	exitB = NULL;
	modeB = NULL;
	renderB = NULL;
	keySlider = NULL;
	frameCounter = NULL;

	//frames.clear();
}

SceneWindow* GUI_Win::getScene()
{
	return gWin;
}

Fl_Tree* GUI_Win::getTree()
{
	return tWin;
}

void GUI_Win::addQCB(Fl_Widget *w, void *data)
{
	GUI_Win* gui = (GUI_Win*)data;
	Fl_Tree* tree = gui->tWin;
	//get node at selected branch
	Fl_Tree_Item* item = tree->item_clicked();
	if (item->is_selected())
	{
		Node* parent = (Node*)item->user_data();
		//add node to scene graph
		Quad* q = new Quad();
		string name = "quad" + to_string(gui->counter++);
		q->setColor(0.0, 0.4, 0.8);
		Node* child = new Node(name, gMatrix3::identity(), q );
		parent->addNode(parent, child);
		Fl_Tree_Item* leaf = item->add(Fl_Tree_Prefs(), name.c_str());
		leaf->user_data(child);
		gui->redraw();
		gui->getScene()->redraw();
	}
}

void GUI_Win::addTCB(Fl_Widget *w, void *data)
{
	GUI_Win* gui = (GUI_Win*)data;
	Fl_Tree* tree = gui->tWin;
	//get node at selected branch
	Fl_Tree_Item* item = tree->item_clicked();
	if (item->is_selected())
	{
		Node* parent = (Node*)item->user_data();
		//add node to scene graph
		Triangle* t = new Triangle();
		string name = "tri" + to_string(gui->counter++);
		t->setColor(0.0, 0.8, 0.4);
		Node* child = new Node(name, gMatrix3::identity(), t);
		parent->addNode(parent, child);
		Fl_Tree_Item* leaf = item->add(Fl_Tree_Prefs(), name.c_str());
		leaf->user_data(child);

		gui->redraw();
		gui->getScene()->redraw();
	}
}

void GUI_Win::addPCB(Fl_Widget *w, void *data)
{
	GUI_Win* gui = (GUI_Win*)data;
	Fl_Tree* tree = gui->tWin;
	//get node at selected branch
	Fl_Tree_Item* item = tree->item_clicked();
	if (item->is_selected())
	{
		Node* parent = (Node*)item->user_data();
		//add node to scene graph
		Poly* l = new Poly();
		string name = "poly" + to_string(gui->counter++);
		l->setColor(0.8, 0.0, 0.6);
		Node* child = new Node(name, gMatrix3::identity(), l);
		parent->addNode(parent, child);
		//add leaf to branch
		Fl_Tree_Item* leaf = item->add(Fl_Tree_Prefs(), name.c_str());
		leaf->user_data(child);

		gui->redraw();
		gui->getScene()->redraw();
	}
}

void GUI_Win::addLCB(Fl_Widget *w, void *data)
{
	GUI_Win* gui = (GUI_Win*)data;
	Fl_Tree* tree = gui->tWin;
	//get node at selected branch
	Fl_Tree_Item* item = tree->item_clicked();
	if (item->is_selected())
	{
		Node* parent = (Node*)item->user_data();
		//add node to scene graph
		Lines* l = new Lines();
		string name = "line" + to_string(gui->counter++);
		l->setColor(0.8, 0.9, 0.0);
		Node* child = new Node(name, gMatrix3::identity(), l);
		parent->addNode(parent, child);
		//add leaf to branch
		Fl_Tree_Item* leaf = item->add(Fl_Tree_Prefs(), name.c_str());
		leaf->user_data(child);

		gui->redraw();
		gui->getScene()->redraw();
	}
}

void GUI_Win::addCB(Fl_Widget *w, void *data)
{
	cout << "add NOde" << endl;
	GUI_Win* gui = (GUI_Win*)data;
	Fl_Tree* tree = gui->tWin;
	//get node at selected branch
	Fl_Tree_Item* item = tree->item_clicked();
	if (item->is_selected())
	{

		Node* parent = (Node*)item->user_data();
		//add node to scene graph
		string name = "node" + to_string(gui->counter++);
		Node* child = new Node(name, gMatrix3::identity());
		parent->addNode(parent, child);
		//add leaf to branch
		Fl_Tree_Item* leaf = item->add(Fl_Tree_Prefs(),name.c_str());
		leaf->user_data(child);
		gui->redraw();
		gui->getScene()->redraw();
	}
}

void GUI_Win::rmCB(Fl_Widget *w, void *data)
{
	GUI_Win* gui = (GUI_Win*)data;
	Fl_Tree* tree = gui->tWin;
	Fl_Tree_Item* item = tree->item_clicked();
	if (item->has_children() == 0)
	{
		Node* parent = (Node*)item->parent()->user_data();
		Node* child = (Node*)item->user_data();
		child->removeNode(parent, child);
		item->deselect();
		tree->select(item->parent());
		tree->remove(item);
		//redraw gui and scene
		gui->redraw();
		gui->getScene()->redraw();
	}
	else
		cout << "Can only remove leafs" << endl;
}

void GUI_Win::printCB(Fl_Widget *w, void *data)
{
	SceneWindow* s = (SceneWindow*)data;
	cout << s->getName() << endl;
	Node::printAllNodes(s->getRoot());
}

//set GUI to Animate or Model mode (default is Model Mode)
void GUI_Win::modeCB(Fl_Widget *w, void *data)
{
	Fl_Button* button = (Fl_Button*)w;
	GUI_Win* gui = (GUI_Win*)data;
	Fl_Hor_Nice_Slider* slider = gui->keySlider;
	Fl_Simple_Counter* counter = gui->frameCounter;
	Fl_Button* render = gui->renderB;

	//hide or show slider and counter
	//if changing to animation mode, make a list of frames
	//if changing to model mode, model is based off of the first frame
	if (slider->visible() || counter->visible())
	{
		slider->hide();
		counter->hide();
		render->hide();
		button->label("Model Mode");
		button->color(FL_YELLOW);
		gui->gWin->clearFrames();

		gui->tWin->deselect_all();
		gui->tWin->clear();
		gui->tWin->begin();
		gui->growTree(gui->gWin->getRoot(), "");
		gui->tWin->end();
	}
	else
	{
		slider->show();
		counter->show();
		render->show();
		button->label("Animate Mode");
		button->color(FL_GREEN);
		//create a list of scenes, or frames, based on current scene
		gui->gWin->buildFrames(gui->num_frames);
	}
}

void GUI_Win::clrCB(Fl_Widget *w, void *data)	// callback method for the clear button
{
	GUI_Win* guiStuff = (GUI_Win*)data;
	//clear the scene
	Node* root = guiStuff->getScene()->getRoot();
	root->clearScene();
	root->print();
	SceneWindow* scene = guiStuff->getScene();
	scene->resetWindow();

	//clear the tree
	Fl_Tree* tree = guiStuff->getTree();
	tree->clear();
	cout << "Clear!" << endl;
	guiStuff->growTree(root, "");

	//call these to redraw gui and scene
	guiStuff->redraw();
	guiStuff->getScene()->redraw();
	tree->deselect_all();

	guiStuff->resetAllWidgets();
}

void GUI_Win::exitCB(Fl_Widget *w, void *data)	// callback method for the exit button
{
	exit(0);	// end the whole program
}

void GUI_Win::resetCB(Fl_Widget *w, void *data) // magic button callback
{
	//rebuild scene graph
	GUI_Win* gui = (GUI_Win*)data;
	SceneWindow* scene = gui->getScene();
	Node* root = scene->getRoot();
	root->buildGraph();
	//rebuild fl tree
	Fl_Tree* tree = gui->getTree();
	tree->clear();
	tree->begin();
	gui->growTree(root, "");
	tree->end();
	gui->redraw();
	//gui->rgbB->redraw();
	scene->redraw();
	tree->deselect_all();
	//tree->select(tree->root());
	gui->resetAllWidgets();
}

void GUI_Win::treeCB(Fl_Widget *w, void *data) {
	Fl_Tree *tree = (Fl_Tree*)w;
	fprintf(stderr, "TreeCallback: data=%d, ", (int)data);
	GUI_Win* gui = (GUI_Win*)data;
	// Find item that was clicked
	Fl_Tree_Item *item = (Fl_Tree_Item*)tree->item_clicked();
	if (item) {
		fprintf(stderr, "item='%s'\n", item->label());	// print item's label
		Node* node = (Node*)item->user_data();
		if (node)
			node->print();
		if (node->getGeometry() != NULL)
		{
			Geometry* shape = node->getGeometry();
			Fl_Color_Chooser* colorer = gui->rgbB;
			colorer->rgb(shape->red(), shape->green(), shape->blue());
		}
	}
	else {
		fprintf(stderr, "(NO ITEM?)\n");
	}
}

void GUI_Win::rotCB(Fl_Widget *w, void *data)
{
	GUI_Win* gui = (GUI_Win*)data;
	Fl_Dial* dial = (Fl_Dial*)w;
	float prevVal = gui->prevVals[0];
	Fl_Tree_Item* item = gui->getTree()->item_clicked();
	if (item->is_selected() && item->user_data())
	{
		Node* rotNode = (Node*)item->user_data();
		float rotValue = dial->value() - prevVal;
		gui->prevVals[0] = dial->value();
		gMatrix3 rotation = gMatrix3::rotation2D(rotValue);
		rotNode->transform(rotation);
		gui->getScene()->redraw();
	}
}

void GUI_Win::scaleXCB(Fl_Widget *w, void *data)
{
	GUI_Win* gui = (GUI_Win*)data;
	Fl_Dial* dial = (Fl_Dial*)w;
	Fl_Tree_Item* item = gui->getTree()->item_clicked();
	if (item->is_selected() && item->user_data())
	{
		Node* rotNode = (Node*)item->user_data();
		float scaleX = dial->value();
		gMatrix3 scale = gMatrix3::scale2D(scaleX, 1);
		rotNode->transform(scale);
		gui->getScene()->redraw();
	}
}

void GUI_Win::scaleYCB(Fl_Widget *w, void *data)
{
	GUI_Win* gui = (GUI_Win*)data;
	Fl_Dial* dial = (Fl_Dial*)w;
	Fl_Tree_Item* item = gui->getTree()->item_clicked();
	if (item->is_selected() && item->user_data())
	{
		Node* rotNode = (Node*)item->user_data();
		float scaleY = dial->value();
		gMatrix3 scale = gMatrix3::scale2D(1, scaleY);
		rotNode->transform(scale);
		gui->getScene()->redraw();
	}
}

void GUI_Win::transXCB(Fl_Widget *w, void *data)
{
	GUI_Win* gui = (GUI_Win*)data;
	Fl_Roller* roller = (Fl_Roller*)w;
	Fl_Tree_Item* item = gui->getTree()->item_clicked();
	if (item->is_selected() && item->user_data())
	{
		Node* transNode = (Node*)item->user_data();
		float transX = roller->value();// -gui->prevVals[3];
		//gui->prevVals[3] = roller->value();
		gMatrix3 t = gMatrix3::translation2D(transX, 0);
		transNode->translate(t);
		gui->getScene()->redraw();
		roller->value(0);
	}
}

void GUI_Win::transYCB(Fl_Widget *w, void *data)
{
	GUI_Win* gui = (GUI_Win*)data;
	Fl_Roller* roller = (Fl_Roller*)w;
	Fl_Tree_Item* item = gui->getTree()->item_clicked();
	if (item->is_selected() && item->user_data())
	{
		Node* transNode = (Node*)item->user_data();
		float transY = roller->value();// -gui->prevVals[4];
		//gui->prevVals[4] = roller->value();
		gMatrix3 t = gMatrix3::translation2D(0, transY);
		transNode->translate(t);
		gui->getScene()->redraw();
		roller->value(0);
	}
}

void GUI_Win::rgbCB(Fl_Widget *w, void *data)
{
	GUI_Win* gui = (GUI_Win*)data;
	Fl_Color_Chooser* chooser = (Fl_Color_Chooser*)w;
	Fl_Tree_Item* item = gui->getTree()->item_clicked();
	Node* n = (Node*)item->user_data();
	Geometry* g = n->getGeometry();
	if (g != NULL)
	{
		g->setColor( chooser->r(), chooser->g(), chooser->b() );
		gui->getScene()->redraw();
	}
}

void GUI_Win::keySliderCB(Fl_Widget *w, void *data)
{
	Fl_Hor_Nice_Slider* slider = (Fl_Hor_Nice_Slider*)w;
	GUI_Win* gui = (GUI_Win*)data;
	SceneWindow* scene = gui->getScene();
	Fl_Simple_Counter* counter = gui->frameCounter;

	counter->value(slider->value());

	scene->switchToFrame(slider->value()-1);

	gui->tWin->deselect_all();
	gui->tWin->clear();
	gui->tWin->begin();
	gui->growTree(scene->getRoot(), "");
	gui->tWin->end();

}

void GUI_Win::frameCounterCB(Fl_Widget *w, void *data)
{
	Fl_Simple_Counter* counter = (Fl_Simple_Counter*)w;
	GUI_Win* gui = (GUI_Win*)data;
	SceneWindow* scene = gui->getScene();
	Fl_Hor_Nice_Slider* slider = gui->keySlider;

	slider->value(counter->value());

	scene->switchToFrame(counter->value()-1);

	gui->tWin->deselect_all();
	gui->tWin->clear();
	gui->tWin->begin();
	gui->growTree(scene->getRoot(), "");
	gui->tWin->end();
}

void GUI_Win::renderCB(Fl_Widget *w, void *data)
{
	GUI_Win* gui = (GUI_Win*)data;
	gui->getScene()->renderDraw();
}

string GUI_Win::getPathName(Fl_Tree_Item* item)
{
	string pathName = "";
	if (item->parent())
	{
		return pathName = getPathName(item->parent()) + "/" 
						+ (string)item->label();
	}
	return (string)item->label();
}

//expecting tree->begin having been called
//follow up with tree->end
void GUI_Win::growTree(Node* N, string path)
{
	string pathName = path + "/" + N->getName();
	tWin->add(pathName.c_str());
	( tWin->find_item(pathName.c_str()) )->user_data(N);
	list<Node*>::iterator it;
	list<Node*> children = N->getChildren();
	for (it = children.begin(); it != children.end(); it++)
	{
		growTree(*it, pathName);
	}
}

int GUI_Win::getNumFrames()
{
	return num_frames;
}

void GUI_Win::setNumFrames(int f)
{
	num_frames = f;
}

//reset all gui widgets to defaults (zeros?)
void GUI_Win::resetModelWidgets()
{
	rotB->value(0);
	scaleXB->value(1.0);
	scaleYB->value(1.0);
	transXB->value(0);
	transYB->value(0);

	rgbB->rgb(0.0, 0.0, 0.0);

	prevVals[0] = 0;
	prevVals[1] = 1;
	prevVals[2] = 1;
	prevVals[3] = 0;
	prevVals[4] = 0;
}

void GUI_Win::resetAllWidgets()
{
	keySlider->value(1);
	frameCounter->value(1);
	resetModelWidgets();
}

////////////////////////////////////////////////////////////////////////////
// For playback
void GUI_Win::playbuttonCB(Fl_Widget *w, void *data)
{
	GUI_Win* win = (GUI_Win*)data;
	win->playing = !win->playing;
}
void GUI_Win::playCB(void *data)	// callback method for the exit button
{
	GUI_Win* win = (GUI_Win*)data;
	if (win->playing){

		win->gWin->redraw();
	}
	Fl::repeat_timeout(1.0 / 5.0, playCB, win); // 5 fps
}
///////////////////////////////////////////////////////////////////////////