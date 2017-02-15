#ifndef LIB_DOUBLE_PENDULUM_H_
#define LIB_DOUBLE_PENDULUM_H_
// © Bastian Niebel

#include <vector>
#include "dynamical_system.h"

// Differential algebraic equations of a double pendulum.
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
//    pend->operator();
//    auto derivative_of_states_with_respect_to_the_time = pend->getState();
//    for (auto it& : derivative_of_states_with_respect_to_the_time) {
//      std::cout << it << std::endl;
//    }
//
//    delete pend;
//

template<typename T>
class DoublePendulum : public DynamicalSystem<T>
{
  public:

//  Initializes the T pendulum with the passed arguments
//
//  Arguments:
//    time
//    state:
//
//
    DoublePendulum(T time, std::vector<T> state,
        T length1, T length2, T mass1, T mass2);

//  Initializes the double pendulum with default values
//    time : 0
//    state : 0, 0.1, 0, 0.1
//    length1: 1
//    length2: 1
//    mass1: 1
//    mass2: 2

    DoublePendulum();

    ~DoublePendulum() {};

    std::vector<T> operator()(const T time,
        const std::vector<T>& state) const;

  private:
    const T gravity_of_earth = 9.81;
    T length1;
    T length2;
    T mass1;
    T mass2;
};

template class DoublePendulum<float>;

template class DoublePendulum<double>;


#endif /* ifndef LIB_PENDULUM_H_ */

