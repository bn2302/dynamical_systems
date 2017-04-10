#ifndef LIB_INTEGRATOR_H_
#define LIB_INTEGRATOR_H_
//
// © Bastian Niebel
//
// Abstract base class that define integrators for simple ordinary differential
// equations.
//
#include <memory>
#include <type_traits>
#include <utility>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>
#include <iostream>


namespace integration {


  //
  // Container for the integration data, contains the time and the states,
  // whose type is passed as a template which should be a container. The type
  // of the time is deduced from the container elements type
  //
  template<typename State>
  struct IntegrationData
  {

      typename std::remove_reference<decltype(
            std::declval<State>().front())>::type time;

      State state;

  };


  //
  // Abstract class for the integrators
  // Children should implement a function integrateStep.
  //
  // The class is passed two templates. The first is system, which specifies the
  // type of the dynamical system. The system type can be a function pointer or
  // a class with an overloaded () operator.
  //
  // The second template is state, which is a container used for the dynamical
  // states
  //
  template<typename System, typename State>
  class Integrator
  {

    using element_type = typename std::remove_reference<decltype(
            std::declval<State>().front())>::type;

    public:

      using StateTimeSeries = std::vector<IntegrationData<State>>;

      Integrator();

      virtual ~Integrator() = 0;

      auto integrateNSteps(const System& sys,
                           const State& initial_state,
                           const element_type& inital_time,
                           int n);

    protected:

      virtual IntegrationData<State> integrateStep(
              const System& sys, const IntegrationData<State>& data) = 0;

      static auto multiply_by_scalar(const State& vec,
                                      const element_type& scalar);

      static auto add_vectors(const State& vec1, const State& vec2);

  };


  template<typename System, typename State>
  Integrator<System, State>::Integrator() {}


  template<typename System,  typename State>
  Integrator<System, State>::~Integrator() {}


  // Integrate the dynamical system
  template<typename System,  typename State>
  auto Integrator<System, State>::integrateNSteps(
          const System& sys,
          const State& initial_state,
          const element_type& inital_time,
          int n) {

    StateTimeSeries store;

    IntegrationData<State> data {inital_time, initial_state};

    store.push_back(data);

    for (auto i = 0; i < n; ++i) {
      auto new_data = integrateStep(sys, data);
      store.push_back(new_data);
      data = new_data;
    }

    return store;
  }


  // Adds the elements of a container with a scalar, casts the scalar to the
  // elements of the container
  template<typename System,  typename State>
  inline auto Integrator<System, State>::multiply_by_scalar(
      const State& vec,
      const typename Integrator<System, State>::element_type& scalar) {

    State vec_out;
    std::transform(vec.begin(), vec.end(), std::back_inserter(vec_out),
            std::bind1st(std::multiplies<element_type>(), scalar));

    return vec_out;
  }


  // Adds the elements of two containers element wise
  template<typename System,  typename State>
  inline auto Integrator<System, State>::add_vectors(
      const State& vec1,
      const State& vec2) {

    State vec_out;
    std::transform(vec1.begin(), vec1.end(), vec2.begin(),
        std::back_inserter(vec_out), std::plus<element_type>());

    return vec_out;

  }


  // Writes the integration data to the standard out, in the following
  // format:
  //
  // <time> <state1> <state2> .. <state_n>
  template<typename State>
  void writeIntegrationData(const std::vector<IntegrationData<State>>& data)
  {

      for(auto datum = data.begin(); datum != data.end(); ++datum) {

        std::cout << datum->time;

        auto state = datum->state;
        for(auto j = state.begin(); j != state.end(); ++j) {
          std::cout << "\t" <<  *j;
        }
        std::cout << std::endl;
      }
  }

}


#endif /* ifndef LIB_INTEGRATOR_H_ */
