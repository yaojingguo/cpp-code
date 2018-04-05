all:
	gcc -c -Wall -Werror -fpic greeting.c
	gcc -shared -o libgreeting.so greeting.o
	gcc -Wall -o test main.c -lgreeting -L.

clean:
	rm -fr *.o *.so
