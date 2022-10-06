#include <SDL.h>
#pragma once
class Ball
{
	public:
		double r;
		double x,y;
		Ball(double x, double y, double vx, double vy, double r);
		void render(SDL_Renderer *renderer);
		~Ball();
		void Move();
		void CheckCollision(int W, int H);

	private:
		double vx,vy;
};

