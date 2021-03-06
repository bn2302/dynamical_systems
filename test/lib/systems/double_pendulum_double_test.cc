#include <vector>
#include "gtest/gtest.h"
#include "double_pendulum.h"


TEST(dynamical_systems, double_pendulum_double_test)
{

  DoublePendulum pendulum = {1.0,
      std::vector<double> {1.2, 0.2, -2.3, 2.4}, .2, .3, .1, .3};

  auto calculated_result = pendulum(pendulum.getInitialTime(),
                                    pendulum.getInitialState());

  std::vector<double> expected_result {0.2, -51.8975137806604, 2.4,
    -8.02464300367009};

  ASSERT_EQ(calculated_result.size(), expected_result.size())
    << "Vectors calculated_resultand result are of unequal length";

  for (auto i = 0u; i < expected_result.size(); ++i) {
    EXPECT_DOUBLE_EQ(calculated_result[i], expected_result[i])
      << "Vectors calculated_resultand result differ at indecalculated_result"
      << i;
  }

}
