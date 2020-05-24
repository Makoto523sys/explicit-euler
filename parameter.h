#ifndef _IMPLICIT_EULER_H_
#define _IMPLICIT_EULER_H_
/** We will determine class that includes various parameters that are useful for coding explicit euler algorithm */
class parameter{
	/**
	 * In the following, We determine parameters, delta x, delta t take for exmaple.
	 * First, We want you to pay attension that this I'll code this program to solve heat transfer equation only,
	 * so other PDE, like wave equation, poisson equation, can't solve this program. 
	 * Some paramters will be determined.Show them below.
	 * double dx ... it means delta x
	 * double dt ... it means delta t
	 * double kappa ... it means thermal diffusion coefficient.However except for special case, 
	 * it's often determined 1.0
	 */
	public:
		double t = 0.0;
		double dx;
		double dt;
		double kappa = 1.0;
		double courant;
		explicit parameter(double _dx, double _dt):dx(_dx), dt(_dt){
			courant = kappa / dx * dt / dx;
		}
		explicit parameter(double _dx, double _dt, double _kappa):dx(_dx), dt(_dt), kappa(_kappa){
			courant = kappa * dt / dx;
		}

};
#endif
