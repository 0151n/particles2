#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <voxel/particle.h>
#include <demo/fireworks.h>
#include <demo/emitter.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <time.h> 
#include <unistd.h>

//particle array
voxel::Particle particles[1000];
//fireworks array
Firework fireworks[100];
//emitter array
voxel::Emitter emitters[10];
//state of fullscreen
int fullscreen = 1;
//indexes for arrays
int i,index,f_index,e_index = 0;
//time per frame. 30 = fps
int f_time = 1000000 / 30;
int window;
//state of buttons
bool left,right = false; 
//particle deviation
bool devi = false;
//particle color
bool fire,emit,edit = false;
bool part = true;
bool colors = false;
float red,green,blue;
int ran;
//timing variables
int timeSinceStart,dtime,OldTimeSinceStart,padding = 0;
int framenum;
//mouse variables
int mbutton,mstate,mx,my = 0;
//emitter edit funcitons
int selected = 0;
int a,b;
float x_vel,y_vel = 0;
float angle,c;
//functions	
void update();

//opengl initialization
void init(void) 
{
  glViewport(0,0,640,480);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D( 0, 640, 480, 0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glPushAttrib( GL_DEPTH_BUFFER_BIT | GL_LIGHTING_BIT );
  glDisable( GL_DEPTH_TEST );
  glDisable( GL_LIGHTING );
}

//display functions
void display(void)
{
   update();
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   for(i = 0;i < 1000;i++){
		if(particles[i].alive == true){
			if(colors)glColor3f(particles[i].red,particles[i].green,particles[i].blue);
			if(!colors)glColor3f(1.0f,1.0f,1.0f);
			glBegin(GL_QUADS);
				glVertex2f(particles[i].getPosition().x - particles[i].size,particles[i].getPosition().y - particles[i].size);
				glVertex2f(particles[i].getPosition().x + particles[i].size,particles[i].getPosition().y - particles[i].size);
				glVertex2f(particles[i].getPosition().x + particles[i].size,particles[i].getPosition().y + particles[i].size);
				glVertex2f(particles[i].getPosition().x - particles[i].size,particles[i].getPosition().y + particles[i].size);
			glEnd();
		}
	}
	for(i = 0;i < 100;i++){
			if(fireworks[i].alive == true){
				if(colors)glColor3f(fireworks[i].red,fireworks[i].green,fireworks[i].blue);
				if(!colors)glColor3f(1.0f,1.0f,1.0f);
				glBegin(GL_TRIANGLES);
					glVertex2f(fireworks[i].getPosition().x - fireworks[i].size,fireworks[i].getPosition().y - fireworks[i].size);
					glVertex2f(fireworks[i].getPosition().x + fireworks[i].size,fireworks[i].getPosition().y -fireworks[i].size);
					glVertex2f(fireworks[i].getPosition().x,fireworks[i].getPosition().y + fireworks[i].size);
				glEnd();
			}
	}
	if(edit || emit){
	for(i = 0;i < 10;i++){
			if(emitters[i].alive && emitters[i].render){
				glColor3f(0.5f,0.5f,0.5f);
				glBegin(GL_QUADS);
					glVertex2f(emitters[i].x - 4,emitters[i].y - 4);
					glVertex2f(emitters[i].x + 4,emitters[i].y - 4);
					glVertex2f(emitters[i].x + 4,emitters[i].y + 4);
					glVertex2f(emitters[i].x - 4,emitters[i].y + 4);
				glEnd();
			}
	}
			glLineWidth(2.5);
			glColor3f(1.0, 0.0, 0.0);
			glBegin(GL_LINES);
				glVertex2f(emitters[selected].x, emitters[selected].y);
				glVertex2f(mx,my);
			glEnd();
			glLineWidth(1.0);
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_LINES);
				glVertex2f(emitters[selected].x - 4, emitters[selected].y - 4);
				glVertex2f(emitters[selected].x + 4, emitters[selected].y - 4);
				
				glVertex2f(emitters[selected].x + 4, emitters[selected].y - 4);
				glVertex2f(emitters[selected].x + 4, emitters[selected].y + 4);
				
				glVertex2f(emitters[selected].x + 4, emitters[selected].y + 4);
				glVertex2f(emitters[selected].x - 4, emitters[selected].y + 4);
				
				glVertex2f(emitters[selected].x - 4, emitters[selected].y + 4);
				glVertex2f(emitters[selected].x - 4, emitters[selected].y - 4);
			glEnd();
	}
	//draw screen
	glutSwapBuffers();

	//timing code
	//start time
	timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	//find difference between old and new time
	dtime = timeSinceStart - OldTimeSinceStart;
	//make new old time since start
	OldTimeSinceStart = timeSinceStart;
	//"debug code for time:" std::cout << "time:" << dtime << std::endl;
	//find the remaning time in the frame
	padding = f_time - dtime;
	//count frames within a second
	if(framenum == 30)framenum = 0;
	framenum++;
	//sleep for rest of frame
	usleep(padding);
}
void keyPressed(unsigned char key, int x, int y) 
{
	
    /* avoid thrashing this procedure */
    usleep(10000);

    /* If escape is pressed, kill everything. */
    if (key == 27) 
    { 
	/* shut down our window */
	glutDestroyWindow(window); 
	/* exit the program...normal termination. */
	exit(0);
    }
	//the 1 key to enter full screen mode
	if(key == 49){
		if(fullscreen == 0){
			glutReshapeWindow(640, 480);
			fullscreen = 1;
		}
		else if(fullscreen == 1){
			glutFullScreen();
			fullscreen = 0;
		}
	}
	if(key == 50 && !devi){
		devi = true;
	}
	else if(key == 50 && devi){
		devi = false;
	}
	if(key == 51 && !colors){
		colors = true;
	} 
	else if(key == 51 && colors){
		colors = false;
	}
	if(key == 52 && !part){
		part = true;
		fire = false;
		emit = false;
		edit = false;
	} 
	else if(key == 52 && part){
		part = false;
	}
	if(key == 53 && !fire){
		fire = true;
		part = false;
		emit = false;
		edit = false;
	} 
	else if(key == 53 && fire){
		fire = false;
	}
	if(key == 54 && !emit){
		emit = true;
		part = false;
		fire = false;
		edit = false;
	} 
	else if(key == 54 && emit){
		emit = false;
	}
	if(key == 55 && !edit){
		edit = true;
		emit = false;
		part = false;
		fire = false;
	} 
	else if(key == 55 && edit){
		edit = false;
	}
	if (key == 46 && selected < e_index)
	{
		selected++;
		mx = emitters[selected].temp.getPosition().x;
		my = emitters[selected].temp.getPosition().y;
	}
	if (key == 44 && selected > -1)
	{
		selected--;
		mx = emitters[selected].temp.getPosition().x;
		my = emitters[selected].temp.getPosition().y;
	}
	if(key == 56 && edit && emitters[selected].ord == 0){
			emitters[selected].ord = 1;
	}
	else if(key == 56 && edit && emitters[selected].ord == 1){
			emitters[selected].ord = 0;
	}
}
void mouse(int button,int state,int x,int y){
	mx = x;
	my = y;
	if(button == GLUT_LEFT_BUTTON){
		if(state == GLUT_DOWN){
			left = true;
		}
		else {
			left = false;
		}
	}
	if(button == GLUT_RIGHT_BUTTON){
		if(state == GLUT_DOWN){
			right = true;
		}
		else {
			right = false;
		}
	}
}
void motion(int x, int y)
{
	mx = x;
	my = y;
}
void update(){
	if(left){
		if(part) {
			if(framenum % 1 == 0){
				ran = rand() % 15 + (-5);
				particles[index].alive = true;
				particles[index].setPosition(mx,my,0.0f);
				if(devi)particles[index].setVelocity((float)ran,0.0f,0.0f);
				if(!devi)particles[index].setVelocity(0.0f,0.0f,0.0f);
				index++;	
			}
		}
		if(fire){
			if(framenum % 5 == 0){
				fireworks[f_index].alive = true;
				fireworks[f_index].setPosition(mx,my,0.0f);
				fireworks[f_index].setVelocity(100.0f,-100.0f,0.0f);
				fireworks[f_index].fuse = 30;
				fireworks[f_index].age = 0;
				f_index++;
			}
		}
		if(emit){
			//if(framenum % 10 == 0){
				emitters[e_index].x = mx;
				emitters[e_index].y = my;
				emitters[e_index].wait = 30;
				emitters[e_index].alive = true;
				emitters[e_index].render = true;
				emitters[e_index].setParticle(mx,my,2,0.5f,1.0f,0.0f);
				emitters[e_index].setFirework(mx,my,60,0.1f,5.0f,0.0f);
				e_index++;
				usleep(100000);
		}
		if(edit){
			//edit calculations
				a = mx - emitters[selected].x;
				b = my - emitters[selected].y;
				c = sqrt((a * a) + (b * b));
				x_vel = 0 - (a / 10) * c;
				y_vel = 0 - (b / 10) * c;
				emitters[selected].temp.setVelocity(x_vel,y_vel,0.0f);
				emitters[selected].temp_f.setVelocity(x_vel,y_vel,0.0f);
		}
	}
	for(i = 0;i < 1000;i++){
		if(particles[i].alive == true){
			if(particles[i].getPosition().y >= 480)particles[i].alive = false;
			else particles[i].integrate(0.1f);
		}
	}
	if(index >= 998)index = 0;
	for(i = 0;i < 100;i++){
		if(fireworks[i].alive == true){
			if(fireworks[i].getPosition().y >= 480)fireworks[i].alive = false;
			
			if(fireworks[i].update(0.1f)){
				if(index >= 991)index = 0;
				index = fireworks[i].explode(particles,index,true,8);
			}

		}
	}
	if(f_index >= 99)f_index = 0;
	
	for(i = 0;i < 10;i++){
		if(emitters[i].alive == true){
			if(emitters[i].update(framenum)){
					if (emitters[i].ord == 0)
					{			
						particles[index] = emitters[i].emit(0,0);
						index++; 	
					}
					if (emitters[i].ord == 1)
					{			
						fireworks[f_index] = emitters[i].emit_f(0,0);
						f_index++; 	
					}
			}
		}
	}

}
int main(int argc, char** argv)
{
	//initialization of particles
	for(i = 0;i < 1000;i++){
		//random colors
		green = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		blue = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		red = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		ran = (rand() % 3) + 1;
		particles[i].setColor(red,green,blue);
		particles[i].setMass(2.0f);
		particles[i].size = ran;
		particles[i].setVelocity(0.0f,0.0f,0.0f);
		particles[i].setAcceleration(0.0f,9.0f,0.0f);
		particles[i].setDamping(0.99f);
	}
	//initialization of fireworks
	for(i = 0;i < 100;i++){
		fireworks[i].setMass(2.0f);
		fireworks[i].setVelocity(5.0f,-10.0f,0.0f);
		fireworks[i].setAcceleration(0.0f,9.0f,0.0f);
		fireworks[i].setDamping(0.99f);
	}
	
	srand(time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (640, 480); 
	glutInitWindowPosition (0,0);
	window = glutCreateWindow("particles demo");
	init ();
	glutDisplayFunc(display); 
	//glutFullScreen();
	glutIdleFunc(display);
	glutKeyboardFunc(&keyPressed);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutMainLoop();
	return 0;
}
