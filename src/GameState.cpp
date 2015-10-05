#include <GameState.h>
#include <EventManager.h>
#include <VideoManager.h>
#include <Button.h>
#include <iostream>
#include <stdlib.h>


GameState::GameState(){
	buttons = new std::vector<Button*>;
	turn = true;
	field = new int*[3];
	for(int c=0;c<3;c++){
		field[c] = new int;
	}
	for(int c=0;c<3;c++){
		for(int c1=0;c1<3;c1++){
			field[c][c1] = 0;
		}
	}
}

void GameState::onActive(){
	for(int c=0;c<3;c++){
		for(int c1=0;c1<3;c1++){
			buttons->push_back(new FieldButton(170 + 50*c1, 170+50*c, 40, 40, "test", c1, c, this));
		}
	}
	buttons->push_back(new StateButton(170, 330, 140, 30, "Exit", NULL));

	for(auto i = buttons->begin();i<buttons->end();i++){
		EventManager::getImplementation()->bindButton(*i);
	}
}

void GameState::onPassive(){
	EventManager::getImplementation()->unbindAll();
	buttons->clear();
}

void GameState::onRender(){
	for(std::vector<Button*>::iterator i = buttons->begin();i<buttons->end();i++){
		VideoManager::getImplementation()->drawButton(*i);
	}
	for(int c=0;c<3;c++){
		for(int c1=0;c1<3;c1++){
			switch(field[c1][c]){
				case 1: VideoManager::getImplementation()->drawCross(180 + 50*c1, 180+50*c, 0, 255, 255, 255);
				break;
				case 2: VideoManager::getImplementation()->drawZero(180 + 50*c1, 180+50*c, 255, 255, 255);
				break;
			}
		}
	}
}

void GameState::mark(int x, int y, Button *button){
	EventManager::getImplementation()->unbindButton(button);
	turn = !turn;
	if(turn)field[x][y] = 1;
	else field[x][y] = 2;
	check();
}

void GameState::check(){
	
}