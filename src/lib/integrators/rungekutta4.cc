#include <algorithm>
#include <functional>

#include "rungekutta4.h"

RungeKutta4::RungeKutta4(DynamicalSystem& dynamical_system, double h) :
  Integrator::Integrator(dynamical_system), h(h) {}

RungeKutta4::~RungeKutta4() {};

void RungeKutta4::integrateStep() {

  auto time = dynamical_system.getTime();
  auto state = dynamical_system.getState();

  auto k1 = dynamical_system(time, state);

  auto k2 = dynamical_system(time+0.5*h,
      add_vectors(state, multiply_by_scalar(k1, 0.5*h)));

  auto k3 = dynamical_system(time+0.5*h,
      add_vectors(state, multiply_by_scalar(k2, 0.5*h)));

  auto k4 = dynamical_system(time+h,
      add_vectors(state, multiply_by_scalar(k3, h)));

  for (auto it = state.begin(); it != state.end(); ++it) {
    int index = std::distance(state.begin(), it);
    *it += 1./6.*k1[index] + 1./3.*k2[index]
      + 1./3.*k3[index] + 1./6.*k4[index];
  }

  dynamical_system.setState(state);
  dynamical_system.setTime(time+h);

}

std::vector<double> RungeKutta4::multiply_by_scalar(
    const std::vector<double>& vec, double scalar) {

  std::vector<double> vec_out;
  std::transform(vec.begin(), vec.end(), std::back_inserter(vec_out),
      [scalar](double d1) {return (d1 * scalar);});

  return vec_out;
}


std::vector<double> RungeKutta4::add_vectors(const std::vector<double>& vec1,
        const std::vector<double>& vec2) {

  std::vector<double> vec_out;
  std::transform(vec1.begin(), vec1.end(), vec2.begin(),
      std::back_inserter(vec_out), [](double d1, double d2) {return d1 + d2;});

  return vec_out;
}

