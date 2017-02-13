#include <vector>
#include <iostream>
#include <functional>

#include "pendulum.h"
#include "rungekutta4.h"

int main()
{
    double time = 0.4;
    std::vector<double> state {0.0, 0.1};

    DynamicalSystem* pendulum = new Pendulum(time, state, 1.0);
    Integrator* rk4 = new RungeKutta4(*pendulum, 0.01);

    rk4->integrateNSteps(10);


    delete pendulum;
    delete rk4;
    return 0;
}
