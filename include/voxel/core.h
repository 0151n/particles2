#ifndef CORE_H
#define CORE_H
#include <voxel/precision.h>
#include <math.h>

namespace voxel {
	/*----three dimensional vector class----
	 *----four word aligned----*/
	// extern real sleepEpsilon;
	// void setSleepEpsilon(real value);
	// real getSleepEpsilon();

	class Vec3 {
		public:
			//x value of vector
			real x;
			//y value of vector
			real y;
			//z value of vector
			real z;
		private:
			//padding for four word alignment
			real pad;
		public:
			//default constructor
			Vec3() : x(x), y(y), z(z) {}
			//explicit constructor
			Vec3(const real x,const real y, const real z) : x(x), y(y), z(z) {}
			//invert all elements
			void invert()
			{
				x -= x;
				y -= y;
				z -= z;
			}
			//Get magnitude
			real magnitude() const {
				return real_sqrt(x*x+y*y+z*z);
			}
			//Get squared magnitude
			real squareMagnitude() const {
				return x*x+y*y+z*z;
			}
			//Creat a unit vector from a non unit vector
			void normalise(){
				real l = magnitude();
				 if(l > 0){
					(*this) *= ((real)1)/l;
				}
			}
			      /** Limits the size of the vector to the given maximum. */
			void trim(real size)
			{
			    if (squareMagnitude() > size*size)
			    {
				normalise();
				x *= size;
				y *= size;
				z *= size;
			    }
			}
			Vec3 unit() const
			{
			    Vec3 result = *this;
			    result.normalise();
			    return result;
			}

			/** Checks if the two vectors have identical components. */
			bool operator==(const Vec3& other) const
			{
			    return x == other.x &&
				y == other.y &&
				z == other.z;
			}

			//overloading *= operator to multipy vector and scalar
			void operator*=(const real value){
				x *= value;
				y *= value;
				z *= value;
			}
			bool operator!=(const Vec3& other) const
			{
				return !(*this == other);
			}

			//same as above but with *
			Vec3 operator*(const real value) const{
				return Vec3(x*value,y*value,z*value);
			}
			//overloading the += operator to add two vectors 
			void operator+=(const Vec3& v){
				x += v.x;
				y += v.y;
				z += v.z;
			}
			//same as above but with +
			Vec3 operator+(const Vec3& v) const{
				return Vec3(x+v.x,y+v.y,z+v.z);
			}
			//overloading the -= operator to subtract two vectors 
			void operator-=(const Vec3& v){
				x -= v.x;
				y -= v.y;
				z -= v.z;
			}
			//same as above but with -
			Vec3 operator-(const Vec3& v) const{
				return Vec3(x-v.x,y-v.y,z-v.z);
			}
			//add the given vector to this, scaled by a given amount
			void addScaledVector(const Vec3& vector, real scale){
				x += vector.x * scale;
				y += vector.y * scale;
				z += vector.z * scale;
			}
			//returns compnent product as vector
			Vec3 componentProduct(const Vec3 &vector) const{
				return Vec3(x * vector.x,y * vector.y,z * vector.z);
			}
			//*= component product
			Vec3 componentProductUpdate(const Vec3 &vector){
				x *= vector.x;
				y *= vector.y; 			
				z *= vector.z;
			}
			//scalar product
			real scalarProduct(const Vec3 &vector) const{
				return x*vector.x + y*vector.y + z*vector.z;
			}
			//scalar product
			real operator*(const Vec3 & vector) const{
				return x*vector.x + y*vector.x + z*vector.z;
			}
			//vector product
			Vec3 vectorProduct(const Vec3 &vector) const{
				return Vec3(y*vector.z-z*vector.y,
				       z*vector.x-x*vector.z,
				       x*vector.y-y*vector.x);
			}
			void operator%=(const Vec3 &vector){
				*this = vectorProduct(vector);
			}
			Vec3 operator%(const Vec3 &vector){
				return Vec3(y*vector.z-z*vector.y,
				       z*vector.x-x*vector.z,
				       x*vector.y-y*vector.x);
			}
	bool operator<(const Vec3& other) const
        {
            return x < other.x && y < other.y && z < other.z;
        }

        /**
         * Checks if this vector is component-by-component less than
         * the other.
	*/
        bool operator>(const Vec3& other) const
        {
            return x > other.x && y > other.y && z > other.z;
        }

        /**
         * Checks if this vector is component-by-component less than
         * the other.
         */
        bool operator<=(const Vec3& other) const
        {
            return x <= other.x && y <= other.y && z <= other.z;
        }

        /**
         * Checks if this vector is component-by-component less than other
         */
        bool operator>=(const Vec3& other) const
        {
            return x >= other.x && y >= other.y && z >= other.z;
        }

        /** Zero all the components of the vector. */
        void clear()
        {
            x = y = z = 0;
        }

	};
}
#endif
