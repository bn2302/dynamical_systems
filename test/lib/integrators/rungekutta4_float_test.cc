#include <vector>
#include "gtest/gtest.h"
#include "pendulum.h"
#include "rungekutta4.h"


TEST(rungekutta4_test, integration_step_float_test)
{

  Pendulum<float>* pendulum = new Pendulum<float>();

  RungeKutta4<float>* rk4 = new RungeKutta4<float>(*pendulum, 1);

  rk4->integrateNSteps(1);

  auto calculated_result= pendulum->operator()(
      pendulum->getTime(), pendulum->getState());

  std::vector<float> expected_result {0.0096204951, 0.621849568};

  ASSERT_EQ(calculated_result.size(), expected_result.size())
    << "Vectors calculated_result and result are of unequal length";

  for (auto i = 0u; i < expected_result.size(); ++i) {
      EXPECT_FLOAT_EQ(calculated_result[i], expected_result[i])
      << "Vectors calculated_result and result differ at index "
      << i;
  }

  delete pendulum;
  delete rk4;

}
