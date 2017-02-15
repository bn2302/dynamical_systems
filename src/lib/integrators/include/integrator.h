#ifndef LIB_INTEGRATOR_H_
#define LIB_INTEGRATOR_H_

#include <vector>
#include "dynamical_system.h"

template<typename T>
class IntegrationData
{

  public:

    IntegrationData();

    void push_back(T time_point, const std::vector<T>& state);

    void writeData();


  private:

    std::vector<T> timepoints;

    std::vector<std::vector<T>> states_over_time;

};

template class IntegrationData<float>;

template class IntegrationData<double>;


template<typename T>
class Integrator
{

  public:

    Integrator(DynamicalSystem<T> &sys);

    virtual ~Integrator() = 0;

    IntegrationData<T> integrateNSteps(int n);

    void setDynamicalSystem(DynamicalSystem<T>& sys);


  protected:

    DynamicalSystem<T> &dynamical_system;

    virtual void integrateStep() = 0;

    static std::vector<T> multiply_by_scalar(
      const std::vector<T> &vec, T scalar);

    static std::vector<T> add_vectors(const std::vector<T> &vec1,
      const std::vector<T> &vec2);


};

template class Integrator<float>;

template class Integrator<double>;


#endif /* ifndef LIB_INTEGRATOR_H_ */
