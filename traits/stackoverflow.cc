#include <cstddef>

template<template<typename T> class AllocatePolicy>
struct Pool {
    void allocate(size_t n) {
        int *p = AllocatePolicy<int>::allocate(n);
    }
};

// pass the template "allocator" as argument.
template<typename T>
struct allocator {
  static T * allocate(size_t n) {
    return 0;
  }
};

Pool<allocator> test;

int main(int argc, char const *argv[]) {

  return 0;
}
