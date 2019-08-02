# this target will compile all the files
CFLAGS = -c -Wall
src = src
CC = g++

TARGET: clean main.o StateMachine.o AssetManager.o
	$(CC) StateMachine.o AssetManager.o main.o -o main -lsfml-graphics -lsfml-window -lsfml-system

main.o: src/main.cpp
	$(CC) $(CFLAGS) $(src)/main.cpp

StateMachine.o: $(src)/StateMachine.cpp $(src)/StateMachine.hpp
	$(CC) $(CFLAGS) $(src)/StateMachine.cpp

AssetManager.o: $(src)/AssetManager.cpp $(src)/AssetManager.hpp
	$(CC) $(CFLAGS) $(src)/AssetManager.cpp













clean:
	rm -f *.o main
