#include <math.h>
#include "pendulum.h"

Pendulum::Pendulum(double time, std::vector<double> state,double length)
  : DynamicalSystem::DynamicalSystem(time, state) {
  this->length = length;
}

std::vector<double> Pendulum::right_hand_side(const double time,
    const std::vector<double>& state) const{

  std::vector<double> d_state {0, 0};

  d_state[0] = state[1];
  d_state[1] = -gravity_of_earth/length*sin(state[0]);

  return d_state;

}
