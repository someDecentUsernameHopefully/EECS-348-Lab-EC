APPLICATION_NAME = driver
CC = g++
CFLAGs = -c -Wall -g

strToNum = stringToNumber

all: main.o
	$(CC) -o $(APPLICATION_NAME) main.o -g

main.o: main.cpp
	$(CC) $(CFLAGs) main.cpp

clean:
	rm -f *.o