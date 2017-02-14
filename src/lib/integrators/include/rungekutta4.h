#ifndef LIB_RUNGEKUTTA4_H_
#define LIB_RUNGEKUTTA4_H_


#include "integrator.h"


class RungeKutta4 : public Integrator
{
  public:

    RungeKutta4(DynamicalSystem& dynamical_system, double step_size);

    ~RungeKutta4();

  protected:

    void integrateStep();

  private:

    double step_size;

};


#endif /* ifndef LIB_ODE45_H_ */
