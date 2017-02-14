#ifndef LIB_PENDULUM_H_
#define LIB_PENDULUM_H_
#include <vector>
#include "dynamical_system.h"

class Pendulum : public DynamicalSystem
{
  public:
    Pendulum();

    Pendulum(double time, std::vector<double> state, double length);

    ~Pendulum() {};

    std::vector<double> operator() (const double time,
        const std::vector<double>& state) const;

  private:
    const double gravity_of_earth = 9.81;
    double length;
};

#endif /* ifndef LIB_PENDULUM_H_ */

