Brandon Shea
Assignment 02 Scene Graph
CS351

Using one grace day please!

Primitive Objects available: {Quad, Triangle, Lines(Polylines), Poly(Polygons)}
	Each of the primitives inherits from Geometry. The parent class provides a 
	blueprint for each one, providing methods to setColor, print, and a Pure
	virtual method to draw. Each has fields for color RGB values and a list of
	vertices. Currently, the transform method is not used since it permently 
	changes the vertices of a Geometry.  Each Primitive has its own Draw().

Nodes
	This class is the main structure of the scene graph.  Nodes have a list of
	children which can be traversed to draw the image.  Methods are provided to
	add nodes based on different parameters.  BuildGraph() sets up the current
	Node as the root and sets up branches and children to draw a cat-like
	creature.  Inside the buildGraph() is where you can manipulate the different
	parts of the cat, such as rotating the head or translating the entire body.
	The comments in the code document where each part is handled.  I decided to
	only have one geometry for leg, and just diffent transformation nodes
	pointing to it. Currently, removeNode() deletes the node and its children.
	Say for example you remove the head, the eye will be removed as well.

GL Window
	I mainly use the gl example from class with a few tweaks to work for this
	assignment. A Node is passed in as a parameter when building, which should
	be treated as the root node with an Identity matrix. 

Character
	Is a cat-like creature. The limbs can all move independently and are all
	parented to body.	

Known Bugs:
	1. Not sure if everything is properly deleted.