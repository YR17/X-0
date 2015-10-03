#include <Application.h>
#include <BackgroundState.h>
#include <MenuState.h>

#ifdef DEBUG_FLAG
	#include <iostream>
	using namespace std;
#endif

Application::Application(){
	#ifdef DEBUG_FLAG
		cout<<"Constructor of Application "<<this<<endl;
	#endif
	videoManager = VideoManager::getImplementation();
	eventManager = EventManager::getImplementation();
	stateManager = StateManager::getImplementation();
}

void Application::start(){
	stateManager->pushBackgroundState(new BackgroundState());
	stateManager->push(new MenuState());
	while(!stateManager->isExit()){
		videoManager->clearRender();
		stateManager->onRender();
		videoManager->presentRender();
		stateManager->onPhysicTick();
		eventManager->checkEvent();
		SDL_Delay(1000/60);
	}
}

Application::~Application(){
	delete stateManager;
	delete eventManager;
	delete videoManager;
	#ifdef DEBUG_FLAG
	cout<<"Destructor of Application "<<this<<endl;
	#endif
}