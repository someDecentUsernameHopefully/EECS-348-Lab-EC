APPLICATION_NAME = driver
CC = g++
CFLAGs = -c -Wall -g

strToNum = stringToNumber

all: main.o strToNum.o
	$(CC) -o $(APPLICATION_NAME) main.o $(strToNum).o -g

main.o: main.cpp
	$(CC) $(CFLAGs) main.cpp

$(strToNum).o: $(strToNum).cpp
	$(CC) $(CFLAGs) $(strToNum).cpp

clean:
	rm -f *.o