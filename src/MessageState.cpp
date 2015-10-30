#include <MessageState.h>
#include <EventManager.h>
#include <VideoManager.h>
using namespace std;

MessageState::MessageState(string message){
	this->message = message;
}

void MessageState::onActive(){
	closeButton = new StateButton(170, 300, 140, 40, "Back", NULL);
	EventManager::getImplementation()->bindButton(closeButton);
}

void MessageState::onPassive(){
	EventManager::getImplementation()->unbindButton(closeButton);
	delete closeButton;
}

void MessageState::onRender(){
	VideoManager::getImplementation()->fillRect(40, 190, 400, 60, 0, 0, 0, 230);
	VideoManager::getImplementation()->drawText(50, 200, 380, 40, message);
	VideoManager::getImplementation()->drawButton(closeButton);
}
