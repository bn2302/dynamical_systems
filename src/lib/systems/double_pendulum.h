#ifndef LIB_DOUBLE_PENDULUM_H_
#define LIB_DOUBLE_PENDULUM_H_
#include <vector>
#include "dynamical_system.h"

//
// © Bastian Niebel
//
// Differential algebraic equations describing a double pendulum.
//
// The () operator implements the right hand side of the ordinary differential
// systems of equations of the double pendulum.
//
// The dynamic system has to states phi1 and d_phi1, phi2, d_phi2, where d_phi
// is the derivative of phi with respect to time. The index 1/2 indicates the
// sub-pendulum.
//
// Example:
//    DoublePendulum* pend = new DoublePendulum();
//    auto derivative_of_states_with_respect_to_the_time = pend->operator();
//    for (auto it& : derivative_of_states_with_respect_to_the_time) {
//      std::cout << it << std::endl;
//    }
//
//    delete pend;
class DoublePendulum : public DynamicalSystem
{
  public:

//  Initializes the double pendulum with the passed arguments
//
//  Arguments:
//    initial_time: time
//    initial_state: phi1, d_phi1, phi2, d_phi2
//    length1: length of the first pendulum
//    length2: length of the second pendulum
//    mass1: Mass of the first pendulum
//    mass2: Mass of the second pendulum
//
    DoublePendulum(double initial_time, std::vector<double> initial_state,
        double length1, double length2, double mass1, double mass2);

//  Initializes the double pendulum with default values
//    time : 0
//    state : 0, 0.1, 0, 0.1
//    length1: 1
//    length2: 1
//    mass1: 1
//    mass2: 2
//
    DoublePendulum();

    ~DoublePendulum() {};

//  () Operator defines the right hand side of the dynamical system describing
//  the double pendulum.
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

