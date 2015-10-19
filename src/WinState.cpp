#include <WinState.h>
#include <EventManager.h>
#include <VideoManager.h>
using namespace std;

WinState::WinState(string text){
	this->text = text;
	buttons = new vector<Button*>;
}

void WinState::onActive(){
	buttons->push_back(new StateButton(70, 260, 140, 30, "New Game", NULL));
	buttons->push_back(new StateButton(270, 260, 140, 30, "Menu", NULL));

	for(auto i = buttons->begin();i<buttons->end();i++){
		EventManager::getImplementation()->bindButton(*i);
	}
}

void WinState::onPassive(){
	EventManager::getImplementation()->unbindAll();
	buttons->clear();
}

void WinState::onRender(){
		VideoManager::getImplementation()->drawRect(60, 170, 360, 140, 0, 0, 0);
	for(auto i = buttons->begin();i<buttons->end();i++){
		VideoManager::getImplementation()->drawButton(*i);
	}
}