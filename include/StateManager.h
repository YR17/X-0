#ifndef STATE_MANAGER_H
	#define STATE_MANAGER_H
	#include <State.h>
	#include <vector>
	class StateManager{
	private:
		std::vector<State*> *states;
		std::vector<State*> *backgroundStates;
		State *curentState;
		static StateManager *pImplementation;
		StateManager();
	public:
		static StateManager *getImplementation();
		~StateManager();
		void pushBackgroundState(State *);
		void push(State*);
		void popBackgroundState();
		void pop();
		void popAll();
		bool isExit();
		void onPhysicTick();
		void onRender();
	};
#endif