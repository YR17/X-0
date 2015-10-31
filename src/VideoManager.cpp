#include <VideoManager.h>

#include <iostream>
#include <SDL2/SDL_image.h>
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
	TTF_Init();
	window = SDL_CreateWindow("X&0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	resetRenderDrawColor();
	SDL_Surface *temp = IMG_Load("../data/images/Cross.png");
	cross = SDL_CreateTextureFromSurface(render, temp);
	SDL_FreeSurface(temp);
	temp = IMG_Load("../data/images/Zero.png");
	zero = SDL_CreateTextureFromSurface(render, temp);
	font = TTF_OpenFont("../data/fonts/UbuntuMono-B.ttf", 48);
	SDL_FreeSurface(temp);

	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 0;
}

void VideoManager::clearRender(){
	SDL_RenderClear(render);
}

void VideoManager::drawCross(int x, int y, int angle, int r = 255, int g = 255, int b = 255){
	rect.x = x;
	rect.y = y;
	rect.w = MARK_WIDTH;
	rect.h = MARK_HEIGHT;
	SDL_SetTextureColorMod(cross, r, g, b);
	SDL_RenderCopyEx(render, cross, NULL, &rect, angle, NULL, SDL_FLIP_NONE);
}

void VideoManager::drawZero(int x, int y, int r = 255, int g = 255, int b = 255){
	rect.x = x;
	rect.y = y;
	rect.w = MARK_WIDTH;
	rect.h = MARK_HEIGHT;
	SDL_SetTextureColorMod(zero, r, g, b);
	SDL_RenderCopy(render, zero, NULL, &rect);
}

void VideoManager::fillRect(int x, int y, int w, int h, int r, int g, int b, int a){
	SDL_SetRenderDrawColor(render, r, g, b, a);
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);
	SDL_RenderFillRect(render, &rect);
	resetRenderDrawColor();
}

void VideoManager::drawRect(int x, int y, int w, int h, int r, int g, int b){
	SDL_SetRenderDrawColor(render, r, g, b, 255);
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);
	SDL_RenderDrawRect(render, &rect);
	resetRenderDrawColor();
}

void VideoManager::drawButton(Button* button){
	if(button->isActive())fillRect(button->x, button->y, button->w, button->h, 0, 0, 0, 200);
	else fillRect(button->x, button->y, button->w, button->h, 0, 0, 0, 230);
	drawText(button->x, button->y, button->w, button->h, button->text);
}

void VideoManager::drawText(int x, int y, int w, int h, string text){
	temp = TTF_RenderText_Solid(font, text.c_str(), color);
	texture = SDL_CreateTextureFromSurface(render, temp);
	SDL_FreeSurface(temp);
	rect.x = x + (w - 18 * text.length())/2;
	rect.y = y + (h-18)/2;
	rect.h = 18;
	rect.w = 18 * text.length();
	SDL_RenderCopy(render, texture, NULL, &rect);
	SDL_DestroyTexture(texture);
}

void VideoManager::presentRender(){
	SDL_RenderPresent(render);
}

VideoManager::~VideoManager(){
	SDL_DestroyTexture(cross);
	SDL_DestroyTexture(zero);
}