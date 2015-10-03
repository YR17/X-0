#ifndef EVENT_MANAGER_H
	#define EVENT_MANAGER_H
	#include <Button.h>
	#include <SDL2/SDL.h>
	#include <vector>
	#include <iostream>
	class Button;
	class EventManager{
		static EventManager *pImplementation;
		SDL_Event *event;
		std::vector<Button*> *bindedButtons;
		EventManager();
		bool checkMousePosition(int x, int y, Button*);
	public:
		static EventManager *getImplementation();
		~EventManager();
		void checkEvent();
		void bindButton(Button*);
		void unbindButton(Button*);
		void unbindAll();

		void debug(std::string);
	};
#endif