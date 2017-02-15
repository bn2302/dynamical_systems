#include <iostream>
#include <vector>
#include <string>

#include "pendulum.h"
#include "double_pendulum.h"
#include "integrator.h"
#include "rungekutta4.h"


int main(int argc, char *argv[])
{
    std::vector<std::string> args(argv, argv+argc);

    DynamicalSystem<double> *system;

    if ((args.size() > 1) && (args[1] == "single")) {

       system = new Pendulum<double>();

    } else if ((args.size() > 1) && (args[1] == "double")) {

       system = new DoublePendulum<double>();

    } else {

      std::cout << "Usage: program [single | double] \n";
      std::cout << "for single or double pendulum. \n";

      return 1;

    }

    Integrator<double> *integrator = new RungeKutta4<double>(*system, 0.01);
    IntegrationData<double> data = integrator->integrateNSteps(1000);
    data.writeData();

    delete system;
    delete integrator;

    return 0;

}
