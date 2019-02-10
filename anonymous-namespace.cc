#include <iostream>

namespace {
    int add(int a, int b) {
        return a + b;
    }
}

int main(int argc, char *argv[]) {
    printf("sum: %d\n", add(10, 20));
    return 0;
}
