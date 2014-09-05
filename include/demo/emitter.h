#ifndef EMITTER_H
#define EMITTER_H
#include<voxel/particle.h>
#include<demo/fireworks.h>

namespace voxel {
	class Emitter{
		public:
			int size;
			int wait;
			bool render;
			bool alive;
			int ord;
			voxel::Particle temp;
			Firework temp_f;
			float x,y;
			int update(int time);
			voxel::Particle emit(float x_velocity,float y_velocity);
			Firework emit_f(float x_velocity,float y_velocity);
			int setParticle(float x,float y,int size,float r,float g,float b);
			int setFirework(float x,float y,int fuse,float r,float g,float b);
	};
}


#endif
