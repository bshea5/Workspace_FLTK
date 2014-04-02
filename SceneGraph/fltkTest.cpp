//#include <FL/Fl.H>
//#include <FL/Gl.H>
//#include <Fl/Fl_Gl_Window.H>
//#include <iostream>
//#include "Node.h"
//
//
//class GlTest:public Fl_Gl_Window{ // Create a subclass of the FL_GL_Window class
//	void draw(){							// Override the draw method
//		if (!valid()){						// Some housekeeping
//			valid(1);
//			glLoadIdentity();				// Prepare the OpenGL stack
//			glViewport(0,0,w(),h());		// Create a viewport 
//			glOrtho(-5,5,-5,5,-1,1);		// Create a projection
//		}
//		std::cout << "It's running." << std::endl; // Test this behavior
//		glClearColor(0.5,0,0.3,0);			// Set the background color
//		glClear(GL_COLOR_BUFFER_BIT);		// Apply the background color
//		//Rectangle
//		glColor3f(0, 1, 1);					// Set the draw color
//		glBegin(GL_QUADS);					// Draw a quad
//			glVertex3f(-1, -1, 0);
//			glVertex3f(-1, 1, 0);
//			glVertex3f(1, 1, 0);
//			glVertex3f(1, -1, 0);
//		glEnd();
//
//
//	}
//	public:
//		GlTest(int x, int y, int w, int h, char* c):Fl_Gl_Window(x, y, w, h, c){} // Constructor
//};
//
//int main (int argc, char * const argv[]) {
//   GlTest *g = new GlTest(50, 10, 700, 700, "Jan's Greatest Window"); // Create a new window to draw in
//   g->show();											  // Show this window
//   return Fl::run();									  // Start the FLTK loop
//}