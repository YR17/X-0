#include <WinState.h>
#include <MenuState.h>
#include <BackgroundState.h>
#include <EventManager.h>
#include <StateManager.h>
#include <VideoManager.h>
using namespace std;

WinState::WinState(string text){
	this->text = text;
	buttons = new vector<Button*>;
}

void WinState::onActive(){
	buttons->push_back(new CallerButton(70, 260, 140, 30, "New Game", this, 1));
	buttons->push_back(new CallerButton(270, 260, 140, 30, "Menu", this, 2));

	for(auto i = buttons->begin();i<buttons->end();i++){
		EventManager::getImplementation()->bindButton(*i);
	}
}

void WinState::onPassive(){
	EventManager::getImplementation()->unbindAll();
	buttons->clear();
}

void WinState::onRender(){
	VideoManager::getImplementation()->fillRect(40, 190, 400, 60, 0, 0, 0, 230);
	VideoManager::getImplementation()->drawText(50, 200, 380, 40, text);
	for(auto i = buttons->begin();i<buttons->end();i++){
		VideoManager::getImplementation()->drawButton(*i);
	}
}

void WinState::onClick(int number){
	StateManager::getImplementation()->popAll();
	StateManager::getImplementation()->push(new MenuState());
	StateManager::getImplementation()->pushBackgroundState(new BackgroundState());
	if(number==1){
		StateManager::getImplementation()->push(new GameState());
	}
}