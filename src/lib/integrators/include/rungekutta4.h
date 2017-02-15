#ifndef LIB_RUNGEKUTTA4_H_
#define LIB_RUNGEKUTTA4_H_


#include "integrator.h"

template <typename T>
class RungeKutta4 : public Integrator<T>
{

  public:

    RungeKutta4(DynamicalSystem<T> &sys, T step_size);

    ~RungeKutta4();

  protected:

    void integrateStep();

  private:

    T step_size;

    using Integrator<T>::dynamical_system;

    using Integrator<T>::add_vectors;

    using Integrator<T>::multiply_by_scalar;

};

template class RungeKutta4<float>;

template class RungeKutta4<double>;


#endif /* ifndef LIB_ODE45_H_ */
