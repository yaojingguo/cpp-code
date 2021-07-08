#include <iostream>

#include "gtest/gtest.h"
#include "queue.h"

class QueueTest : public ::testing::Test {
  protected:
  void SetUp() override {
    std::cout << "Setting up\n";
    q0_.Enqueue(100);
    q1_.Enqueue(1);
    q2_.Enqueue(2);
  }
  void TearDown() override {
    std::cout << "Tearing down\n";
  }
  Queue<int> q0_;
  Queue<int> q1_;
  Queue<int> q2_;
};

TEST_F(QueueTest, IsEmptyInitially) {
  EXPECT_EQ(q0_.size(), 1);
}
TEST_F(QueueTest, DequeueWorks) {
  int n = q0_.Dequeue();
  EXPECT_EQ(n, 100);
}