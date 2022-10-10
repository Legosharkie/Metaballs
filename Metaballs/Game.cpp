#include "Game.h"

Game::Game()
{
	player.x = 0;
	player.y = 0;
	player.w = 100;
	player.h = 100;
	latest_action = SDLK_d;
}

Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, int res, double aspect, bool fullScreen)
{
	int flags = 0;
	
	if (fullScreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	windowRes = res;
	aspectRatio = aspect;
	std::vector<Cell> tmp;

	for (int i = 0; i < height; i+=res)
	{
		for (int j = 0; j < width; j+=res*aspect)
		{
			if (i == 0)
				ncol++;
			Cell c = Cell(res, aspect, j, i);
			
			tmp.push_back(c);

			//ncol++;
		}
		grid.push_back(tmp);
		tmp.clear();
		nrow++;
	}

	int Nballs = 7;
	int minR = 40;
	int maxR = 100;
	int minV = -3;
	int maxV = 3;

	int x, y, vx, vy, r;
	srand((unsigned)time(NULL));

	for (int i = 0; i < Nballs; i++)
	{
		r = (rand()%(maxR - minR)) + minR;
		x = (rand() % ((windowW - r) - r)) + r;
		y = (rand() % ((windowH - r) - r)) + r;
		vx = (rand() % (maxV-minV)) + minV;
		vy = (rand() % (maxV-minV)) + minV;
		Ball b = Ball(x, y, vx, vy, r);
		balls.push_back(b);
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Initializing..." << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		SDL_GetWindowSize(window, &windowW, &windowH);
		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
}

void Game::handleEvents(int *pause)
{
	SDL_Event event;

	SDL_PollEvent(&event);
	//const Uint8* state = SDL_GetKeyboardState(NULL);

	switch (event.type)
	{
		case SDL_MOUSEBUTTONDOWN:
			//mousePress(event.button);
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_p)
			{
				*pause = !(*pause);
				break;
			}
			latest_action = event.key.keysym.sym;
			break;
		case SDL_QUIT:
			isRunning = false;
			break;
		
		default:
			break;
	}
}
 
void Game::update()
{
	for (auto &b : balls)
	{
		//std::cout << "Pos before: " << b.x << "," << b.y << std::endl;
		b.Move();
		//std::cout << "Pos: " << b.x << "," << b.y << std::endl;
		b.CheckCollision(windowW, windowH);
	}
}

void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	
	SDL_SetRenderDrawColor(renderer, 126, 126, 126, 255);

	/*
	for (int row = 0; row < windowH; row+=windowRes)
	{
		SDL_RenderDrawLine(renderer, 0, row, windowW, row);
	}
	
	
	for (int col = 0; col < windowW; col+=windowRes*aspectRatio)
	{
		SDL_RenderDrawLine(renderer, col, 0, col, windowH);
	}
	*/
	
	for (auto x : grid)
	{
		for (auto y : x)
			y.render(renderer, y.getState(balls));
	}

	/*
	for (auto b : balls)
		b.render(renderer);
	*/

	

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Window destroyed!" << std::endl;
}

void Game::drawRect(int x, int y, int w, int h, int r, int g, int b)
{
	SDL_Rect rect;

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderFillRect(renderer, &rect);
}
