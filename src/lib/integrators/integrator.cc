#include <algorithm>
#include <functional>

#include "integrator.h"


Integrator::Integrator(DynamicalSystem& sys) : dynamical_system(sys) {}


Integrator::~Integrator() {};


IntegrationData Integrator::integrateNSteps(int n) {

  IntegrationData data;

  std::vector<double> state = dynamical_system.getState();
  double time = dynamical_system.getTime();
  data.push_back(time, state);

  for (int i = 0; i < n; ++i) {
    integrateStep();
    state = dynamical_system.getState();
    time = dynamical_system.getTime();
    data.push_back(time, state);
  }

  return data;
}


void Integrator::setDynamicalSystem(DynamicalSystem& dynamical_system) {
  this->dynamical_system = dynamical_system;
}


std::vector<double> Integrator::multiply_by_scalar(
    const std::vector<double>& vec,
    double scalar) {

  std::vector<double> vec_out;
  std::transform(vec.begin(), vec.end(), std::back_inserter(vec_out),
      [scalar](double d1) {return (d1 * scalar);});

  return vec_out;
}


std::vector<double> Integrator::add_vectors(
    const std::vector<double>& vec1,
    const std::vector<double>& vec2) {

  std::vector<double> vec_out;
  std::transform(vec1.begin(), vec1.end(), vec2.begin(),
      std::back_inserter(vec_out), [](double d1, double d2) {return d1 + d2;});

  return vec_out;
}

