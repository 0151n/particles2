#ifndef FIREWORKS_H
#define FIREWORKS_H

#include<voxel/core.h>
#include<voxel/precision.h>
#include<voxel/particle.h>

  class Firework : public voxel::Particle{
          public:
                  unsigned age;
                  unsigned fuse;
                  Particle sub[10];
                  
                  int update(float par1);
		  int explode(voxel::Particle *particles,int index,bool def,int num);
};
#endif
