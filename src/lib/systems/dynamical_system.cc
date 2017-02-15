// © Bastian Niebel
#include "dynamical_system.h"


template<typename T>
DynamicalSystem<T>::DynamicalSystem(T time, std::vector<T> state)
  : time(time), state(state) {}

template<typename T>
DynamicalSystem<T>::~DynamicalSystem() {}


template<typename T>
const std::vector<T>& DynamicalSystem<T>::getState() const {
  return state;
}


template<typename T>
void DynamicalSystem<T>::setState(const std::vector<T>& state) {
  this->state = std::move(state);
}


template<typename T>
T DynamicalSystem<T>::getTime() const {
  return time;
}


template<typename T>
void DynamicalSystem<T>::setTime(const T time) {
  this->time = time;
}


