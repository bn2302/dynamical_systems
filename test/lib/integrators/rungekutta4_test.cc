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

  auto calculated_result= pendulum->operator()(
      pendulum->getTime(), pendulum->getState());

  std::vector<double> expected_result {0.00962051092222679, 0.621849568726504};

  ASSERT_EQ(calculated_result.size(), expected_result.size())
    << "Vectors calculated_resultand result are of unequal length";

  for (auto i = 0u; i < expected_result.size(); ++i) {
      EXPECT_DOUBLE_EQ(calculated_result[i], expected_result[i])
      << "Vectors calculated_resultand result differ at indecalculated_result"
      << i;
  }

  delete pendulum;
  delete rk4;

}
