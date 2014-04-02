#pragma once
#include <Fl/Fl.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Tree.H>
#include <FL/Fl_Dial.H>
#include <FL/Fl_Slider.H>
#include <Fl/Fl_Hor_Nice_Slider.H>
#include <Fl/Fl_Simple_Counter.H>
#include <FL/Fl_Roller.H>
#include <FL/Fl_Color_Chooser.H>
#include "SceneWindow.h"

class GUI_Win :public Fl_Window
{
private:
	int counter = 0;
	int num_frames = 20;
	float prevVals[5];			//0-rotation, 1-scaleX, 2-scaleY, 3-transX, 4-transY
	SceneWindow* gWin;			// a pointer to the graphics window
	Fl_Button* addB;			// a pointer to the add button
	Fl_Button* addQB;			// a pointer to the add Quad button
	Fl_Button* addTB;			// a pointer to the add Triangle button
	Fl_Button* addPB;			// a pointer to the add Polygon button
	Fl_Button* addLB;			// a pointer to the add Polyline button
	Fl_Button* rmB;				// a pointer to the remove button
	Fl_Button* printB;			// a pointer to the print all button
	Fl_Button* exitB;			// a pointer to the exit button
	Fl_Button* clrB;			// a pointer to the clear button
	Fl_Button* resetB;			// a pointer to the reset button
	Fl_Tree* tWin;				// a pointer to the tree window
	Fl_Dial* rotB;				// a pointer to the rotation widget
	Fl_Dial* scaleXB;			// a pointer to the scale x widget
	Fl_Dial* scaleYB;			// a pointer to the scale y widget
	Fl_Roller* transXB;			// a pointer to the translate x widget
	Fl_Roller* transYB;			// a pointer to the translate y widget
	Fl_Color_Chooser* rgbB;		// a pointer to the choose color widget
	Fl_Button* modeB;			// a pointer to the select mode widget
	Fl_Button* renderB;			// a pointer to the render animation widget
	Fl_Hor_Nice_Slider* keySlider; // a pointer to the keyframe slider widget
	Fl_Simple_Counter* frameCounter;	// a pointer to the select frame counter

	static void addCB(Fl_Widget *w, void *data);	// callback method for adding a node w/o geometry button
	static void addQCB(Fl_Widget *w, void *data);	// callback method for the add Quad button
	static void addTCB(Fl_Widget *w, void *data);	// callback method for the add Triangle button
	static void addPCB(Fl_Widget *w, void *data);	// callback method for the add polygon button
	static void addLCB(Fl_Widget *w, void *data);	// callback method for the add polyline button
	static void rmCB(Fl_Widget *w, void *data);		// callback method for the remove leaf node button
	static void printCB(Fl_Widget *w, void *data);	// callback method for the print all button
	static void clrCB(Fl_Widget *w, void *data);	// callback method for the clear button
	static void exitCB(Fl_Widget *w, void *data);	// callback method for the exit button. MUST BE STATIC
	static void resetCB(Fl_Widget *w, void *data);	// callback method for the reset button (magic button)
	static void rotCB(Fl_Widget *w, void *data);	// callback method for rotation dial
	static void scaleXCB(Fl_Widget *w, void *data); // callback method for the scale x dial
	static void scaleYCB(Fl_Widget *w, void *data);	// callback method for the scale y dial
	static void transXCB(Fl_Widget *w, void *data);	// callback method for the translate x roller
	static void transYCB(Fl_Widget *w, void *data);	// callback method for the translate y roller
	static void rgbCB(Fl_Widget *w, void *data);	// callback method for the change color widget thingy
	static void treeCB(Fl_Widget *w, void *data);	// callback method for clicking a branch/leaf in tree
	static void modeCB(Fl_Widget *w, void *data);	// callback method for selecting model/animate mode
	static void renderCB(Fl_Widget *w, void *data); // callback method for rendering the list of frames into an animation
	static void keySliderCB(Fl_Widget *w, void *data); // callback method for sliding the keyframe slider to selecte a frame
	static void frameCounterCB(Fl_Widget *w, void *data);	// callback method for selecting a keyframe

	//////////////////////////////////////////////////////////////////////////
	// For playback
	bool playing;
	static void playbuttonCB(Fl_Widget *w, void *data);
	static void playCB(void *data);	// callback method for the exit button
	///////////////////////////////////////////////////////////////////////////

public:
	GUI_Win(int x, int y, int w, int h, char* c);
	virtual ~GUI_Win();
	
	//getters
	int getNumFrames();
	SceneWindow* getScene();
	Fl_Tree* getTree();
	string getPathName(Fl_Tree_Item* item);	//get path name of selected item in tree
	//setters
	void setNumFrames(int f);				//set the number of frames
	void setScene(SceneWindow* s);			

	void growTree(Node* N, string path);	//build tree based on current gWin
	//void buildFrames();						//build list of scenes for frames
	void resetModelWidgets();				//reset widgets to default positions
	void resetAllWidgets();
};

