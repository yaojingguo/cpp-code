#pragma once
#include "list"
using namespace std;

template <typename E>
class Queue {
 public:
  Queue();
  void Enqueue(E element);
  E Dequeue();
  size_t size() const;

 private:
  list<E> list_;
};
