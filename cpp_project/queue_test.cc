#include <iostream>

#include "gtest/gtest.h"
#include "queue.h"

using namespace std;

class QueueTest : public ::testing::Test {
  protected:
  void SetUp() override {
    cout << "Setting up\n";
    q0_.Enqueue(0);
    q1_.Enqueue(1);
    q2_.Enqueue(2);
  }
  void TearDown() override {
    cout << "Tearing down\n";
  }
  Queue<int> q0_;
  Queue<int> q1_;
  Queue<int> q2_;
};

TEST_F(QueueTest, IsEmptyInitially) {
  EXPECT_EQ(q0_.size(), 0);
}




