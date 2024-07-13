all:
	sudo cp pine.h /usr/include/pine.h
	gcc -Wall -Wno-pointer-sign -o demo demo.c
