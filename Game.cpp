#include"Game.h"
#include<random>
#include<ctime>
#include<vector>

std::vector<Tetromino*> Game::tetrominos;
Window* Game::window;
int Game::delay = 0;

void Game::start(Window* const window) {
	Game::window = window;
	srand(time(nullptr));
	tetrominos.push_back(getRandomTetromino((COLUMNS - 3) / 2, -1));
}

void Game::update() {
	while (delay++ > 1000) {
		if(canGoDown(tetrominos.back())) tetrominos.back()->goDown();
		else tetrominos.push_back(getRandomTetromino((COLUMNS - 3) / 2, -1));
		delay = 0;
	}
	
	for (Tetromino* const tetromino : tetrominos) {
		for (const Mino* mino : tetromino->getMinos()) {
			window->drawTexture(mino->getTexture(), mino->getRect());
		}
	}
}

void Game::eventHandler(const SDL_Keycode& keycode) {
	switch (keycode) {
	case SDLK_LEFT: if (canGoLeft(tetrominos.back())) tetrominos.back()->goLeft(); break;
	case SDLK_RIGHT: if (canGoRight(tetrominos.back())) tetrominos.back()->goRight(); break;
	case SDLK_DOWN: if (canGoDown(tetrominos.back())) tetrominos.back()->goDown(); break;
	case SDLK_SPACE: drop(tetrominos.back()); break;
	}
}

Tetromino* Game::getRandomTetromino(const int x, const int y) {
	unsigned char tetrominoNum = rand() % 7;

	switch (tetrominoNum) {
	case 0: return new Tetromino(Game::window, Tetromino::Type::I, x, y);
	case 1: return new Tetromino(Game::window, Tetromino::Type::J, x, y);
	case 2: return new Tetromino(Game::window, Tetromino::Type::L, x, y);
	case 3: return new Tetromino(Game::window, Tetromino::Type::O, x, y);
	case 4: return new Tetromino(Game::window, Tetromino::Type::S, x, y);
	case 5: return new Tetromino(Game::window, Tetromino::Type::T, x, y);
	case 6: return new Tetromino(Game::window, Tetromino::Type::Z, x, y);
	}

	return nullptr;
}

bool Game::hasReachedBottomLimit(const Tetromino* const tetromino) {
	return !(tetromino->getBottomY() < Game::window->getHeight() - Game::window->getGridSize());
}
bool Game::hasCollidedBottom(const Tetromino* const tetromino) {
	for (const Tetromino* const other : tetrominos) {
		if (tetromino == other) return false;

		for (const Mino* const otherMino : other->getMinos()) {
			for (const Mino* const mino : tetromino->getMinos()) {
				if (mino->getX() == otherMino->getX() && mino->getY() + mino->getSize() == otherMino->getY()) return true;
			}
		}
	}

	return false;
}

bool Game::canGoDown(const Tetromino* const tetromino) {
	return !hasReachedBottomLimit(tetromino) && !hasCollidedBottom(tetromino);
}

bool Game::hasReachedLeftLimit(const Tetromino* const tetromino) {
	return tetromino->getLeftmostX() <= 0;
}

bool Game::hasCollidedLeft(const Tetromino* const tetromino) {
	for (const Tetromino* const other : tetrominos) {
		if (tetromino == other) return false;

		for (const Mino* const otherMino : other->getMinos()) {
			for (const Mino* const mino : tetromino->getMinos()) {
				if (mino->getX() - mino->getSize() == otherMino->getX() && mino->getY() == otherMino->getY()) return true;
			}
		}
	}

	return false;
}

bool Game::canGoLeft(const Tetromino* const tetromino) {
	return !hasReachedLeftLimit(tetromino) && !hasCollidedLeft(tetromino);
}

bool Game::hasReachedRightLimit(const Tetromino* const tetromino) {
	return tetromino->getRightmostX() >= window->getWidth() - window->getGridSize();
}

bool Game::hasCollidedRight(const Tetromino* const tetromino) {
	for (const Tetromino* const other : tetrominos) {
		if (tetromino == other) return false;

		for (const Mino* const otherMino : other->getMinos()) {
			for (const Mino* const mino : tetromino->getMinos()) {
				if (mino->getX() + mino->getSize() == otherMino->getX() && mino->getY() == otherMino->getY()) return true;
			}
		}
	}

	return false;
}

bool Game::canGoRight(const Tetromino* const tetromino){
	return !hasReachedRightLimit(tetromino) && !hasCollidedRight(tetromino);
}

void Game::drop(Tetromino* const tetromino) {
	int targetY = tetromino->getBottomY();
	bool canStop = false;

	for (int nextY = targetY + window->getGridSize(); nextY <= window->getHeight(); nextY += window->getGridSize()) {
		for (const Tetromino* const other : tetrominos) {
			for (const Mino* mino : other->getMinos()) {
				if (nextY == mino->getY()) {
					canStop = true;
					break;
				}
			}
			if (canStop) break;
		}
		if (!canStop) {
			targetY = nextY;
		}
	}

	tetromino->setY(targetY);
}