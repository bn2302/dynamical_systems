#include <iostream>
#include "integrator.h"

Integrator::Integrator(DynamicalSystem& sys) : dynamical_system(sys) {}
Integrator::~Integrator() {};

void Integrator::integrateNSteps(int n) {
  std::vector<double> state = dynamical_system.getState();
  double time = dynamical_system.getTime();

  for (int i = 0; i < n; ++i) {

    std::cout << "time: "<< time << "\nstate:\n";

    for(auto i = state.begin(); i != state.end(); ++i)
    {
      std::cout <<  *i << "\n";
    }
    integrateStep();
    state = dynamical_system.getState();
    time = dynamical_system.getTime();

  }
}

