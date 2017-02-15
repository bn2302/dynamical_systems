#include <math.h>
#include "double_pendulum.h"


template<typename T>
DoublePendulum<T>::DoublePendulum(T time, std::vector<T> state,
    T length1, T length2, T mass1, T mass2)
  : DynamicalSystem<T>::DynamicalSystem(time, state), length1(length1),
    length2(length2), mass1(mass1), mass2(mass2) {}


template<typename T>
DoublePendulum<T>::DoublePendulum()
  : DoublePendulum::DoublePendulum(0.0,
      std::vector<T> {0, 0.1, 0, 0.1},
      1.0, 1.0, 1.0, 1.0) {}


template<typename T>
std::vector<T> DoublePendulum<T>::operator()(const T time,
    const std::vector<T>& state) const{

  std::vector<T> d_state (state.size(), 0);

  auto total_mass = mass1 + mass2;
  auto cos_delta_phi = cos(state[0] - state[2]);
  auto sin_delta_phi = sin(state[0] - state[2]);

  d_state[0] = state[1];
  d_state[1] = (mass2*cos_delta_phi*(length1*sin_delta_phi*state[1]*state[1]
                                     -gravity_of_earth*sin(state[2]))
                + mass2*length2*sin_delta_phi*state[3]*state[3]
                +total_mass*gravity_of_earth*sin(state[0]))
            / (mass2*length1*cos_delta_phi*cos_delta_phi-total_mass*length1);

  d_state[2] = state[3];
  d_state[3] = (mass2*length2*cos_delta_phi*sin_delta_phi*state[3]*state[3]
                + total_mass*length1*sin_delta_phi*state[1]*state[1]
                + total_mass*gravity_of_earth*cos_delta_phi*sin(state[0])
                - total_mass*gravity_of_earth*sin(state[2]))
            / (total_mass*length2 - mass2*length2*cos_delta_phi*cos_delta_phi);


  return d_state;

}
