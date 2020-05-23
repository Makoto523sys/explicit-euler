#ifndef _EXPLICIT_EULER_H_
#define _EXPLICIT_EULER_H_
#include<cmath>
#include<algorithm>
#include "parameter.h"

class explicit_euler: public parameter{
	private:
		double* u;
	public:
		inline void next(void);
		inline void;
};
