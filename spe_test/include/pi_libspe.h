#ifndef PI_LIBSPE_H_
#define PI_LIBSPE_H_
	#include<stdint.h>
	
	typedef struct{
		float value;
		uint64_t rounds;
		uint64_t seed;
		char reserved[4];
	}spe_par_t;
	
#endif /*PI_LIBSPE_H_*/
