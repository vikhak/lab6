# -*- Makefile -*-
INSTDIRPROG = /usr/local/bin
INSTDIRLIB = /usr/local/lib
LIBFLAG = -L. -lresistance -Wl,-rpath,/usr/local/lib

all:	electrotest

lib:	libresistance.so

electrotest:	main.c libresistance.so
		gcc -o electrotest main.c -L. -lresistance -Wl,-rpath,.

libresistance.so:	lib/libresistance.c lib/libresistance.h
			gcc -c -fPIC lib/libresistance.c
			gcc -shared -fPIC -o libresistance.so libresistance.o

electrotestlib: main.c libresistance.so
		gcc -o electrotest main.c $(LIBFLAG)

install:	electrotestlib
		@if [ -d $(INSTDIRPROG) ];\
			then \
			cp electrotest $(INSTDIRPROG);\
			chmod a+x $(INSTDIRPROG)/electrotest;\
			chmod og-w $(INSTDIRPROG)/electrotest;\
			echo "Installed electrotest in $(INSTDIRPROG)";\
		else \
			echo "Sorry, $(INSTDIRPROG) does not exist.";\
		fi
		@if [ -d $(INSTDIRLIB) ];\
			then \
			cp libresistance.so $(INSTDIRLIB);\
			echo "Installed libresistance.so in $(INSTDIRLIB)";\
		else \
			echo "Sorry, $(INSTDIRLIB) does not exist.";\
		fi
