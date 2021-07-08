#pragma once

#include <list>

template <typename E>
class Queue {
 public:
  Queue();
  ~Queue();
  void Enqueue(E element);
  E Dequeue();
  size_t size() const;

 private:
  std::list<E> list_;
};

template <typename E>
Queue<E>::Queue() {}

template <typename E>
Queue<E>::~Queue() {}

template <typename E>
void Queue<E>::Enqueue(E element) {
  list_.push_back(element);
}

template <typename E>
E Queue<E>::Dequeue() {
  E head = list_.front();
  list_.pop_front();
  return head;
}

template <typename E>
size_t Queue<E>::size() const { 
  return list_.size(); 
}
