#include <iostream>

#include "gtest/gtest.h"

class Environment : public ::testing::Environment {
 public:
  Environment() { std::cout << "construct env\n"; }
  ~Environment() override { std::cout << "destruct env\n"; }

  // Override this to define how to set up the environment.
  void SetUp() override { std::cout << "Global set up\n"; }

  // Override this to define how to tear down the environment.
  void TearDown() override { std::cout << "Global tear down\n"; }
};

TEST(Number, Compare) { EXPECT_EQ(1, 1); }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}