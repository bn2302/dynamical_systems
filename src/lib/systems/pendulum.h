#ifndef LIB_PENDULUM_H_
#define LIB_PENDULUM_H_
#include <vector>
#include "dynamical_system.h"


//
// © Bastian Niebel
// Differential algebraic equations describing a pendulum.
//
// The () operator implements the right hand side of the ordinary differential
// systems of equations of the pendulum.
//
// The dynamic system has to states phi and d_phi, where d_phi
// is the derivative of phi with respect to time.
//
// Example:
//    Pendulum* pend = new Pendulum();
//    auto derivative_of_states_with_respect_to_the_time = pend->operator();
//    for (auto it& : derivative_of_states_with_respect_to_the_time) {
//      std::cout << it << std::endl;
//    }
//
//    delete pend;
class Pendulum : public DynamicalSystem
{
  public:

//  Initializes the pendulum with the passed arguments
//
//  Arguments:
//    initial_time: initial_time
//    initial_state: phi, d_phi
//    length: length of the first pendulum
    Pendulum(double initial_time, std::vector<double> initial_state,
             double length);

//  Initializes the pendulum with default values
//    time : 0
//    state : 0, 0.1
//    length: 1
    Pendulum();

    ~Pendulum() {};

//  () Operator defines the right hand side of the dynamical system describing
//  the pendulum.
    std::vector<double> operator() (const double time,
        const std::vector<double>& state) const;

  private:
    const double gravity_of_earth = 9.81;
    double length;
};


#endif /* ifndef LIB_PENDULUM_H_ */

