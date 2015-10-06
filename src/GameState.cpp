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
	if(turn)field[x][y] = CROSS;
	else field[x][y] = ZERO;
	check();
	turn = !turn;
}

bool GameState::check(int x, int y, int length, Mark mark, Direction direction){
	if(x>=0&&y>=0&&x<3&&y<3&&field[x][y]==mark){
		std::cout<<x<<'\t'<<y<<"="<<field[x][y]<<std::endl;
		if(field[x][y]==CROSS)std::cout<<"CROSS"<<std::endl;
		else if(field[x][y]==ZERO)std::cout<<"ZERO"<<std::endl;
		else std::cout<<"NONE"<<std::endl;
		if(length==0)return true;
		else{
			switch(direction){
				case RIGHT: return check(x+1, y, length-1, mark, direction);
				break;
				case DOWN: return check(x, y-1, length-1, mark, direction);
				break;
				case DOWN_LEFT: return check(x-1, y-1, length-1, mark, direction);
				break;
				case DOWN_RIGHT: return check(x+1, y-1, length-1, mark, direction);
				break;
			}
		}
	}
	else return false;
}

void GameState::check(){
	if(check(0, 0, 1, CROSS, RIGHT)){
		std::cout<<"ok"<<std::endl;
	}
	else std::cout<<"no"<<std::endl;
}