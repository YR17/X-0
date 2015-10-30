#include <Button.h>
#include <StateManager.h>
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

FieldButton::FieldButton(int x, int y, int w, int h, std::string text, int xPos, int yPos, GameState *state){
	this->active = false;
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->text = text;
	this->xPos = xPos;
	this->yPos = yPos;
	this->state = state;
}

void FieldButton::onClick(){
	state->mark(xPos, yPos, this);
}

CallerButton::CallerButton(int x, int y, int w, int h, string text, State* state, int number){
	this->active = false;
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->text = text;
	this->callerState = state;
	this->number = number;
}

void CallerButton::onClick(){
	callerState->onClick(number);
}