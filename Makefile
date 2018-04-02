# -*- Makefile -*-
CC = gcc

all:	electrotest

electrotest:	main.c libresistance.so
		gcc -o electrotest main.c -L. -lresistance -Wl,-rpath,.

libresistance.so:	libresistance.c libresistance.h
			gcc -c -fpic libresistance.c
			gcc -shared -fPIC -o libresistance.so libresistance.o
