#include <vector>
#include "dynamical_system.h"
#include "integrator.h"
#include "rungekutta4.h"
#include "pendulum.h"
#include "gtest/gtest.h"

TEST(rungekutta4_test, integration_step_test)
{
  DynamicalSystem* pendulum = new Pendulum();
  Integrator* rk4 = new RungeKutta4(*pendulum, 1);

  rk4->integrateNSteps(1);

  ASSERT_EQ(0.0, 0.0);
  delete pendulum;
  delete rk4;



}
