#include <iostream>

namespace {
    int add(int a, int b) {
        return a + b;
    }
    struct Person {
        int age;
    };
}

int main(int argc, char *argv[]) {
    printf("sum: %d\n", add(10, 20));

    struct Person p = {.age= 100};

    printf("person age: %d\n", p.age);
    return 0;
}
