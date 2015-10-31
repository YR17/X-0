#include <BackgroundState.h>

BackgroundState::BackgroundState(){
	backgroundElements = new std::vector<BackgroundElement*>;
	BackgroundElement *temp;
	for(int c=0;c<SCREEN_HEIGHT/SPACE_COEFICIENT-6;c++){
		for(int c1=0;c1<SCREEN_WIDTH/SPACE_COEFICIENT-6;c1++){
			temp = new BackgroundElement;
			if(rand()%2)temp->backgroundElementType = CROSS;
			else temp->backgroundElementType = ZERO;
			temp->x = c1 * (MARK_WIDTH + SPACE_COEFICIENT);
			temp->y = c * (MARK_HEIGHT + SPACE_COEFICIENT);
			temp->r = rand()%256;
			temp->g = rand()%256;
			temp->b = rand()%256;
			temp->angle = rand()%46;
			temp->rotationSpeed = (rand()%21)/10;
			backgroundElements->push_back(temp);
		}
	}
}

void BackgroundState::onRender(){
	BackgroundElement *temp;
	for(auto i = backgroundElements->begin();i<backgroundElements->end();i++){
		temp = *i;
		if(temp->backgroundElementType==ZERO){
			VideoManager::getImplementation()->drawZero(temp->x, temp->y, temp->r, temp->g, temp->b);
		}
		else{
			VideoManager::getImplementation()->drawCross(temp->x, temp->y, temp->angle, temp->r, temp->g, temp->b);
		}
	}
}

void BackgroundState::onPhysicTick(){
	for(auto i = backgroundElements->begin();i<backgroundElements->end();i++){
		temp = *i;
		if(temp->x>SCREEN_WIDTH){
			temp->x = -MARK_WIDTH;
			if(rand()%2)temp->backgroundElementType = CROSS;
			else temp->backgroundElementType = ZERO;
			temp->r = rand()%256;
			temp->g = rand()%256;
			temp->b = rand()%256;
			temp->angle = rand()%46;
			temp->rotationSpeed = (rand()%21)/10;
		}
		temp->angle += temp->rotationSpeed;
		temp->x += ELEMENTS_SPEED;
	}
}

BackgroundState::~BackgroundState(){
	for(auto i = backgroundElements->begin();i<backgroundElements->end();i++){
		delete *i;
	}
	delete backgroundElements;
}