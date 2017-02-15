#include <vector>
#include "pendulum.h"
#include "gtest/gtest.h"

TEST(prendulum_test, test1)
{
  Pendulum* pendulum = new Pendulum(1.0, std::vector<double> {1.2, 0.2}, .2);
  auto calculated_result= pendulum->operator()(
      pendulum->getTime(), pendulum->getState());

  std::vector<double> expected_result {0.2, -45.71651716669245};

  ASSERT_EQ(calculated_result.size(), expected_result.size())
    << "Vectors calculated_resultand result are of unequal length";

  for (auto i = 0u; i < expected_result.size(); ++i) {
      EXPECT_DOUBLE_EQ(calculated_result[i], expected_result[i])
      << "Vectors calculated_resultand result differ at indecalculated_result"
      << i;
  }

  delete pendulum;

}
