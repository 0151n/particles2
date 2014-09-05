particles2
==========

basic physics engine
-------

Particles 2 is a basic physics engine currently focused mainly on particles.
currently the code compiles to a demo. This demo allows for the individual 
components of the engine to be tested, and different particles are bound to 
different keys.

##Key-bindings
"1" = toggle fullscreen.

"2" = toggle random deviation of particles

"3" = toggle color

"4" = spawn particles on left click (default)

"5" = spawn fireworks on left click

"6" = spawn emitters on left click

"7" = edit velocity and direction of particles created by emitter

"8" = toggle particle emitted from emiiter (particle -> firework)

dependencies:
1. Opengl - Graphics library

2. Glut - Utilities for OpenGl

3. Xi - Input library for X
 
4. Xmu - mouse input library for X

5. X11 - X11 library

##Compilation
Due to its dependence on linux librarys (e.g. Xi,Xmu,X11), the engine is 
currently only compileable on linux. And can be done so with the supplied Makefile.

