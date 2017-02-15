#include <math.h>
#include "double_pendulum.h"

DoublePendulum::DoublePendulum(double time, std::vector<double> state,
    double length1, double length2, double mass1, double mass2)
  : DynamicalSystem::DynamicalSystem(time, state), length1(length1),
    length2(length2), mass1(mass1), mass2(mass2) {}

DoublePendulum::DoublePendulum()
  : DoublePendulum::DoublePendulum(0.0,
      std::vector<double> {0, 0.1, 0, 0.1},
      1.0, 1.0, 1.0, 1.0) {}


std::vector<double> DoublePendulum::operator()(const double time,
    const std::vector<double>& state) const{

  // state is phi1 dphi1 phi2 dphi2

  std::vector<double> d_state (state.size(), 0);

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
