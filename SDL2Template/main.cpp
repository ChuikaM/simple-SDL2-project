#include<SDL.h>
#include<iostream>

const int WIDTH = 840;
const int HEIGHT = 640;

SDL_Surface* surface = NULL;
SDL_Window* window = NULL;

int Init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { std::cerr << "Error! " << SDL_GetError(); return 1; }

	window = SDL_CreateWindow("SDL2",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WIDTH,
		HEIGHT,
		SDL_WINDOW_SHOWN);
	if (!window) { std::cerr << "Error! " << SDL_GetError(); return 1; }

	surface = SDL_GetWindowSurface(window);
	if (!surface) { std::cerr << "Error! " << SDL_GetError(); return 1; }
}

void Draw() {
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 0, 0));
	SDL_UpdateWindowSurface(window);
}

void Quit() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char ** args) {
	if (Init() == 1) { return 1; }
	bool run = true;

	SDL_Event* Event = new SDL_Event();
	while (run) {
		while (SDL_PollEvent(Event)) {
			if (Event->type == SDL_QUIT) {
				run = false;
			}			
		}
		Draw();
	}	

	delete Event;
	Quit();
}