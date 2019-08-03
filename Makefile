# this target will compile all the files
CFLAGS = -c -Wall
src = src
CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
TARGET: main.o StateMachine.o AssetManager.o InputManager.o Game.o SplashState.o MainMenuState.o
	$(CC) StateMachine.o AssetManager.o InputManager.o AssetManager.o MainMenuState.o SplashState.o main.o -o main $(LIBS)

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

MainMenuState.o: $(src)/MainMenuState.cpp $(src)/MainMenuState.hpp $(src)/DEFINATIONS.hpp
	$(CC) $(CFLAGS) $(src)/MainMenuState.cpp


clean:
	rm -f *.o main
