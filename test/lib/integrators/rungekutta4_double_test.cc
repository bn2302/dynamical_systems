#include <vector>
#include "dynamical_system.h"
#include "integrator.h"
#include "rungekutta4.h"
#include "pendulum.h"
#include "gtest/gtest.h"

TEST(rungekutta4_test, integration_step_double_test)
{
  auto pendulum = new Pendulum();
  auto integrator = new integration::RungeKutta4<DynamicalSystem,
    std::vector<double>>(1);

  auto data = integrator->integrateNSteps(*pendulum, pendulum->getInitialState(),
      pendulum->getInitialTime(), 1);

  std::vector<double> expected_result{ -0.063431883515118137, 0.0096205109222267937};

  auto calculated_result = data[1].state;
  ASSERT_EQ(calculated_result.size(), expected_result.size())
    << "Vectors calculated_resultand result are of unequal length";

  for (auto i = 0u; i < expected_result.size(); ++i) {
      EXPECT_DOUBLE_EQ(calculated_result[i], expected_result[i])
      << "Vectors calculated_resultand result differ at indecalculated_result"
      << i;
  }

  delete pendulum;
  delete integrator;

}
