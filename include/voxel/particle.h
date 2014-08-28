#ifndef PARTICLE_H
#define PARTICLE_H

#include<voxel/core.h>
#include<voxel/precision.h>


namespace voxel{
/*simple object to be simulated by physics system*/
class Particle {
	public:
		//vector to hold linear position
		Vec3 position;
		//vector to hold linear velocity
		Vec3 velocity;
		//vector to hold acceleration of particle
		Vec3 acceleration;
		/*the amount of drag or "damping" that the 
		 *object is being subjected to
		 */
		real damping;
		//holds the inverse mass of a particle
		real inverseMass;
	        
		Vec3 forceAccum;
		//Is particle active
		bool alive = false;
		//particle color
		float red,green,blue = 1;
		//render size of particle
		int size = 2;

		//integrator for particle
		void integrate(real duration);
	
		void setColor(float red,float green,float blue);
		void setMass(const real mass);
		real getMass() const;
		void setInverseMass(const real inverseMass);
		real getInverseMass() const;
		bool hasFiniteMass() const;
		void setDamping(const real damping);
		real getDamping() const;
		void setPosition(const Vec3 &position);
		void setPosition(const real x, const real y, const real z);
		void getPosition(Vec3 *position) const;
		Vec3 getPosition() const;
		void setVelocity(const Vec3 &velocity);
		void setVelocity(const real x, const real y, const real z);
		void getVelocity(Vec3 *velocity) const;
		Vec3 getVelocity() const;
		void setAcceleration(const Vec3 &acceleration);
		void setAcceleration(const real x, const real y, const real z);
		void getAcceleration(Vec3 *acceleration) const;
		Vec3 getAcceleration() const;
		void clearAccumulator();
		void addForce(const Vec3 &force);
};
}
#endif	
