#include "Cell.h"
#include <iostream>
#include <omp.h>
#include "Ball.h"

Cell::Cell(int res, double aspect, int x, int y)
{
	cell.x = x;
	cell.y = y;
	cell.w = res*aspect;
	cell.h = res;

	this->x = x;
	this->y = y;
	this->w = res * aspect;
	this->h = res;
}

Cell::~Cell()
{

}

void Cell::render(SDL_Renderer *renderer, int state)
{
 	//int state = getState();
	int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
	double midX, midY, midX2, midY2;

	Ax = x;
	Ay = y;

	Bx = x + w;
	By = y;

	Cx = x + w;
	Cy = y + h;

	Dx = x;
	Dy = y + h;
	

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	//SDL_RenderDrawLine(renderer, midX, y, x + w, midY);
	//SDL_RenderDrawLine(renderer, x, midY, midX, y + h);

	
	switch (state)
	{
	case 1:
	//	SDL_RenderDrawPoint(renderer, x, y + h);
		midY = Ay + (Dy - Ay) * ((1 - A_val) / (D_val - A_val));
		midX = Dx + (Cx - Dx) * ((1 - D_val) / (C_val - D_val));
		SDL_RenderDrawLine(renderer, x, midY, midX, y+h);
		break;

	case 2:
		midY = By + (Cy - By) * ((1 - B_val) / (C_val - B_val));
		midX = Dx + (Cx - Dx) * ((1 - D_val) / (C_val - D_val));
		//SDL_RenderDrawPoint(renderer, x+w, y + h);
		SDL_RenderDrawLine(renderer, x+w, midY, midX, y+h);
		break;

	case 3:
		midY = Ay + (Dy - Ay) * ((1 - A_val) / (D_val - A_val));
		midY2 = By + (Cy - By) * ((1 - B_val) / (C_val - B_val));
		SDL_RenderDrawLine(renderer, x, midY, x + w, midY2);
		break;

	case 4:
		midY = By + (Cy - By) * ((1 - B_val) / (C_val - B_val));
		midX = Bx + (Ax - Bx) * ((1 - B_val) / (A_val - B_val));
		SDL_RenderDrawLine(renderer, midX, y, x + w, midY);
		break;

	case 5:
		midY = Ay + (Dy - Ay) * ((1 - A_val) / (D_val - A_val));
		midX = Bx + (Ax - Bx) * ((1 - B_val) / (A_val - B_val));

		midY2 = By + (Cy - By) * ((1 - B_val) / (C_val - B_val));
		midX2 = Dx + (Cx - Dx) * ((1 - D_val) / (C_val - D_val));
		SDL_RenderDrawLine(renderer, x, midY, midX, y);
		SDL_RenderDrawLine(renderer, midX2, y+h, x + w, midY2);
		break;

	case 6:
		midX = Bx + (Ax - Bx) * ((1 - B_val) / (A_val - B_val));
		midX2 = Dx + (Cx - Dx) * ((1 - D_val) / (C_val - D_val));
		SDL_RenderDrawLine(renderer, midX, y, midX2, y+h);
		break;

	case 7:
		midY = Ay + (Dy - Ay) * ((1 - A_val) / (D_val - A_val));
		midX = Bx + (Ax - Bx) * ((1 - B_val) / (A_val - B_val));
		SDL_RenderDrawLine(renderer, x, midY, midX, y);
		break;

	case 8:
		midY = Ay + (Dy - Ay) * ((1 - A_val) / (D_val - A_val));
		midX = Bx + (Ax - Bx) * ((1 - B_val) / (A_val - B_val));
		SDL_RenderDrawLine(renderer, x, midY, midX, y);
		break;

	case 9:
		midX = Bx + (Ax - Bx) * ((1 - B_val) / (A_val - B_val));
		midX2 = Dx + (Cx - Dx) * ((1 - D_val) / (C_val - D_val));
		SDL_RenderDrawLine(renderer, midX, y, midX2, y + h);
		break;

	case 10:
		midY = Ay + (Dy - Ay) * ((1 - A_val) / (D_val - A_val));
		midX = Dx + (Cx - Dx) * ((1 - D_val) / (C_val - D_val));
		SDL_RenderDrawLine(renderer, x, midY, midX, y + h);

		midY2 = By + (Cy - By) * ((1 - B_val) / (C_val - B_val));
		midX2 = Bx + (Ax - Bx) * ((1 - B_val) / (A_val - B_val));
		SDL_RenderDrawLine(renderer, midX2, y, x + w, midY2);
		
		break;

	case 11:
		midY = By + (Cy - By) * ((1 - B_val) / (C_val - B_val));
		midX = Bx + (Ax - Bx) * ((1 - B_val) / (A_val - B_val));
		SDL_RenderDrawLine(renderer, midX, y, x + w, midY);
		break;

	case 12:
		midY = Ay + (Dy - Ay) * ((1 - A_val) / (D_val - A_val));
		midY2 = By + (Cy - By) * ((1 - B_val) / (C_val - B_val));
		SDL_RenderDrawLine(renderer, x, midY, x + w, midY2);
		break;

	case 13:
		midY = By + (Cy - By) * ((1 - B_val) / (C_val - B_val));
		midX = Dx + (Cx - Dx) * ((1 - D_val) / (C_val - D_val));
		SDL_RenderDrawLine(renderer, x + w, midY, midX, y + h);
		break;

	case 14:
		midY = Ay + (Dy - Ay) * ((1 - A_val) / (D_val - A_val));
		midX = Dx + (Cx - Dx) * ((1 - D_val) / (C_val - D_val));
		SDL_RenderDrawLine(renderer, x, midY, midX, y + h);
		break;

	case 15:
		break;

	default:
		break;
	}
	
}

int Cell::getState(std::vector<Ball> balls)
{
	/*
	
	A ---- B
	|      |
	|      |
	D----- C

	*/


	int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;

	Ax = x;
	Ay = y; 

	Bx = x + w;
	By = y;

	Cx = x + w;
	Cy = y + h;

	Dx = x;
	Dy = y + h;

	double sumA, sumB, sumC, sumD;
	sumA = 0;
	sumB = 0;
	sumC = 0;
	sumD = 0;

	for (auto ball : balls)
	{
		sumA += calcDist(Ax, Ay, ball);
		sumB += calcDist(Bx, By, ball);
		sumC += calcDist(Cx, Cy, ball);
		sumD += calcDist(Dx, Dy, ball);
	}
	A_val = sumA;
	B_val = sumB;
	C_val = sumC;
	D_val = sumD;

	A = 0;
	B = 0;
	C = 0;
	D = 0;

	if (sumA >= 1)
		A = 1;
	if (sumB >= 1)
		B = 1;
	if (sumC >= 1)
		C = 1;
	if (sumD >= 1)
		D = 1;

	return 1 * D + 2 * C + 4 * B + 8 * A;
}

double Cell::calcDist(int x, int y, Ball b)
{
	double xd = (x - b.x);
	double yd = (y - b.y);
	return b.r * b.r / (xd * xd + yd * yd);
}
