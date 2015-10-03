#ifndef APPLICATION_H
	#define APPLICATION_H
	#include <StateManager.h>
	#include <EventManager.h>
	#include <VideoManager.h>
	class Application{
	private:
		StateManager *stateManager;
		VideoManager *videoManager;
		EventManager *eventManager;
	public:
		Application();
		~Application();
		void start();
	};
#endif