#ifndef MENU_STATE_H
	#define MENU_STATE_H
	#include <State.h>
	#include <VideoManager.h>
	#include <EventManager.h>
	#include <Button.h>
	#include <vector>
	#include <GameState.h>

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
	};
#endif