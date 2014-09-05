#ifndef FIREWORKS_H
#define FIREWORKS_H

#include <voxel/core.h>
#include <voxel/precision.h>
#include <voxel/particle.h>
#include <stdlib.h>

  class Firework : public voxel::Particle{
          public:
                  unsigned age;
                  unsigned fuse;
                  Particle sub[20];
                  
                  int update(float par1);
		  int explode(voxel::Particle *particles,int index,bool def,int num);
		  int setParticle(int part,int x_vel,int y_vel,int size,float r,float g,float b);
};
#endif
