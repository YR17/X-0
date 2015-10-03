#include <StateManager.h>

#include <iostream>
using namespace std;

StateManager *StateManager::pImplementation = NULL;

StateManager *StateManager::getImplementation(){
	if(!pImplementation)pImplementation = new StateManager();
	return pImplementation;
}

StateManager::StateManager(){
	curentState = NULL;
	states = new std::vector<State*>;
	backgroundStates = new std::vector<State*>;
}

StateManager::~StateManager(){
	popAll();
	delete states;
	delete backgroundStates;
	delete curentState;
	curentState = NULL;
	#ifdef DEBUG_FLAG
		cout<<"Destructor of StateManager "<<this<<endl;
	#endif
}

void StateManager::pushBackgroundState(State* state){
	backgroundStates->push_back(state);
}

void StateManager::push(State *state){
	if(state==NULL&&state==curentState){
		return;
	}
	states->push_back(curentState);
	if(curentState)curentState->onPassive();
	curentState = state;
	if(curentState)curentState->onActive();
}

void StateManager::popBackgroundState(){
	backgroundStates->erase(backgroundStates->end());
}

void StateManager::pop(){
	curentState->onPassive();
	delete curentState;
	if(states->size()>1){
		curentState = states->back();
		curentState->onActive();
		states->pop_back();
	}
	else curentState = NULL;
}

void StateManager::popAll(){
	for(vector<State*>::iterator i = states->begin();i<states->end();i++){
		delete *i;
	}
	states->clear();
	for(vector<State*>::iterator i = backgroundStates->begin();i<backgroundStates->end();i++){
		delete *i;
	}
	backgroundStates->clear();
	curentState = NULL;
}

bool StateManager::isExit(){
	if(curentState==NULL){
		popAll();
		return true;
	}
	else return false;
}

void StateManager::onPhysicTick(){
	for(vector<State*>::iterator c = backgroundStates->begin();c<backgroundStates->end();c++){
		(*c)->onPhysicTick();
	}
	if(curentState!=NULL)curentState->onPhysicTick();
}

void StateManager::onRender(){
	for(vector<State*>::iterator c = backgroundStates->begin();c<backgroundStates->end();c++){
		(*c)->onRender();
	}
	if(curentState!=NULL)curentState->onRender();
}