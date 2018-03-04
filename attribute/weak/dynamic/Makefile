all:
	cc -g -c -o main.o main.c
	cc -g -fpic -c -o power_slow.po power_slow.c
	cc -shared -fpic -o libpowerslow.so power_slow.po
	cc  main.o power_slow.po -L`pwd` -Wl,-R`pwd` -lpowerslow -o main

	cc -g -DENABLE_DEF -fpic -c -o power_slow.po power_slow.c
	cc -shared -fpic -o libpowerslow.so power_slow.po
	cc  main.o power_slow.po -L`pwd` -Wl,-R`pwd` -lpowerslow -o main2

	cc -g -DNO_USER_HOOK -c -o main.o main.c
	cc -g -fpic -c -o power_slow.po power_slow.c
	cc -shared -fpic -o libpowerslow.so power_slow.po
	cc  main.o power_slow.po -L`pwd` -Wl,-R`pwd` -lpowerslow -o main3

	cc -g -DNO_USER_HOOK -c -o main.o main.c
	cc -g -DENABLE_DEF -fpic -c -o power_slow.po power_slow.c
	cc -shared -fpic -o libpowerslow.so power_slow.po
	cc  main.o power_slow.po -L`pwd` -Wl,-R`pwd` -lpowerslow -o main4

clean:
	rm -fr main main2 main3 main4 *.o
