# this target will compile all the files
CFLAGS = -c -Wall
src = src
CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
TARGET: main.o StateMachine.o AssetManager.o InputManager.o Game.o SplashState.o MainMenuState.o GameState.o GameOverState.o
	$(CC) StateMachine.o InputManager.o GameOverState.o AssetManager.o GameState.o MainMenuState.o SplashState.o main.o -o main $(LIBS)

main.o: $(src)/main.cpp $(src)/DEFINATIONS.hpp
	$(CC) $(CFLAGS) $(src)/main.cpp

StateMachine.o: $(src)/StateMachine.cpp $(src)/StateMachine.hpp
	$(CC) $(CFLAGS) $(src)/StateMachine.cpp

AssetManager.o: $(src)/AssetManager.cpp $(src)/AssetManager.hpp
	$(CC) $(CFLAGS) $(src)/AssetManager.cpp

InputManager.o: $(src)/InputManager.cpp $(src)/InputManager.hpp
	$(CC) $(CFLAGS) $(src)/InputManager.cpp

Game.o: $(src)/Game.cpp $(src)/Game.hpp
	$(CC) $(CFLAGS) $(src)/Game.cpp

SplashState.o: $(src)/SplashState.cpp $(src)/SplashState.hpp $(src)/DEFINATIONS.hpp
	$(CC) $(CFLAGS) $(src)/SplashState.cpp

MainMenuState.o: $(src)/MainMenuState.cpp $(src)/MainMenuState.hpp $(src)/DEFINATIONS.hpp $(src)/GameState.hpp
	$(CC) $(CFLAGS) $(src)/MainMenuState.cpp

GameState.o: $(src)/GameState.cpp $(src)/GameState.hpp $(src)/DEFINATIONS.hpp
	$(CC) $(CFLAGS) $(src)/GameState.cpp

GameOverState.o: $(src)/GameOverState.cpp $(src)/GameOverState.hpp
	$(CC) $(CFLAGS) $(src)/GameOverState.cpp

clean:
	rm -f *.o main
