#include<demo/emitter.h>
#include<stdlib.h>
#include<stdio.h>
using namespace voxel;

//update method	
int Emitter::update(int time) {
	//check if it is time to create new particle
	if(time >= wait)return 1;
	else return 0;
}
//emit methods
voxel::Particle Emitter::emit(float x_velocity,float y_velocity){
	return temp;
}
Firework Emitter::emit_f(float x_velocity,float y_velocity){
	return temp_f;
}
//method for setting particle values
int Emitter::setParticle(float x,float y,int size,float r,float g,float b){
		//set size
		temp.size = size;	
		temp.alive = true;
		//set position values
		temp.setPosition(x,y,0.0f);
		//set color
		temp.setColor(r,g,b);
		temp.setMass(2.0f);
		temp.setAcceleration(0.0f,9.0f,0.0f);
		temp.setDamping(0.99f);
}
//method for setting particle values
int Emitter::setFirework(float x,float y,int fuse,float r,float g,float b){
		//set fuse
		temp_f.fuse = fuse;	
		temp_f.alive = true;
		//set position values
		temp_f.setPosition(x,y,0.0f);
		//set color
		temp_f.setColor(r,g,b);
		temp_f.setMass(2.0f);
		temp_f.setAcceleration(0.0f,9.0f,0.0f);
		temp_f.setDamping(0.99f);
		temp_f.age = 0;
}
