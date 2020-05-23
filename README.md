# explicit-euler
Explicit euler method may be the most simplest method in the other's.
I will tell how to solve Partial differencial equation(PDE) by explicit euler.
$\frac{\partial u}{\partial t} = c\frac{\partial^2 u}{\partial x^2}$
First,apply forward difference to time and then, $\frac{\partial u}{\partial t} \simeq \frac{u^{n+1}_j - u^n_j}{\Delta t}$.
In this case, $u^n_{j}$ means $u(t, x) = u(n, j)$.
Second, apply second-order precision central difference method to space and then, \frac{\partial^2 u}{\partial x^2} = \frac{u^n_{j-1}
