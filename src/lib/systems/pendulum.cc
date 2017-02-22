#include <math.h>
#include "pendulum.h"


Pendulum::Pendulum(double initial_time, std::vector<double> initial_state,
                   double length)
        : DynamicalSystem::DynamicalSystem(initial_time, initial_state),
          length(length) {}


Pendulum::Pendulum() :
  Pendulum::Pendulum(0.0, std::vector<double> {0, 0.1}, 1.0) {}


// Actual implementation of the dynamical system
std::vector<double> Pendulum::operator()(const double time,
                                        const std::vector<double>& state) const
{

  state;

  std::vector<double> d_state (state.size(), 0);

  d_state[0] = state[1];
  d_state[1] = -gravity_of_earth/length*sin(state[0]);

  return d_state;

}

