#ifndef STATE_H
	#define STATE_H
	class State{
	public:
		State(){};
		virtual ~State(){};
		virtual void onRender() = 0;
		virtual void onPhysicTick() = 0;
		virtual void onActive() = 0;
		virtual void onPassive() = 0;
		virtual void onClick(int) = 0;
	};
#endif