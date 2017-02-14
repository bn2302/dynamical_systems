#include <iostream>
#include <vector>

#include "pendulum.h"
#include "double_pendulum.h"
#include "rungekutta4.h"

int main()
{
    DynamicalSystem* pendulum = new Pendulum();
    DynamicalSystem* doublependulum = new DoublePendulum();

    Integrator* rk4 = new RungeKutta4(*pendulum, 0.01);

    rk4->integrateNSteps(10);

    rk4->setDynamicalSystem(*doublependulum);

    rk4->integrateNSteps(10);

    delete pendulum;
    delete rk4;

    return 0;
}
