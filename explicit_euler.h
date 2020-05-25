#ifndef _EXPLICIT_EULER_H_
#define _EXPLICIT_EULER_H_
#include<cmath>
#include<algorithm>
#include<vector>
#include<type_traits>
#include "parameter.h"

class explicit_euler: public parameter{
	private:
		std::vector<double> u;
	public:
		explicit explicit_euler(double _dx, double _dt): parameter{_dx, _dt}{
			u.resize((int)std::pow(dx, -1));
			u[(int)std::pow(dx, -1) - 1] = 1.0;
	       	}
		explicit explicit_euler(double _dx, double _dt,double _kappa): parameter{_dx, _dt, _kappa}{
			u.resize((int)std::pow(dx, -1));
			u[(int)std::pow(dx, -1) - 1] = 1.0;
	       	}
		explicit explicit_euler(): parameter{0.001, 0.01}{
			u.resize((int)std::pow(dx, -1));
			u[(int)std::pow(dx, -1) - 1] = 1.0;
	       	}
		~explicit_euler(){}
		inline void next(void);
		inline void step_to(int);
		inline void solve(void);
};

void explicit_euler::next(void){
	decltype(u) u_tmp;
	u_tmp.resize(u.size());
	std::copy(u.begin(), u.end(), u_tmp.begin());
	/**
	 * du/dt = kappa * d^2 u / d x^2
	 * du/dt = (u^{n+1}_j - u^n_j) / delta_t
	 * d^2 u/ d x^2 = u^n_{j-1} - 2 * u^n_j + u^n_{j+1}
	 * r = kappa * dt / (dx)^2
	 * therefore
	 * u^{n+1}_j = ru^n_{j-1} - 2 u^n_j + u^n_{j+1}
	 **/
	for(int i = 1; i < u_tmp.size() - 1; i++) u_tmp[i] = courant * u[i - 1] + (1 - 2 * courant) * u[i] + courant * u[i + 1];
	std::copy(u_tmp.begin(), u_tmp.end(), u.begin());
	t += dt;
}

void explicit_euler::step_to(int n){
	for(int i = 0; i < n; i++) next();
}

void explicit_euler::solve(void){
	while(t <= 0.1) next();
}
