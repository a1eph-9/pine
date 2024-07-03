all:
	gcc -Wall -Wno-pointer-sign -o test test.c
	./test
	sudo cp pine.h /usr/include/pine.h
