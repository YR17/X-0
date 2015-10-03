#ifndef BUTTON_H
	#define BUTTON_H
	#include <string>

	#include <GameState.h>

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

	class FieldButton: public Button{
		int xPos;
		int yPos;
		GameState *state;
	public:
		FieldButton(int, int, int, int,std::string, int, int, GameState*);
		~FieldButton(){};
		void onClick();
	};
#endif