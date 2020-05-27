#ifndef _EXPLICIT_EULER_H_
#define _EXPLICIT_EULER_H_
#include<cmath>
#include<algorithm>
#include<vector>
#include<type_traits>
#include "parameter.h"

class explicit_euler: public parameter{
	public:
		std::vector<double> u;
		std::vector<double> u_tmp;
		explicit explicit_euler(double _nx, double _dt): parameter{_nx, _dt}{
			u.resize(nx);
			u_tmp.resize(nx);
			u[nx - 1] = 1.0;
			u_tmp[nx - 1] = 1.0;
	       	}
		explicit explicit_euler(double _nx, double _dt,double _kappa): parameter{_nx, _dt, _kappa}{
			u.resize(nx);
			u_tmp.resize(nx);
			u[nx - 1] = 1.0;
			u_tmp[nx - 1] = 1.0;
	       	}
		explicit explicit_euler(): parameter{21, 1e-3}{
			u.resize(nx);
			u_tmp.resize(nx);
			u[nx - 1] = 1.0;
			u_tmp[nx - 1] = 1.0;
	       	}
		~explicit_euler(){}
		inline void next(void);
		inline void step_to(int);
		inline void solve(void);
		inline bool is_end(void);
};

bool  explicit_euler::is_end(void){
	return std::fabs(t - limt) < 1e-4;
}

void explicit_euler::next(void){
	if(is_end()){
		std::cout << "All step have finished" << std::endl;
		return;
	}
	/**
	 * du/dt = kappa * d^2 u / d x^2
	 * du/dt = (u^{n+1}_j - u^n_j) / delta_t
	 * d^2 u/ d x^2 = u^n_{j-1} - 2 * u^n_j + u^n_{j+1}
	 * r = kappa * dt / (dx)^2
	 * therefore
	 * u^{n+1}_j = ru^n_{j-1} - 2 u^n_j + u^n_{j+1}
	 **/
	std::cout << -1;
	for(int i = 1; i < u_tmp.size() - 1; i++) 
		u_tmp[i] = u[i] + courant * (u[i + 1] - 2 * u[i] + u[i - 1]);
		//u_tmp[i] = u[i] + (dt * kappa / (dx * dx)) * (u[i + 1] - 2 * u[i] + u[i - 1]);
		//u_tmp[i] = u[i] + dt * kappa * (u[i + 1] - 2 * u[i] + u[i - 1]) / (dx * dx);
	std::copy(u_tmp.begin() + 1, u_tmp.end() - 1, u.begin() + 1);
	t += dt;
}

void explicit_euler::step_to(int n){
	for(int i = 0; i < n; i++) next();
}

void explicit_euler::solve(void){
	while(t <= limt) next();
}
#endif
