#ifndef EMITTER_H
#define EMITTER_H
#include<voxel/particle.h>

namespace voxel {
	class Emitter{
		public:
			int size;
			int wait;
			bool render;
			bool alive;
			voxel::Particle temp;
			float x,y,emit_x,emit_y;
			int update(int time);
			voxel::Particle emit(float x_velocity,float y_velocity);
			int setParticle(float x,float y,int size,int position,float r,float g,float b);
			
	};
}


#endif
