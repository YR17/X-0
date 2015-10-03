#ifndef GAME_STATE_H
	#define GAME_STATE_H
	#include <State.h>
	#include <vector>

	class Button;

	class Button;
	class GameState: public State{
		bool turn;
		int **field;
		std::vector<Button*> *buttons;
	public:
		GameState();
		~GameState(){};
		void onActive();
		void onPassive();
		void onRender();
		void onPhysicTick(){};
		void mark(int, int);
	};
#endif