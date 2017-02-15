#ifndef LIB_PENDULUM_H_
#define LIB_PENDULUM_H_
#include <vector>
#include "dynamical_system.h"


template<typename T>
class Pendulum : public DynamicalSystem<T>
{
  public:
    Pendulum();

    Pendulum(T time, std::vector<T> state, T length);

    ~Pendulum() {};

    std::vector<T> operator() (const T time,
        const std::vector<T>& state) const;

  private:
    const T gravity_of_earth = 9.81;
    T length;
};


template class Pendulum<float>;
template class Pendulum<double>;

#endif /* ifndef LIB_PENDULUM_H_ */

