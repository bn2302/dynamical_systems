#ifndef LIB_PENDULUM_H_
#define LIB_PENDULUM_H_
#include <vector>
#include <memory>
#include "dynamical_system.h"

class Pendulum : public DynamicalSystem
{
  public:
    Pendulum(double time, std::vector<double> state, double length);

    ~Pendulum() {};

    std::vector<double> right_hand_side(const double time,
        const std::vector<double>& state) const;

  private:
    const float gravity_of_earth = 9.81;
    float length;


};

#endif /* ifndef LIB_PENDULUM_H_ */

