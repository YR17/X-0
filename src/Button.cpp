#include <Button.h>
#include <iostream>
using namespace std;


void Button::onMouseIn(){
	active = true;
}

void Button::onMouseOut(){
	active = false;
}

StateButton::StateButton(int x, int y, int w, int h, std::string text, State *state){
	this->active = false;
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->text = text;
	this->onClickState = state;
}

void StateButton::onClick(){
	if(onClickState!=NULL)
		StateManager::getImplementation()->push(onClickState);
	else
		StateManager::getImplementation()->pop();
}

template<typename T>
CallerButton<T>::CallerButton(int x, int y, int w, int h, std::string text, T caller){
	this->active = false;
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->text = text;
	this->caller = caller;
}

template<typename T>
void CallerButton<T>::onClick(){
	caller();
}