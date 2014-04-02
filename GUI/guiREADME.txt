Brandon Shea
CS351 HW3
March 05, 2014

Guide
Select nodes using the tree widget. When a node is selected, you may change its
transformation values with the widgets on the bottom of the screen to translate,
scale, and rotate.  On the left side are several buttons to add a node as a child
of the presently selected node.  Press a button with a shape title to insert a
geometry.  Add node only inserta node with a transformation with no geometry.  
Remove will delete the presently selected node if it is a leaf(aka has no children).
PrintAll will print all the nodes in the scene graph with their transformation
values.  The buttons in the lower right of the screen, allow the user to exit, reset
to the default scene graph (a cat-like creature), and clear the current scene graph
and tree.  Right now, the color widget in the lower left is not working.  The idea is
to allow the user to change the color of the current node's geometry if it has one.


Difficultites: 
BUGS:
1. Sometimes clicking a node in the tree does not select the node and still has the 
previous node selected. I'm not sure why this happens. I set item equal to
Fl_Tree->item_clicked().
2. Color widget doesn't work. When I assign it the rgb values of the current node,
it doesn't allow me to interact with it.  Redrawing the GUI_Win Class doesn't seem
to redraw the color widget, like it could be its own window.
3. In the original Scene graph, certain parts of the cat, such as the head, do not
alwasy translate across the right axis, often across. It works fine for objects
created in the gui.
Choices:
Why did I use Fl_Tree -_-  . I probably should have used the code provided. The 
Fl_Tree class uses Fl_Tree_Items which have a void* type variable. I use this variable
to assign pointers to my nodes of my scene graph. Unfortuently this results in lots
of casting. I don't quite understand the mechanics of the color widget.