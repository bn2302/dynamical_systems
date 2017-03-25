#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "dynamical_system.h"
#include "pendulum.h"
#include "double_pendulum.h"
#include "integrator.h"
#include "rungekutta4.h"
#include "euler.h"



int main(int argc, char *argv[])
{
    std::vector<std::string> args(argv, argv+argc);

    std::unique_ptr<DynamicalSystem> system;
    std::unique_ptr<Integrator<DynamicalSystem, std::vector<double>>> 
        integrator;

    bool error = false;

    if ((args.size() > 2) && (args[1] == "single")) {

      system = std::make_unique<Pendulum>();

    }
    else if ((args.size() > 2) && (args[1] == "double")) {

      system = std::make_unique<DoublePendulum>();

    } else {

      error = true;

    }


    if ((error == false) && (args.size() > 2) && (args[2] == "euler")) {

      integrator = std::make_unique<
          Euler<DynamicalSystem, std::vector<double>>>(0.1);

    } else if ((error == false) && (args.size() > 2) && (args[2] == "rk4")) {

      integrator = std::make_unique<
          RungeKutta4<DynamicalSystem, std::vector<double>>>(0.1);

    } else {
      error = true;
    }

    if (error == true) {
      std::cout << "Usage: program [single | double] [euler | rk4] \n";
      std::cout << "[single | double ]for single or double pendulum. \n";
      std::cout << "[euler | rk4] for Euler or Runge Kutta4 scheme. \n";

      return 1;

    }

    auto data = integrator->integrateNSteps(*system, system->getInitialState(),
        system->getInitialTime(), 100);
    integration::writeIntegrationData(data);

    return 0;

}
