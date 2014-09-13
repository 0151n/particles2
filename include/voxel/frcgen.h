/*
 * Force generator
 */
#include<voxel/precision.h>
#include<voxel/particle.h>
class ParticleForceGenerator
{
	//interface due to be overloaded to update force
	virtual void updateForce(Particle *particle, real duration) = 0;
};
