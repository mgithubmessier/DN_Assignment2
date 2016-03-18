CC = g++
CPPFLAGS = -g -I.
all: main

main: Parser.o 

main.o: main.cpp
Parser.o: Parser.cpp 

clean:
	rm main
	rm *.o
