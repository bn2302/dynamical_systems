#include <iostream>

#include "integrator.h"

template<typename T>
IntegrationData<T>::IntegrationData() {}

template<typename T>
void IntegrationData<T>::push_back(T time_point,
    const std::vector<T>& state) {

  timepoints.push_back(time_point);

  states_over_time.push_back(std::move(state));

}

template<typename T>
void IntegrationData<T>::writeData() {

    for(auto i = timepoints.begin(); i != timepoints.end(); ++i) {

      std::cout << *i;
      int index = std::distance(timepoints.begin(), i);
      for(auto j = states_over_time[index].begin();
          j != states_over_time[index].end(); ++j) {
        std::cout << "\t" <<  *j;
      }
      std::cout << std::endl;

    }

}

