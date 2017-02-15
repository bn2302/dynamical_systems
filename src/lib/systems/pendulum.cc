#include <math.h>
#include <memory>
#include "pendulum.h"


template<typename T>
Pendulum<T>::Pendulum(T time, std::vector<T> state, T length)
  : DynamicalSystem<T>::DynamicalSystem(time, state), length(length) {}


template<typename T>
Pendulum<T>::Pendulum() :
  Pendulum::Pendulum(0.0, std::vector<T> {0, 0.1}, 1.0) {}


template<typename T>
std::vector<T> Pendulum<T>::operator()(const T time,
    const std::vector<T>& state) const{

  std::vector<T> d_state (state.size(), 0);

  d_state[0] = state[1];
  d_state[1] = -gravity_of_earth/length*sin(state[0]);

  return d_state;

}
