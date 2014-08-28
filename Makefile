#voxel test makefile
all:
	g++ main.cpp -c -I./include/ -L/usr/X11R6/lib -lX11 -lXi -lXmu -lglut -lGL -lGLU -lm -o test.o
	g++ particle.cpp -c -I./include/ -o particle.o
	g++ fireworks.cpp -c -I./include/ -o firework.o
	g++ emitter.cpp -c -I./include/ -o emitter.o
	g++ test.o particle.o firework.o emitter.o -lX11 -lXi -lXmu -lglut -lGL -lGLU -lm -I./include/ -L/usr/X11R6/lib -o test
	rm *.o
	
