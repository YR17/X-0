#ifndef VIDEO_MANAGER_H
	#define VIDEO_MANAGER_H

	#define SCREEN_WIDTH 480
	#define SCREEN_HEIGHT 480

	#define MARK_WIDTH 20
	#define MARK_HEIGHT 20

	#include <SDL2/SDL.h>
	#include <SDL2/SDL_ttf.h>
	#include <Button.h>
	class VideoManager{
		SDL_Renderer *render;
		SDL_Window *window;
		SDL_Texture *cross, *zero;
		TTF_Font *font;
		static VideoManager *pImplementation;
		VideoManager();
		void resetRenderDrawColor();
	public:
		static VideoManager *getImplementation();
		~VideoManager();
		void clearRender();
		void drawCross(int, int, int, int, int, int);
		void drawZero(int, int, int, int, int);
		void fillRect(int, int, int, int, int, int, int, int);
		void drawRect(int, int, int, int, int, int, int);
		void drawButton(Button*);
		void drawText(int, int, int, int, std::string);
		void presentRender();
	};
#endif