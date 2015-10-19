#ifndef WIN_STATE_H
	#include <State.h>
	#include <Button.h>
	#include <iostream>
	#include <vector>

	class WinState: public State{
		std::string text;
		std::vector<Button*> *buttons;
	public:
		WinState(std::string);
		virtual ~WinState(){};
		void onRender();
		void onPhysicTick(){};
		void onActive();
		void onPassive();
	};
#endif