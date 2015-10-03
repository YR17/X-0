CC = g++
PRE_FLAGS = -I include
POST_FLAGS = -lSDL2main -lSDL2 -lSDL2_image
all: Game

Game: Application.o BackgroundState.o Button.o EventManager.o GameState.o MenuState.o StateManager.o VideoManager.o
	$(CC) $(PRE_FLAGS) src/main.cpp obj/Application.o obj/BackgroundState.o obj/Button.o obj/EventManager.o obj/GameState.o obj/MenuState.o obj/StateManager.o obj/VideoManager.o -o bin/game.out $(POST_FLAGS)
Application.o:
	$(CC) $(PRE_FLAGS) -c src/Application.cpp -o obj/Application.o
BackgroundState.o:
	$(CC) $(PRE_FLAGS) -c src/BackgroundState.cpp -o obj/BackgroundState.o
Button.o:
	$(CC) $(PRE_FLAGS) -c src/Button.cpp -o obj/Button.o
EventManager.o:
	$(CC) $(PRE_FLAGS) -c src/EventManager.cpp -o obj/EventManager.o -std=c++11
GameState.o:
	$(CC) $(PRE_FLAGS) -c src/GameState.cpp -o obj/GameState.o -std=c++11
MenuState.o:
	$(CC) $(PRE_FLAGS) -c src/MenuState.cpp -o obj/MenuState.o -std=c++11
StateManager.o:
	$(CC) $(PRE_FLAGS) -c src/StateManager.cpp -o obj/StateManager.o
VideoManager.o:
	$(CC) $(PRE_FLAGS) -c src/VideoManager.cpp -o obj/VideoManager.o
clean:
	cd obj
	del "*.*"