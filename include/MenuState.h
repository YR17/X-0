#ifndef MENU_STATE_H
	#define MENU_STATE_H
	#include <State.h>
	#include <Button.h>
	#include <vector>
	
	class GameState;

	class MenuState: public State{
		int x, y, w, h;
		int backgroundR, backgroundG, backgroundB, backgroundA;
		int borderR, borderG, borderB;
		std::vector<Button*> *buttons;
	public:
		MenuState();
		~MenuState();
		void onRender();
		void onPhysicTick(){};
		void onActive();
		void onPassive();
		void onClick(int){};
	};
#endif