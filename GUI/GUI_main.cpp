#include "GUI_Win.h"

int main(void)
{
	GUI_Win *g = new GUI_Win(100, 60, 820, 800, "Playing with Polygons"); // create a window
	g->show();  // show the window
	return Fl::run(); // tell FLTK to go
}