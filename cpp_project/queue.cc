#include "queue.h"

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
  E front = list_.front();
  list_.pop_front();
}

template <typename E>
size_t Queue<E>::size() const { 
  return list_.size(); 
}

