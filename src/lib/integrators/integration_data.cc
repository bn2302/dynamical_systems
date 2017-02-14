#include <iostream>

#include "integrator.h"

IntegrationData::IntegrationData() {}

void IntegrationData::push_back(double time_point,
    const std::vector<double>& state) {

  timepoints.push_back(time_point);

  states_over_time.push_back(std::move(state));

}

void IntegrationData::writeData() {

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


