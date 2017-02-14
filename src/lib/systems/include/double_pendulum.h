#ifndef LIB_DOUBLE_PENDULUM_H_
#define LIB_DOUBLE_PENDULUM_H_
#include <vector>
#include "dynamical_system.h"

class DoublePendulum : public DynamicalSystem
{
  public:
    DoublePendulum();

    DoublePendulum(double time, std::vector<double>& state,
        double length1, double length2, double mass1, double mass2);

    ~DoublePendulum() {};

    std::vector<double> operator()(const double time,
        const std::vector<double>& state) const;

  private:
    const double gravity_of_earth = 9.81;
    double length1;
    double length2;
    double mass1;
    double mass2;
};

#endif /* ifndef LIB_PENDULUM_H_ */

