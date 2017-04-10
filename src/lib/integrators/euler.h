#ifndef LIB_EULER_H_
#define LIB_EULER_H_
// © Bastian Niebel

#include "integrator.h"

using namespace integration;

namespace integration {


  // Class inherits from Integrator and implements an ordinary differential
  // equation integrator using the Euler Method.
  //
  // Example:
  //    Pendulum system;
  //    Euler<DynamicalSystem, std::vector<double>> integrator = {0.1};
  //    auto data = integrator.integrateNSteps(system,
  //                                           system.getInitialState(),
  //                                           system.getInitialTime(),
  //                                           100);
  //    writeIntegrationData(data);
  //
  template<typename System, typename State>
  class Euler : public Integrator<System, State>
  {

    using element_type = typename std::remove_reference<decltype(
            std::declval<State>().front())>::type;

    public:

      Euler(element_type step_size);

      ~Euler();

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
  Euler<System, State>::Euler(
          typename Euler<System, State>::element_type step_size)
      : step_size(step_size) {}


  template<typename System, typename State>
  Euler<System, State>::~Euler() {}


  template<typename System, typename State>
  auto Euler<System, State>::integrateStep (
          const System& sys,
          const IntegrationData<State>& data) -> IntegrationData<State> {

    IntegrationData<State> new_data {data};

    new_data.time += step_size;
    new_data.state = add_vectors(data.state,
        multiply_by_scalar(sys(data.time, data.state), step_size));

    return new_data;

  }


}


#endif /* ifndef LIB_EULER_H_ */
