#ifndef GAME_STATE_H
	#define GAME_STATE_H
	#include <State.h>
	#include <vector>

	#define WIN_LENGTH 3	


	class Button;
	class GameState: public State{

		enum Direction{RIGHT=0, DOWN, DOWN_LEFT, DOWN_RIGHT};
		enum Mark{NONE=0, CROSS, ZERO};
		
		bool turn;
		int **field;
		std::vector<Button*> *buttons;
		bool check(int, int, int, Mark, Direction);
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