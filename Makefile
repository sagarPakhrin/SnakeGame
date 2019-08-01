# this target will compile all the files
CFLAGS = -c -Wall
src = src
CC = g++

TARGET: clean main.o
	$(CC) main.o -o main -lsfml-graphics -lsfml-window -lsfml-system

main.o: src/main.cpp
	$(CC) $(CFLAGS) $(src)/main.cpp

clean:
	rm -f *.o main
