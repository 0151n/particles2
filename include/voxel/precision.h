#ifndef PRECISION_H
#define PRECISION_H
#include<float.h>
namespace voxel {
	//real number precision, single or double
	typedef float real;
	#define REAL_MAX FLT_MAX
	//real_sqrt function
	#define real_sqrt sqrtf
	//real_pow function
	#define real_pow powf
}
#endif
