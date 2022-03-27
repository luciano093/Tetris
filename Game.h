#ifndef GAME_H
#define GAME_H

#include<SDL.h>
#include<utility>
#include"Window.h"
#include"Tetromino.h"

namespace Game {
	extern std::vector<Tetromino*> tetrominos;
	extern Window* window;
	extern int delay;

	extern void start(Window* const window);
	extern void update();
	extern void eventHandler(const SDL_Keycode& keycode);

	// helper functions
	extern Tetromino* getRandomTetromino(const int x, const int y);

	extern bool hasReachedBottomLimit(const Tetromino* const tetromino);
	extern bool hasReachedLeftLimit(const Tetromino* const tetromino);
	extern bool hasReachedRightLimit(const Tetromino* const tetromino);

	extern bool hasCollidedBottom(const Tetromino* const tetromino);
	extern bool hasCollidedLeft(const Tetromino* const tetromino);
	extern bool hasCollidedRight(const Tetromino* const tetromino);

	extern bool canGoDown(const Tetromino* const tetromino);
	extern bool canGoLeft(const Tetromino* const tetromino);
	extern bool canGoRight(const Tetromino* const tetromino);

	extern bool isThereMino(const int x, const int y);
	extern bool testPos(std::pair<int, int> (&pos)[4]);
	extern void drop(Tetromino* const tetromino);
}

#endif