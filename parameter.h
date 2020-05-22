#ifndef _IMPLICIT_EULER_H_
#define _IMPLICIT_EULER_H_
/** We will determine class that includes various parameters that useful for coding implicit euler algorithm */
class parameter{
	private:
	/**
	 * In the following, We determine parameters, delta x, delta t take for exmaple.
	 * First, We want you to pay attension that this I'll code this program to solve heat transfer equation only, so other PDE, like 
	 * wave equation, poisson equation, can't solve this program. 
	 * Some paramters will be determined.We show them.
	 * double dx ... it means delta x
	 * double dt ... it means delta t
	 * double kappa ... it means thermal diffusion coefficient.However except for special case, it's often determine 1.0
	 */
		double dx;
		double dt;
	public:
		double kappa = 1.0;
		explicit parameter(double _dx, double _dt):dx(_dx), dt(_dt){}
		explicit parameter(double _dx, double _dt, double _kappa):dx(_dx), dt(_dt), kappa(_kappa){}

		double get_dx(void) const{
			return this->dx;
		}
		double get_dt(void) const{
			return this->dt;
		}
};
#endif
