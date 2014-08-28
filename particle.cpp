#include<assert.h>
#include<voxel/particle.h>

using namespace voxel;

void Particle::integrate(real duration){
	//things with infinite mass are not integrated
	if (inverseMass <= 0.0f) return;

	assert(duration > 0.0);
	//update linear position
	position.addScaledVector(velocity,duration);
	//acceleration from force 
	Vec3 resultingAcc = acceleration;
	//update linear velocity from acceleration
	velocity.addScaledVector(resultingAcc, duration);
	//impose drag
	velocity *= real_pow(damping, duration);
	//clear forces
	clearAccumulator();
}
void Particle::setMass(const real mass)
{
    assert(mass != 0);
    Particle::inverseMass = ((real)1.0)/mass;
}

real Particle::getMass() const
{
    if (inverseMass == 0) {
        return REAL_MAX;
    } else {
        return ((real)1.0)/inverseMass;
    }
}
void Particle::setColor(float in_red,float in_green,float in_blue){
	red = in_red;
	green = in_green;
	blue = in_blue;
}
void Particle::setInverseMass(const real inverseMass)
{
    Particle::inverseMass = inverseMass;
}

real Particle::getInverseMass() const
{
    return inverseMass;
}

bool Particle::hasFiniteMass() const
{
    return inverseMass >= 0.0f;
}

void Particle::setDamping(const real damping)
{
    Particle::damping = damping;
}

real Particle::getDamping() const
{
    return damping;
}

void Particle::setPosition(const Vec3 &position)
{
    Particle::position = position;
}

void Particle::setPosition(const real x, const real y, const real z)
{
    position.x = x;
    position.y = y;
    position.z = z;
}

void Particle::getPosition(Vec3 *position) const
{
    *position = Particle::position;
}

Vec3 Particle::getPosition() const
{
    return position;
}

void Particle::setVelocity(const Vec3 &velocity)
{
    Particle::velocity = velocity;
}

void Particle::setVelocity(const real x, const real y, const real z)
{
    velocity.x = x;
    velocity.y = y;
    velocity.z = z;
}

void Particle::getVelocity(Vec3 *velocity) const
{
    *velocity = Particle::velocity;
}

Vec3 Particle::getVelocity() const
{
    return velocity;
}

void Particle::setAcceleration(const Vec3 &acceleration)
{
    Particle::acceleration = acceleration;
}

void Particle::setAcceleration(const real x, const real y, const real z)
{
    acceleration.x = x;
    acceleration.y = y;
    acceleration.z = z;
}

void Particle::getAcceleration(Vec3 *acceleration) const
{
    *acceleration = Particle::acceleration;
}

Vec3 Particle::getAcceleration() const
{
    return acceleration;
}

void Particle::clearAccumulator()
{
    forceAccum.clear();
}

void Particle::addForce(const Vec3 &force)
{
    forceAccum += force;
}
