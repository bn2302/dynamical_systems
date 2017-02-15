#include "rungekutta4.h"


template<typename T>
RungeKutta4<T>::RungeKutta4(DynamicalSystem<T> &sys, T step_size)
  : Integrator<T>::Integrator(sys), step_size(step_size) {}


template<typename T>
RungeKutta4<T>::~RungeKutta4() {};


template<typename T>
void RungeKutta4<T>::integrateStep() {

  auto time =  dynamical_system.getTime();

  auto state = dynamical_system.getState();

  auto k1 = dynamical_system(time, state);

  auto k2 = dynamical_system(time+0.5*step_size,
      add_vectors(state, multiply_by_scalar(k1, 0.5*step_size)));

  auto k3 = dynamical_system(time+0.5*step_size,
      add_vectors(state, multiply_by_scalar(k2, 0.5*step_size)));

  auto k4 = dynamical_system(time+step_size,
      add_vectors(state, multiply_by_scalar(k3, step_size)));

  for (auto it = state.begin(); it != state.end(); ++it) {

    int index = std::distance(state.begin(), it);

    *it += step_size/6*k1[index] + step_size/3*k2[index]
      + step_size/3*k3[index] + step_size/6*k4[index];

  }

  dynamical_system.setState(state);

  dynamical_system.setTime(time+step_size);

}
