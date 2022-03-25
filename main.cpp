#include<SDL.h>
#include"Window.h"
#include"Config.h"
#include"Game.h"

unsigned lastTime = 0;
unsigned currentTime;
int delay = 90;

int main(int argc, char* argv[]) {
	Window window("Tetris", 400, 800);
	window.createGrid(ROWS, COLUMNS);

	SDL_Event evt;
	bool running = true;

	Game::start(&window);

	while (running) {
		currentTime = SDL_GetTicks();

		while (SDL_PollEvent(&evt)) {
			if (evt.type == SDL_QUIT) running = false;
			else if (evt.type == SDL_KEYDOWN) {
				if (evt.key.keysym.sym == SDLK_EQUALS) delay -= 10;
				else if (evt.key.keysym.sym == SDLK_MINUS) delay += 10;
				else Game::eventHandler(evt.key.keysym.sym);
			}

		}

		window.clear();
		Game::update();
		window.present();

		lastTime = currentTime;
	}

	return 0;
}