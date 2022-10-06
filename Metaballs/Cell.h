#include <SDL.h>
#include <vector>
#include "Ball.h"

#pragma once
class Cell
{
	public:
		Cell(int res, double aspect, int x, int y);
		~Cell();
		void render(SDL_Renderer* renderer, int state);
		int getState(std::vector<Ball> balls);
		double calcDist(int x, int y, Ball b);
		int A, B, C, D;
		double A_val, B_val, C_val, D_val;
		
	private:
		int x, y, w, h;
		SDL_Rect cell;
};

