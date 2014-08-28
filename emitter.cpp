#include<demo/emitter.h>
#include<stdlib.h>
#include<stdio.h>
using namespace voxel;

//update method	
int Emitter::update(int time) {
	//check if it is time to create new particle
	if(time >= wait){
			return 1;
	}
	else {
			return 0;
	}
}
//emit method
voxel::Particle Emitter::emit(float x_velocity,float y_velocity){
		//return particle
		temp.setVelocity(x_velocity,y_velocity,0.0f);
		return temp;
}
//method for setting particle values
int Emitter::setParticle(float x,float y,int size,int position,float r,float g,float b){
		//set size
		temp.size = size;
		//set emit position 1 = left, 2 = right, 3 = top, 4 = bottom
		switch(position){
			case 1:
				emit_x = x - size;
				emit_y = y;
				break;
			case 2:
				emit_x = x + size;
				emit_y = y;
				break;
			case 3:
				emit_x = x;
				emit_y = y + size;
				break;
			case 4:
				emit_x = x;
				emit_y = y - size;
				break;
		}
		temp.alive = true;
		//set position values
		temp.setPosition(emit_x,emit_y,0.0f);
		//set color
		temp.setColor(r,g,b);
		temp.setMass(2.0f);
		temp.setAcceleration(0.0f,9.0f,0.0f);
		temp.setDamping(0.99f);
}
