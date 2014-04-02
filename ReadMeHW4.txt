Brandon's Bad Cat GUI

Modeling Mode
The default mode is model mode, where you can set up your
initial scene graph.  You do this with the tree interface, where
you can add/remove nodes and shapes.  The default image is a
bad cat, I think. He's been some sort of naughty I'm sure of it,
I mean look at it's face. Anyways, you can edit any node or shape
with the widgets towards the bottom of the screen.  Be careful
with the scaling dials, they can be wacking if turned too much.
Colors can be set for each geometry using the RGB interface in
the lower left.

Animation Mode
Engage this mode by clicking the yellow model mode button, and
you will see the button turn green and change to Animation Mode.
This mode will take the image from model mode and replicate into
20 frames(a set amount for now).  You can cycle through these
frames with either the counter or the slider that appear when
this mode is turned on.  To render the current frame, simply hit
the dark green Render button in the lower right.

You can switch back to model mode, but be warned, your frames
will be lost. Model mode will use the frame 1 scene.

BUGS
There is still the blased clicking bug, that occurs sometimes
when trying to click an item of the tree. Even though it was
clicked, it may not be selected, so pay attention to the
terminal output. 

The scales are extremely touchy, as they are applying the 
rotation value of the dial to the previous value and not to the base
like it should be.