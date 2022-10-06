#include "Ball.h"
#include <iostream>

Ball::Ball(double x, double y, double vx, double vy, double r)
{
	this->x = x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
	this->r = r;
}

Ball::~Ball()
{

}

void Ball::render(SDL_Renderer *renderer)
{

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
	//SDL_RenderFillRect(renderer, &rec);
	SDL_RenderDrawLine(renderer, x - r, y, x + r, y);
	SDL_RenderDrawLine(renderer, x, y - r, x, y + r);
}

void Ball::Move()
{
	//std::cout << "Pos before: " << x << "," << y << std::endl;

	x += vx;
	y += vy;

	//std::cout << "Pos: " << x << "," << y << std::endl;
	//std::cout << "Vel: " << vx << "," << vy << std::endl;
}

void Ball::CheckCollision(int W, int H)
{
	if (x + r >= W && vx > 0)
	{
		x = W - r;
		vx = -vx;
	//	std::cout << "BONK: Right wall" << std::endl;
	}
	if (x <= r && vx < 0)
	{
		x = r;
		vx = -vx;
	//	std::cout << "BONK: Left wall" << std::endl;
	}
	if (y + r >= H && vy > 0)
	{
		y = H - r;
		vy = -vy;
	//	std::cout << "BONK: Down" << std::endl;
	}
	if (y <= r && vy < 0)
	{
		y = r;
		vy = -vy;
	//	std::cout << "BONK: Up" << std::endl;
	}
	
}
