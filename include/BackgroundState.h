#ifndef BACKGROUND_STATE_H
	#define BACKGROUND_STATE_H
	#include <State.h>
	#include <VideoManager.h>
	#include <vector>
	#include <time.h>
	#include <stdlib.h>

	#define SPACE_COEFICIENT 30
	#define ELEMENTS_SPEED 0.5

	enum BackgroundElementType{ZERO, CROSS};

	struct BackgroundElement{

		
		BackgroundElementType backgroundElementType;
		int r, g, b;
		float x, y, angle, rotationSpeed;
	};

	class BackgroundState: public State{
	std::vector<BackgroundElement*> *backgroundElements;
	BackgroundElement *temp;
	public:
		BackgroundState();
		~BackgroundState();
		void onRender();
		void onPhysicTick();
		void onEvent(){};
		void onActive(){};
		void onPassive(){};
		void onClick(int){};
	};
#endif