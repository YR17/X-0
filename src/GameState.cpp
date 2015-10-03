#include <GameState.h>

GameState::GameState(){
	buttons = new std::vector<Button*>;
	for(int c=0;c<3;c++){
		for(int c1=0;c1<3;c1++){
			// buttons->push_back(new StateButton(170 + 50*c1, 170+50*c, 40, 40, "X", NULL));
		}
	}
	// buttons->push_back(new StateButton(170, 330, 140, 30, "Exit", NULL));
}

void GameState::onActive(){
	for(auto i = buttons->begin();i<buttons->end();i++){
		EventManager::getImplementation()->bindButton(buttons->back());
	}

}

void GameState::onRender(){
	for(std::vector<Button*>::iterator i = buttons->begin();i<buttons->end();i++){
		VideoManager::getImplementation()->drawButton(*i);
	}
}

void GameState::onClick(int xPos, int yPos){
	// field[xPos][yPos] = turn;
	// if(turn==CROSS_BUTTON)turn = ZERO_BUTTON;
	// else turn = CROSS_BUTTON;
}