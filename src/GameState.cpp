#include <GameState.h>
#include <StateManager.h>
#include <WinState.h>
#include <EventManager.h>
#include <VideoManager.h>
#include <Button.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

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
			buttons->push_back(new FieldButton(170 + 50*c1, 170+50*c, 40, 40, " ", c1, c, this));
		}
	}
	buttons->push_back(new StateButton(170, 330, 140, 30, "Back", NULL));

	for(auto i = buttons->begin();i<buttons->end();i++){
		EventManager::getImplementation()->bindButton(*i);
	}
}

void GameState::onPassive(){
	EventManager::getImplementation()->unbindAll();
	buttons->clear();
}

void GameState::onRender(){
	for(auto i = buttons->begin();i<buttons->end();i++){
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
	if(turn)field[x][y] = 1;
	else field[x][y] = 2;
	check();
	turn = !turn;
}

void GameState::check(){
	isDraw = true;
	for(int c=0;c<3;c++){
		result = 0;
		verticalSum = 0;
		horizontalSum = 0;
		mainDiagonalSum = 0;
		sideDiagonalSum =0;
		verticalFlag = true;
		horizontalFlag = true;
		mainDiagonalFlag = true;
		sideDiagonalFlag = true;
		for(int c1=0;c1<3;c1++){
			if(field[c][c1]==0)isDraw = false;
			if(!field[c][c1])verticalFlag = false;
			if(!field[c1][c])horizontalFlag = false;
			if(!field[c1][c1])mainDiagonalFlag = false;
			if(!field[2-c1][2-c1])sideDiagonalFlag = false;
			verticalSum+=field[c][c1];
			horizontalSum+=field[c1][c];
			mainDiagonalSum+=field[c1][c1];
			sideDiagonalSum+=field[2-c1][2-c1];
		}
		if(verticalFlag){
			if(verticalSum==3||verticalSum==6){
				if(verticalSum==3){
					// cout<<"CROSS WINS"<<endl;
					// exit(0);
					StateManager::getImplementation()->push(new WinState("CROSS WINS"));
				}
				else{
					// cout<<"ZEROS WINS"<<endl;
					// exit(0);
					StateManager::getImplementation()->push(new WinState("ZEROS WINS"));
				}
			}
		}
		if(horizontalFlag){
			if(horizontalSum==3||horizontalSum==6){
				if(horizontalSum==3){
					// cout<<"CROSS WINS"<<endl;
					// exit(0);
					StateManager::getImplementation()->push(new WinState("CROSS WINS"));
				}
				else{
					// cout<<"ZEROS WINS"<<endl;
					// exit(0);
					StateManager::getImplementation()->push(new WinState("ZEROS WINS"));
				}
			}
		}
		if(mainDiagonalFlag){
			if(mainDiagonalSum==3||mainDiagonalSum==6){
				if(mainDiagonalSum==3){
					// cout<<"CROSS WINS"<<endl;
					// exit(0);
					StateManager::getImplementation()->push(new WinState("CROSS WINS"));
				}
				else{
					// cout<<"ZEROS WINS"<<endl;
					// exit(0);
					StateManager::getImplementation()->push(new WinState("ZEROS WINS"));
				}
			}
		}
		if(sideDiagonalFlag){
			if(sideDiagonalSum==3||sideDiagonalSum==6){
				if(sideDiagonalSum==3){
					// cout<<"CROSS WINS"<<endl;
					// exit(0);
					StateManager::getImplementation()->push(new WinState("CROSS WINS"));
				}
				else{
					// cout<<"ZEROS WINS"<<endl;
					// exit(0);
					StateManager::getImplementation()->push(new WinState("ZEROS WINS"));
				}
			}
		}
	}
	if(isDraw)StateManager::getImplementation()->push(new WinState("DRAW"));
}

GameState::~GameState(){
	for(int c=0;c<3;c++){
		delete field[c];
	}
	delete field;
	for(auto i=buttons->begin();i<buttons->end();i++){
		delete *i;
	}
	buttons->clear();
	delete buttons;
}