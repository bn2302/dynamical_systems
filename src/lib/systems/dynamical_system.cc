#include "dynamical_system.h"


DynamicalSystem::DynamicalSystem(double time, std::vector<double> state)
  : time(time), state(state) {}


DynamicalSystem::~DynamicalSystem() {}


const std::vector<double>& DynamicalSystem::getState() const {
  return state;
}


void DynamicalSystem::setState(const std::vector<double>& state) {
  this->state = std::move(state);
}


double DynamicalSystem::getTime() const {
  return time;
}


void DynamicalSystem::setTime(const double time) {
  this->time = time;
}

