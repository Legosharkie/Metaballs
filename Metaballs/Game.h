#include <SDL.h>
#include <iostream>
#include <vector>
#include "Cell.h"
#include "Ball.h"
#include <vector>
#pragma once
class Game
{
	public:
		Game();
		~Game();

		void init(const char* title, int xpos, int ypos, int width, int height, int res, double aspect, bool fullScreen);
		
		void handleEvents(int* pause);
		void update();
		void render();
		void clean();

		bool running() { return isRunning; }
		void drawRect(int x, int y, int w, int h, int r, int g, int b);

	private:
		int count = 0;
		int windowH, windowW, windowRes, aspectRatio; 
		int ncol = 0; 
		int nrow = 0;
		bool isRunning;
		SDL_Window* window;
		SDL_Renderer* renderer;
		std::vector<std::vector<Cell>> grid;
		std::vector<Ball> balls;
		SDL_Rect player;
		SDL_Keycode latest_action;
};

