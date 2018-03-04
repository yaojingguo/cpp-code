Build commands:
```
cc -g -c -o main.o main.c
cc -g -c -o power_slow.o power_slow.c
cc -g -c -o power.o power.c
cc  main.o power_slow.o         -o slow
cc  main.o power_slow.o power.o -o fast
```

Output:
```
$ ./slow 3
slow power2
power3() = 27
$ ./fast 3
fast power2
power3() = 27
```
