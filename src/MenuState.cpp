#include <MenuState.h>
#include <MessageState.h>
#include <EventManager.h>
#include <VideoManager.h>
#include <iostream>
using namespace std;

MenuState::MenuState(){
	x = 120;
	y = 70;
	w = 240;
	h = 300;
	backgroundR = 255;
	backgroundG = 255;
	backgroundB = 255;
	backgroundA = 235;
	borderR = 0;
	borderG = 0;
	borderB = 0;

	buttons = new std::vector<Button*>;
}

void MenuState::onRender(){
	for(auto i = buttons->begin();i<buttons->end();i++){
		VideoManager::getImplementation()->drawButton(*i);
	}
}

void MenuState::onActive(){
	buttons->push_back(new StateButton(140, 145, 200, 30, "One player", new MessageState("In developing")));
	buttons->push_back(new StateButton(140, 185, 200, 30, "Two players", new GameState));
	buttons->push_back(new StateButton(140, 225, 200, 30, "Play online", new MessageState("In developing")));
	buttons->push_back(new StateButton(140, 265, 200, 30, "Settings", new MessageState("In developing")));
	buttons->push_back(new StateButton(140, 305, 200, 30, "Exit", NULL));
	for(auto i = buttons->begin();i<buttons->end();i++){
		EventManager::getImplementation()->bindButton(*i);
	}
}

void MenuState::onPassive(){
	EventManager::getImplementation()->unbindAll();
	buttons->clear();
}

MenuState::~MenuState(){
	for(auto i = buttons->begin();i<buttons->end();i++){
		delete *i;
	}
	delete buttons;
}