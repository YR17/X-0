#ifndef STATE_H
	#define STATE_H
	// #define DEBUG_FLAG
	class State{
	public:
		State(){};
		virtual ~State(){};
		virtual void onRender() = 0;
		virtual void onPhysicTick() = 0;
		virtual void onActive() = 0;
		virtual void onPassive() = 0;
	};
#endif