#ifndef _EXPLICIT_EULER_H_
#define _EXPLICIT_EULER_H_
#include<cmath>
#include<algorithm>
#include "parameter.h"

class explicit_euler: public parameter{
	private:
		double* u;
	public:
		explicit explicit_euler(double _dx, double _dt): parameter{_dx, _dt}{
			u = new double((int)std::pow(_dt, -1));
		}
		explicit explicit_euler(double _dx, double _dt, _kappa): parameter{_dx, _dt, _kappa}{
			u = new double((int)std::pow(_dt, -1));
		}
		explicit explicit_euler(): parameter{0.001, 0.01}{
			u = new double((int)std::pow(_dt, -1));
		}
		~explicit_euler(){
			delete[] u;
		}
		inline void next(void)const;
		inline void step_to(int)const;
		inline void solve(void)const;
};

void explicit_euler::next(void)const{
