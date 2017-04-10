#ifndef LIB_RUNGEKUTTA4_H_
#define LIB_RUNGEKUTTA4_H_
// © Bastian Niebel

#include "integrator.h"

using namespace integration;

namespace integration {


  // Class inherits from Integrator and implements an ordinary differential
  // equation integrator using a RungeKutta4 scheme.
  //
  // Example:
  //    Pendulum system;
  //    RungeKutta4<DynamicalSystem, std::vector<double>> integrator = {0.1};
  //    auto data = integrator.integrateNSteps(system,
  //                                           system.getInitialState(),
  //                                           system.getInitialTime(),
  //                                           100);
  //    writeIntegrationData(data);
  //
  template<typename System, typename State>
  class RungeKutta4 : public Integrator<System, State>
  {

    using element_type = typename std::remove_reference<decltype(
            std::declval<State>().front())>::type;

    public:

      RungeKutta4(element_type step_size);

      ~RungeKutta4();

    protected:

       auto integrateStep(
              const System& sys,
              const IntegrationData<State>& data) -> IntegrationData<State>;

      using Integrator<System, State>::multiply_by_scalar;

      using Integrator<System, State>::add_vectors;

    private:

      element_type step_size;

  };


  template<typename System, typename State>
  RungeKutta4<System, State>::RungeKutta4(
          typename RungeKutta4<System, State>::element_type step_size)
      : step_size(step_size) {}


  template<typename System, typename State>
  RungeKutta4<System, State>::~RungeKutta4() {}


  template<typename System, typename State>
  auto RungeKutta4<System, State>::integrateStep(
          const System& sys,
          const IntegrationData<State>& data) -> IntegrationData<State>{

    IntegrationData<State> new_data {data};

    auto k1 = sys(data.time, data.state);

    auto k2 = sys(data.time+0.5*step_size,
        add_vectors(data.state, multiply_by_scalar(k1, 0.5*step_size)));

    auto k3 = sys(data.time+0.5*step_size,
        add_vectors(data.state, multiply_by_scalar(k2, 0.5*step_size)));

    auto k4 = sys(data.time+step_size,
        add_vectors(data.state, multiply_by_scalar(k3, step_size)));

    for (auto it = new_data.state.begin(); it != new_data.state.end(); ++it)
    {

      size_t index = std::distance(new_data.state.begin(), it);

      *it += step_size/6*k1[index] + step_size/3*k2[index]
        + step_size/3*k3[index] + step_size/6*k4[index];

    }

    new_data.time += step_size;

    return new_data;

  }


}
#endif /* ifndef LIB_ODE45_H_ */
