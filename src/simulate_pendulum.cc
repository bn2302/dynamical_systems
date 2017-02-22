#include <iostream>
#include <vector>
#include <string>


#include "dynamical_system.h"
#include "pendulum.h"
#include "double_pendulum.h"
#include "integrator.h"
#include "rungekutta4.h"


int main(int argc, char *argv[])
{
    std::vector<std::string> args(argv, argv+argc);

    DynamicalSystem* system = nullptr;
	RungeKutta4<DynamicalSystem,
		std::vector<double>> integrator = {0.1};

    if ((args.size() > 1) && (args[1] == "single")) {

        system = new Pendulum();

    } else if ((args.size() > 1) && (args[1] == "double")) {

        system = new DoublePendulum();

    } else {

      std::cout << "Usage: program [single | double] \n";
      std::cout << "for single or double pendulum. \n";

      return 1;

    }

    auto data = integrator.integrateNSteps(*system, system->getInitialState(),
        system->getInitialTime(), 100);
    integration::writeIntegrationData(data);

    delete system;

    return 0;

}
