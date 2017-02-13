#ifndef LIB_INTEGRATOR_H_
#define LIB_INTEGRATOR_H_

#include <memory>
#include "dynamical_system.h"

class Integrator
{
  public:
    Integrator(DynamicalSystem& dynamical_system);
    virtual ~Integrator() = 0;
    void integrateNSteps(int n);

  protected:
    DynamicalSystem& dynamical_system;
    virtual void integrateStep() = 0;

};


#endif /* ifndef LIB_INTEGRATOR_H_ */
