#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "pendulum.h"
#include "double_pendulum.h"
#include "integrator.h"
#include "rungekutta4.h"

int main(int argc, char *argv[])
{
    std::vector<std::string> args(argv, argv+argc);

    DynamicalSystem* system;

    if ((args.size() > 1) && (args[1] == "single")) {
       system = new Pendulum();

    } else if ((args.size() > 1) && (args[1] == "double")) {
       system = new DoublePendulum();
    } else {
      std::cout << "Usage: program [single | double] \n";
      std::cout << "for single or double pendulum. \n";
      return 1;
    }

    Integrator* integrator = new RungeKutta4(*system, 0.01);
    IntegrationData data = integrator->integrateNSteps(1000);
    data.writeData();

    delete system;
    delete integrator;
    return 0;
}
