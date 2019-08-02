# this target will compile all the files
CFLAGS = -c -Wall
src = src
CC = g++

TARGET: main.o StateMachine.o AssetManager.o InputManager.o Game.o SplashState.o
	$(CC) StateMachine.o AssetManager.o SplashState.o main.o -o main -lsfml-graphics -lsfml-window -lsfml-system

main.o: src/main.cpp
	$(CC) $(CFLAGS) $(src)/main.cpp

StateMachine.o: $(src)/StateMachine.cpp $(src)/StateMachine.hpp
	$(CC) $(CFLAGS) $(src)/StateMachine.cpp

AssetManager.o: $(src)/AssetManager.cpp $(src)/AssetManager.hpp
	$(CC) $(CFLAGS) $(src)/AssetManager.cpp

InputManager.o: $(src)/InputManager.cpp $(src)/InputManager.hpp
	$(CC) $(CFLAGS) $(src)/InputManager.cpp

Game.o: $(src)/Game.cpp $(src)/Game.hpp
	$(CC) $(CFLAGS) $(src)/Game.cpp

SplashState.o: $(src)/SplashState.cpp $(src)/SplashState.hpp
	$(CC) $(CFLAGS) $(src)/SplashState.cpp






clean:
	rm -f *.o main
