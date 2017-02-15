#include <algorithm>
#include <functional>

#include "integrator.h"


template<typename T>
Integrator<T>::Integrator(DynamicalSystem<T> &sys) : dynamical_system(sys) {}


template<typename T>
Integrator<T>::~Integrator() {};


template<typename T>
IntegrationData<T> Integrator<T>::integrateNSteps(int n) {

  IntegrationData<T> data;

  std::vector<T> state = dynamical_system.getState();
  auto time = dynamical_system.getTime();
  data.push_back(time, state);

  for (auto i = 0; i < n; ++i) {
    integrateStep();
    state = dynamical_system.getState();
    time = dynamical_system.getTime();
    data.push_back(time, state);
  }

  return data;
}


template<typename T>
void Integrator<T>::setDynamicalSystem(DynamicalSystem<T> &sys) {
  this->dynamical_system = sys;
}


template<typename T>
std::vector<T> Integrator<T>::multiply_by_scalar(
    const std::vector<T> &vec,
    T scalar) {

  std::vector<T> vec_out;
  std::transform(vec.begin(), vec.end(), std::back_inserter(vec_out),
      [scalar](T d1) {return (d1 * scalar);});

  return vec_out;
}


template<typename T>
std::vector<T> Integrator<T>::add_vectors(
    const std::vector<T> &vec1,
    const std::vector<T> &vec2) {

  std::vector<T> vec_out;
  std::transform(vec1.begin(), vec1.end(), vec2.begin(),
      std::back_inserter(vec_out), [](T d1, T d2) {return d1 + d2;});

  return vec_out;
}

