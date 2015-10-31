#include <EventManager.h>
#include <StateManager.h>
#include <iostream>
using namespace std;


EventManager *EventManager::pImplementation = NULL;

EventManager *EventManager::getImplementation(){
	if(!pImplementation)pImplementation = new EventManager();
	return pImplementation;
}

EventManager::EventManager(){
	event = new SDL_Event();
	bindedButtons = new vector<Button*>;
}

bool EventManager::checkMousePosition(int x, int y, Button* button){
	if(x>=button->x&&
		 x<button->x+button->w&&
		 y>=button->y&&
		 y<button->y+button->h
		)return true;
	else return false;
}

void EventManager::checkEvent(){
	while(SDL_PollEvent(event)!=0){
		switch(event->type){
			case SDL_QUIT:{
				StateManager::getImplementation()->popAll();
				return;
			}
			break;
			case SDL_MOUSEMOTION:{
				for(auto i = bindedButtons->begin();i<bindedButtons->end();i++){
					if(checkMousePosition(event->motion.x, event->motion.y, *i)){
						if(!(*i)->isActive())(*i)->onMouseIn();
					}
					else if((*i)->isActive())(*i)->onMouseOut();
				}
			}
			break;
			case SDL_MOUSEBUTTONUP:{
				for(auto i = bindedButtons->begin();i<bindedButtons->end();i++){
					if(event->button.button==SDL_BUTTON_LEFT&&checkMousePosition(event->button.x, event->button.y, *i)){
						(*i)->onClick();
						break;
					}
				}
			}
			break;
		}
	}
}

void EventManager::bindButton(Button *button){
	bindedButtons->push_back(button);
}

void EventManager::unbindButton(Button *button){
	for(auto i = bindedButtons->begin();i<bindedButtons->end();i++){
		if(*i==button){
			if(button->isActive())button->onMouseOut();
			bindedButtons->erase(i);
			return;
		}
	}
}

void EventManager::unbindAll(){
	bindedButtons->clear();
}

EventManager::~EventManager(){
	for(auto i = bindedButtons->begin();i<bindedButtons->end();i++){
		delete *i;
	}
	delete bindedButtons;
	delete event;
}

void EventManager::debug(string str=" "){
	cout<<str<<endl;
	cout<<bindedButtons->size()<<endl;
	if(!bindedButtons->empty()){
		for(auto i = bindedButtons->begin();i<bindedButtons->end();i++){
			cout<<*i<<endl;
		}
	}
	cout<<endl;
}