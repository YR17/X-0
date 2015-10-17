#ifndef GAME_STATE_H
	#define GAME_STATE_H
	#include <State.h>
	#include <vector>

	#define WIN_LENGTH 3	


	class Button;
	class GameState: public State{
		bool turn;
		int **field;
		std::vector<Button*> *buttons;
		void check();
	public:
		GameState();
		~GameState(){};
		void onActive();
		void onPassive();
		void onRender();
		void onPhysicTick(){};
		void mark(int, int, Button*);
	};
#endif