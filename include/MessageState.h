#ifndef MESSAGE_STATE_H
	#define MESSAGE_STATE_H
	#include <State.h>
	#include <Button.h>
	#include <iostream>

	class MessageState: public State{
		std::string message;
		Button *closeButton;
	public:
		MessageState(std::string);
		virtual ~MessageState(){};
		void onActive();
		void onPassive();
		void onRender();
		void onPhysicTick(){};
		void onClick(int){};
	};
#endif