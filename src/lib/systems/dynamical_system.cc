#include "dynamical_system.h"

DynamicalSystem::DynamicalSystem(double initial_time,
                                 std::vector<double> initial_state)
        : initial_time(initial_time), initial_state(initial_state) {}

DynamicalSystem::~DynamicalSystem() {}


const std::vector<double>& DynamicalSystem::getInitialState() const
{
  return initial_state;
}


void DynamicalSystem::setInitialState(const std::vector<double> initial_state)
{
  this->initial_state = initial_state;
}


double DynamicalSystem::getInitialTime() const {
  return initial_time;
}


void DynamicalSystem::setInitialTime(const double initial_time)
{
  this->initial_time = initial_time;
}


