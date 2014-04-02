#include "Node.h"

Node::Node()
{
	nodeName = "Root";
	transformation = gMatrix3::identity();
}

Node::Node(string name, gMatrix3 T)
{
	nodeName = name;
	transformation = T;
}

Node::Node(string name, gMatrix3 T, Geometry* g)
{
	nodeName = name;
	transformation = T;
	G = g;
}

Node::Node(Node* n)
{
	nodeName = n->nodeName;
	transformation = n->transformation;
	if (n->getGeometry() != NULL)
	{
		if (n->getGeometry()->getShape() == "triangle")
		{
			G = new Triangle((Triangle*)n->getGeometry());
		}
		else if (n->getGeometry()->getShape() == "quad")
		{
			G = new Quad((Quad*)n->getGeometry());
		}
		else if (n->getGeometry()->getShape() == "poly")
		{
			G = new Poly((Poly*)n->getGeometry());
		}
		else if (n->getGeometry()->getShape() == "lines")
		{
			G = new Lines((Lines*)n->getGeometry());
		}
		else
			cout << "Invalid shape copy" << endl;
	}
}

Node::~Node()
{
	children.clear();
	delete G;
}

string Node::getName()
{
	return nodeName;
}

list<Node*> Node::getChildren()
{
	return children;
}

Geometry* Node::getGeometry()
{
	return G;
}

void Node::transform(gMatrix3 m)
{
	//get m's x,y translate from vertices
	float x = transformation[0][2];
	float y = transformation[1][2];
	gMatrix3 translateToOrigin = gMatrix3::translation2D(-x, -y);
	gMatrix3 translateToPosition = gMatrix3::translation2D(x, y);
	//move back to origin, transform, and move back
	transformation = translateToPosition * m * translateToOrigin *  transformation;
}

void Node::translate(gMatrix3 m)
{
	transformation = m * transformation;
}

void Node::traverse(Node* N, gMatrix3 T)
{
	gMatrix3 currentT = T;
	list<Node*>::iterator child;
	for (child = children.begin(); child != children.end(); child++)
	{
		T = currentT * (*child)->transformation; //update transformation
		if ( (*child)->G != NULL ) //does the node point to a geometry?
		{
			//Yes! draw shape!
			//(*child)->print();
			(*child)->G->draw(T);	//draw with updated transformation
		}
		(*child)->traverse(*child, T);
	}
}

//construct a scene graph to build a cat like animal
void Node::buildGraph() 
{
	this->clearScene();
	Node* currentNode = this; //currentNode is root node

	//build body
	//ROOT TRANSFORMATIONS HERE --------------------
	gMatrix3 transform = gMatrix3::translation2D(-1, 2)
						* gMatrix3::rotation2D(20)
						* gMatrix3::scale2D(2, 2);
	// ----------------------------------------------
	//build shape for body-------
	list<gVector3> bodyVertices;
	bodyVertices.push_back(gVector3(-0.5, -0.5, 1));
	bodyVertices.push_back(gVector3(0.5, -0.5, 1));
	bodyVertices.push_back(gVector3(1, 0.5, 1));
	bodyVertices.push_back(gVector3(-1, 0.5, 1));
	Poly* rootBody = new Poly(bodyVertices);
	rootBody->setColor(0, 20, 50);
	//shape built----------------
	//build root transformation node
	Node* rootTransform = new Node("rootTransform", transform);
	addNode(currentNode, rootTransform);
	currentNode = *currentNode->children.begin();
	//build geometry node
	Node* Body = new Node("Body", gMatrix3::identity() , rootBody);
	addNode(currentNode, Body);
	//end body
	//current pointer at body node

	//limbs are next, lets do a head

	//build head
	//HEAD TRANSFORMATIONS --------------------
	transform = gMatrix3::translation2D(-0.8, 0.6)
				* gMatrix3::rotation2D(120)
				* gMatrix3::scale2D(0.8, 1);
	//-----------------------------------------
	Geometry* triHead = new Triangle();
	triHead->setColor(50, 0, 0);
	Node* Head = new Node("Head", transform, triHead);
	addNode(currentNode, Head);

	//add an Eye 
	transform = gMatrix3::translation2D(0.3, 0.1)
				* gMatrix3::rotation2D(-20)
				* gMatrix3::scale2D(0.16, 0.3);
	Geometry* EyeAngle = new Triangle();
	EyeAngle->setColor(0, 0.9, 0.3);
	Node* Eye = new Node("Eye", transform, EyeAngle);
	addNode(Head, Eye);
	cout << Head->children.size() << endl;
	//End Head

	//build tail
	//TAIL TRANSFORMATIONS --------------------
	transform = gMatrix3::translation2D(1, 0.5)
				* gMatrix3::rotation2D(0)
				* gMatrix3::scale2D(2, 2);
	//-----------------------------------------
	//Build shape of Tail ------
	list<gVector3> tailVertices;
	tailVertices.push_back(gVector3(0, 0, 1));
	tailVertices.push_back(gVector3(0.1, 0.1, 1));
	tailVertices.push_back(gVector3(0.2, 0.2, 1));
	tailVertices.push_back(gVector3(0.3, 0.2, 1));
	Lines* polyLine = new Lines(tailVertices);
	polyLine->setColor(0, 0, 75);
	//Tail Built ----------------
	Node* Tail = new Node("Tail", transform, polyLine);
	addNode(currentNode, Tail);
	//End Tail

	//Now to make some legs!
	//each leg with have its own rotation node to move them individually
	//just build a standard quad() and scale it to right size

	//LEG TRANSFORMATIONS --------------
	//leg1
	transform =
		gMatrix3::translation2D(-0.5, -0.5) * gMatrix3::rotation2D(170); 
	Node* leg1 = new Node("L1", transform);
	addNode(currentNode, leg1);
	//leg2
	transform =
		gMatrix3::translation2D(-0.5, -0.5) * gMatrix3::rotation2D(200);
	Node* leg2 = new Node("L2", transform);
	addNode(currentNode, leg2);
	//leg3
	transform =
		gMatrix3::translation2D(0.5, -0.5) * gMatrix3::rotation2D(160);
	Node* leg3 = new Node("L3", transform);
	addNode(currentNode, leg3);
	//leg4
	transform =
		gMatrix3::translation2D(0.5, -0.5) * gMatrix3::rotation2D(190);
	Node* leg4 = new Node("L4", transform);
	addNode(currentNode, leg4);
	//Leg Node with transformations to build it -----
	transform = gMatrix3::translation2D(0, 0.3) //make point of orgin
				* gMatrix3::rotation2D(0)
				* gMatrix3::scale2D(0.1, 0.3);
	Geometry* quadLegs = new Quad();
	quadLegs->setColor(0.3, 0.6, 0.0);
	Node* legs = new Node("Legs", transform, quadLegs);
	addNode(leg1, legs);
	addNode(leg2, legs);
	addNode(leg3, legs);
	addNode(leg4, legs);
	//End Leg Work
	//removeNode(currentNode, Head);
	//END BUILD
}

void Node::addNode(Node* parent, Node* child)
{
	parent->children.push_back(child);
}

//void Node::addNode(Node* parent, gMatrix3 T)
//{
//	Node* child = new Node(T);
//	parent->children.push_back(child);
//}

void Node::addNode(Node* parent, string s, gMatrix3 T, Geometry* g)
{
	Node* child = new Node(s, T, g);
	parent->children.push_back(child);
}

//Currently removes Node and its children
//Example, If you remove the head, the eye is removed as well.
void Node::removeNode(Node* parent, Node* child)
{
	cout << "old size: " << parent->children.size() << endl;
	parent->children.remove(child);
	cout << "removing" << endl;
	cout << "new size: " << parent->children.size() << endl;

}

void Node::clearScene()
{
	this->children.clear();
}

void Node::print()
{
	cout << "------\n\n";
	cout << nodeName << endl;
	transformation.print();
	if (G != NULL)
		G->print();
	cout << "------\n\n";
}

void Node::printAllNodes(Node* root)
{
	list<Node*>::iterator it;
	for (it = root->children.begin(); it != root->children.end(); it++)
	{
		(*it)->print();
		printAllNodes(*it);
	}
}

void Node::copyScene(Node* copy, Node* orig)
{
	//Need to traverse original scene graph,
	//while building and traversing the copy
	list<Node*>::iterator o_child;			//iterator for Orig's SceneGraph
	int count = 0;
	//make copies of children for-loop
	for (o_child = orig->children.begin(); o_child != orig->children.end(); o_child++)
	{
		Node* node_copy = new Node(*o_child);
		copy->children.push_back(node_copy);
		//cout << "kids: " << ++count << endl;
	}

	list<Node*>::iterator c_child;			//iterator for Copy's SceneGraph
	//traverse down for-loop
	for (o_child = orig->children.begin(), c_child = copy->children.begin();
		 o_child != orig->children.end() && c_child != copy->children.end();
		 o_child++, c_child++)
	{
		Node::copyScene(*c_child, *o_child);
	}
}
