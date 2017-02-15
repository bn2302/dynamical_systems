#include <vector>
#include "gtest/gtest.h"
#include "pendulum.h"


TEST(dynamical_systems, pendulum_float_test)
{

  Pendulum<float>* pendulum = new Pendulum<float>(1.0,
      std::vector<float> {1.2, 0.2}, .2);

  auto calculated_result= pendulum->operator()(
      pendulum->getTime(), pendulum->getState());

  std::vector<float> expected_result {0.2, -45.71651716669245};

  ASSERT_EQ(calculated_result.size(), expected_result.size())
    << "Vectors calculated_resultand result are of unequal length";

  for (auto i = 0u; i < expected_result.size(); ++i) {
      EXPECT_FLOAT_EQ(calculated_result[i], expected_result[i])
      << "Vectors calculated_resultand result differ at indecalculated_result"
      << i;
  }

  delete pendulum;

}
