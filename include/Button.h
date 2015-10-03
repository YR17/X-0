#ifndef BUTTON_H
	#define BUTTON_H
	#include <string>
	#include <StateManager.h>
	class Button{
	protected:
		bool active;
	public:
		std::string text;
		int x, y, w, h;
		Button(){};
		virtual ~Button(){};
		bool isActive(){return active;};
		virtual void onClick(){};
		virtual void onMouseIn();
		virtual void onMouseOut();
	};

	class StateButton: public Button{
		State *onClickState;
	public:
		StateButton(int, int, int, int, std::string, State*);
		~StateButton(){};
		void onClick();
	};

	template<typename T>
	class CallerButton: public Button{
		T caller;
	public:
		CallerButton(int, int, int, int,std::string, T);
		~CallerButton(){};
		void onClick();
	};
#endif