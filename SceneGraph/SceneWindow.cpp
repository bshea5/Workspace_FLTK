#include "SceneWindow.h"

//draw method is called here with scene graph

SceneWindow::SceneWindow(int x, int y, int w, int h, char* c)
:Fl_Gl_Window(x, y, w, h, c) // Constructor
{
	//root = n;
	root->buildGraph();
	name = c;
}

//clone a scene and its changes
SceneWindow::SceneWindow(SceneWindow* s, string n)
:Fl_Gl_Window(s->x(), s->y(), s->w(), s->h(), s->label())
{
	root = new Node(s->root);
	Node::copyScene(root, s->root);
	name = n;
}

SceneWindow::~SceneWindow()
{
	frames.clear();
	delete(root);
	root = NULL;
}

//build a list of scene graphs based off original root
void SceneWindow::buildFrames(int n)
{
	frames.push_back(root);
	for (int i = 1; i < n; i++)	//make clones of root and put into frames
	{
		Node* clone = new Node(root);
		Node::copyScene(clone, root);
		frames.push_back(clone);
	}
}

//switch to frame at index of n
void SceneWindow::switchToFrame(int n)
{
	if (n > frames.size())
		return;
	list<Node*>::iterator frame;
	int i = 0;
	for (frame = frames.begin(), i = 0; i < n; i++)
	{
		frame++;
	}
	cout << "frame " << i << endl;
	root = *frame;
	redraw();
}

void SceneWindow::clearFrames()
{
	root = new Node(*frames.begin());
	Node::copyScene(root, *frames.begin());
	frames.clear();
	redraw();
}

void SceneWindow::resetWindow()
{
	glClearColor(0, 0, 0, 0);		// set the background color
	glClear(GL_COLOR_BUFFER_BIT);  // clear the window with the background color
}

void SceneWindow::draw()
{							// Override the draw method
	if (!valid()){						// Some housekeeping
		valid(1);
		glLoadIdentity();					// Prepare the OpenGL stack
		glViewport(0, 0, w(), h());			// Create a viewport 
		glOrtho(-5, 5, -5, 5, -1, 1);		// Create a projection
	}
	//std::cout << "It's running." << std::endl; // Test this behavior
	glClearColor(0, 0, 0, 0);				// Set the background color
	glClear(GL_COLOR_BUFFER_BIT);			// Apply the background color

	//make a coordinate grid
	glColor3f(50, 50, 50);
	glBegin(GL_LINES);
		glVertex3f(-10, 0, 1);
		glVertex3f(10, 0, 1);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(0, -10, 1);
		glVertex3f(0, 10, 1);
	glEnd();

	root->traverse(root, gMatrix3::identity());
}

void SceneWindow::renderDraw()
{
	draw();
	//get code from posted example
	//////////////////////////////////////////////////////////
	// ASSIGNMENT 4: FLIP BOOK
	// Code for outputing FL_GL_Window to a jpeg file!!!
	static int count = 0;	// keep counting the number of files
	std::string s;
	std::stringstream out;	// a stream for outputing to a string
	out << count++;			// make the current count into a string
	s = out.str();
	std::string filename = "anim\\testing_" + s + ".jpg";	// compose the file name

	// Make the BYTE array, factor of 3 because it's RBG.
	int width = 500; int height = 500;
	BYTE* pixels = new BYTE[3 * width * height];

	glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	struct jpeg_compress_struct cinfo;
	struct jpeg_error_mgr jerr;

	/* this is a pointer to one row of image data */
	JSAMPROW row_pointer[1];
	FILE *outfile = NULL;
	fopen_s(&outfile, filename.c_str(), "wb");

	if (!outfile)
	{
		std::cout << "Error opening output jpeg file:" << filename << std::endl;
		return;
	}
	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_compress(&cinfo);
	jpeg_stdio_dest(&cinfo, outfile);

	/* Setting the parameters of the output file here */
	cinfo.image_width = width;
	cinfo.image_height = height;
	cinfo.input_components = 3;		// bytes_per_pixel;
	cinfo.in_color_space = JCS_RGB; // color_space;
	/* default compression parameters, we shouldn't be worried about these */
	jpeg_set_defaults(&cinfo);
	/* Now do the compression .. */
	jpeg_start_compress(&cinfo, TRUE);
	/* like reading a file, this time write one row at a time */
	while (cinfo.next_scanline < cinfo.image_height)
	{
		row_pointer[0] = &pixels[cinfo.next_scanline * cinfo.image_width *  cinfo.input_components];
		jpeg_write_scanlines(&cinfo, row_pointer, 1);
	}
	/* similar to read file, clean up after we're done compressing */
	jpeg_finish_compress(&cinfo);
	jpeg_destroy_compress(&cinfo);
	fclose(outfile);

	delete[] pixels;
	/////////////////////////////////////////////////////////////////////
}

void SceneWindow::setRoot(Node* r)
{
	root = r;
}

Node* SceneWindow::getRoot()
{
	return root;
}

string SceneWindow::getName()
{
	return name;
}