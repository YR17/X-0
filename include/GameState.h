#ifndef GAME_STATE_H
	#define GAME_STATE_H
	#include <State.h>
	#include <Button.h>
	#include <vector>
	#include <EventManager.h>
	#include <VideoManager.h>

	class GameState: public State{
		// FieldButtonType turn;
		// FieldButtonType **field;
		std::vector<Button*> *buttons;
	public:
		GameState();
		~GameState(){};
		void onActive();
		void onPassive(){};
		void onRender();
		void onPhysicTick(){};
		void onClick(int, int);
	};
#endif