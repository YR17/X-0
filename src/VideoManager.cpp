#include <VideoManager.h>

#include <iostream>
using namespace std;

VideoManager *VideoManager::pImplementation = NULL;

VideoManager *VideoManager::getImplementation(){
	if(!pImplementation)pImplementation = new VideoManager();
	return pImplementation;
}

void VideoManager::resetRenderDrawColor(){
	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
}

VideoManager::VideoManager(){
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	window = SDL_CreateWindow("X&0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	resetRenderDrawColor();
	SDL_Surface *temp = IMG_Load("../data/images/Cross.png");
	cross = SDL_CreateTextureFromSurface(render, temp);
	SDL_FreeSurface(temp);
	temp = IMG_Load("../data/images/Zero.png");
	zero = SDL_CreateTextureFromSurface(render, temp);
	SDL_FreeSurface(temp);
}

void VideoManager::clearRender(){
	SDL_RenderClear(render);
}

void VideoManager::drawCross(int x, int y, int angle, int r = 255, int g = 255, int b = 255){
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = MARK_WIDTH;
	rect.h = MARK_HEIGHT;
	SDL_SetTextureColorMod(cross, r, g, b);
	SDL_RenderCopyEx(render, cross, NULL, &rect, angle, NULL, SDL_FLIP_NONE);
}

void VideoManager::drawZero(int x, int y, int r = 255, int g = 255, int b = 255){
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = MARK_WIDTH;
	rect.h = MARK_HEIGHT;
	SDL_SetTextureColorMod(zero, r, g, b);
	SDL_RenderCopy(render, zero, NULL, &rect);
}

void VideoManager::fillRect(int x, int y, int w, int h, int r, int g, int b, int a){
	SDL_Rect *rect = new SDL_Rect();
	SDL_SetRenderDrawColor(render, r, g, b, a);
	rect->x = x;
	rect->y = y;
	rect->w = w;
	rect->h = h;
	SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);
	SDL_RenderFillRect(render, rect);
	resetRenderDrawColor();
}

void VideoManager::drawRect(int x, int y, int w, int h, int r, int g, int b){
	SDL_Rect *rect = new SDL_Rect();
	SDL_SetRenderDrawColor(render, r, g, b, 255);
	rect->x = x;
	rect->y = y;
	rect->w = w;
	rect->h = h;
	SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);
	SDL_RenderDrawRect(render, rect);
	resetRenderDrawColor();
}

// void VideoManager::drawMenuButton(Button *button){
// 	if(button->isActive())fillRect(button->x, button->y, button->w, button->h, 7, 29, 197, 200);
// 	// else fillRect(button->x, button->y, button->w, button->h, 7, 29, 197, 255);
// 	else fillRect(button->x, button->y, button->w, button->h, 0, 200, 0, 230);
// }

void VideoManager::drawButton(Button* button){
	if(button->isActive())fillRect(button->x, button->y, button->w, button->h, 0, 0, 0, 200);
	else fillRect(button->x, button->y, button->w, button->h, 0, 0, 0, 230);
}

void VideoManager::presentRender(){
	SDL_RenderPresent(render);
}

VideoManager::~VideoManager(){
	SDL_DestroyTexture(cross);
	SDL_DestroyTexture(zero);
}