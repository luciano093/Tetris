#include"Tetromino.h"

Tetromino::Tetromino(Window* const window, const Type& type, int x, int y) : window(window), type(type) {
	switch (type) {
	case Type::I:
		minos[0] = new Mino(window, x, y, SDL_Color{ 13, 243, 255 });
		minos[1] = new Mino(window, x + 1, y, SDL_Color{ 13, 243, 255 });
		minos[2] = new Mino(window, x + 2, y, SDL_Color{ 13, 243, 255 });
		minos[3] = new Mino(window, x + 3, y, SDL_Color{ 13, 243, 255 });
		break;
	case Type::J:
		minos[0] = new Mino(window, x, y - 1, SDL_Color{ 13, 16, 217 });
		minos[1] = new Mino(window, x, y, SDL_Color{ 13, 16, 217 });
		minos[2] = new Mino(window, x + 1, y, SDL_Color{ 13, 16, 217 });
		minos[3] = new Mino(window, x + 2, y, SDL_Color{ 13, 16, 217 });
		break;
	case Type::L:
		minos[0] = new Mino(window, x, y, SDL_Color{ 255, 170, 13 });
		minos[1] = new Mino(window, x + 1, y, SDL_Color{ 255, 170, 13 });
		minos[2] = new Mino(window, x + 2, y, SDL_Color{ 255, 170, 13 });
		minos[3] = new Mino(window, x + 2, y - 1, SDL_Color{ 255, 170, 13 });
		break;
	case Type::O:
		minos[0] = new Mino(window, x + 1, y, SDL_Color{ 245, 234, 22 });
		minos[1] = new Mino(window, x + 1, y - 1, SDL_Color{ 245, 234, 22 });
		minos[2] = new Mino(window, x + 2, y, SDL_Color{ 245, 234, 22 });
		minos[3] = new Mino(window, x + 2, y - 1, SDL_Color{ 245, 234, 22 });
		break;
	case Type::S:
		minos[0] = new Mino(window, x, y, SDL_Color{ 22, 245, 26 });
		minos[1] = new Mino(window, x + 1, y, SDL_Color{ 22, 245, 26 });
		minos[2] = new Mino(window, x + 1, y - 1, SDL_Color{ 22, 245, 26 });
		minos[3] = new Mino(window, x + 2, y - 1, SDL_Color{ 22, 245, 26 });
		break;
	case Type::T:
		minos[0] = new Mino(window, x, y, SDL_Color{ 235, 26, 235 });
		minos[1] = new Mino(window, x + 1, y, SDL_Color{ 235, 26, 235 });
		minos[2] = new Mino(window, x + 1, y - 1, SDL_Color{ 235, 26, 235 });
		minos[3] = new Mino(window, x + 2, y, SDL_Color{ 235, 26, 235 });
		break;
	case Type::Z:
		minos[0] = new Mino(window, x, y - 1, SDL_Color{ 235, 26, 40 });
		minos[1] = new Mino(window, x + 1, y  - 1, SDL_Color{ 235, 26, 40 });
		minos[2] = new Mino(window, x + 1, y, SDL_Color{ 235, 26, 40 });
		minos[3] = new Mino(window, x + 2, y, SDL_Color{ 235, 26, 40 });
		break;
	};
}

Tetromino::~Tetromino() {
	for (Mino* mino : minos) {
		delete mino;
	}
}

void Tetromino::goDown() {
	for (Mino* const mino : minos) {
		mino->shiftY(1);
	}
}

void Tetromino::goLeft() {
	for (Mino* const mino : minos) {
		mino->shiftX(-1);
	}
}

void Tetromino::goRight() {
	for (Mino* const mino : minos) {
		mino->shiftX(1);
	}
}

void Tetromino::setY(const int& y) {
	switch (type) {
	case Type::I:
		if (rotation == 1 || rotation == 3) {
			minos[0]->setY(y);
			minos[1]->setY(y);
			minos[2]->setY(y);
			minos[3]->setY(y);
		}
		else if (rotation == 2) {
			minos[0]->setY(y - 3 * minos[0]->getSize());
			minos[1]->setY(y - 2 * minos[0]->getSize());
			minos[2]->setY(y - minos[0]->getSize());
			minos[3]->setY(y);
		}
		else if (rotation == 3) {
			minos[0]->setY(y);
			minos[1]->setY(y - minos[0]->getSize());
			minos[2]->setY(y - 2 * minos[0]->getSize());
			minos[3]->setY(y - 3 * minos[0]->getSize());
		}
		break;
	case Type::J:
		if (rotation == 1) {
			minos[0]->setY(y - minos[0]->getSize());
			minos[1]->setY(y);
			minos[2]->setY(y);
			minos[3]->setY(y);
		}
		else if (rotation == 2) {
			minos[0]->setY(y - 2 * minos[0]->getSize());
			minos[1]->setY(y - 2 * minos[0]->getSize());
			minos[2]->setY(y - minos[0]->getSize());
			minos[3]->setY(y);
		}
		else if (rotation == 3) {
			minos[0]->setY(y);
			minos[1]->setY(y - minos[0]->getSize());
			minos[2]->setY(y - minos[0]->getSize());
			minos[3]->setY(y - minos[0]->getSize());
		}
		else if (rotation == 4) {
			minos[0]->setY(y);
			minos[1]->setY(y);
			minos[2]->setY(y - minos[0]->getSize());
			minos[3]->setY(y - 2 * minos[0]->getSize());
		}
		break;
	case Type::L:
		if (rotation == 1) {
			minos[0]->setY(y);
			minos[1]->setY(y);
			minos[2]->setY(y);
			minos[3]->setY(y - minos[0]->getSize());
		}
		else if (rotation == 2) {
			minos[0]->setY(y - 2 * minos[0]->getSize());
			minos[1]->setY(y - minos[0]->getSize());
			minos[2]->setY(y);
			minos[3]->setY(y);
		}
		else if (rotation == 3) {
			minos[0]->setY(y - minos[0]->getSize());
			minos[1]->setY(y - minos[0]->getSize());
			minos[2]->setY(y - minos[0]->getSize());
			minos[3]->setY(y);
		}
		else if (rotation == 4) {
			minos[0]->setY(y);
			minos[1]->setY(y - minos[0]->getSize());
			minos[2]->setY(y - 2 * minos[0]->getSize());
			minos[3]->setY(y - 2 * minos[0]->getSize());
		}
		break;
	case Type::O:
			minos[0]->setY(y);
			minos[1]->setY(y - minos[0]->getSize());
			minos[2]->setY(y);
			minos[3]->setY(y - minos[0]->getSize());
		break;
	case Type::S:
		if (rotation == 1) {
			minos[0]->setY(y);
			minos[1]->setY(y);
			minos[2]->setY(y - minos[0]->getSize());
			minos[3]->setY(y - minos[0]->getSize());
		}
		else if (rotation == 2) {
			minos[0]->setY(y - 2 * minos[0]->getSize());
			minos[1]->setY(y - minos[0]->getSize());
			minos[2]->setY(y - minos[0]->getSize());
			minos[3]->setY(y);
		}
		else if (rotation == 3) {
			minos[0]->setY(y - minos[0]->getSize());
			minos[1]->setY(y - minos[0]->getSize());
			minos[2]->setY(y);
			minos[3]->setY(y);
		}
		else if (rotation == 4) {
			minos[0]->setY(y);
			minos[1]->setY(y - minos[0]->getSize());
			minos[2]->setY(y - minos[0]->getSize());
			minos[3]->setY(y - 2 * minos[0]->getSize());
		}
		break;
	case Type::T:
		if (rotation == 1) {
			minos[0]->setY(y);
			minos[1]->setY(y);
			minos[2]->setY(y - minos[0]->getSize());
			minos[3]->setY(y);
		}
		else if (rotation == 2) {
			minos[0]->setY(y - 2 * minos[0]->getSize());
			minos[1]->setY(y - minos[0]->getSize());
			minos[2]->setY(y - minos[0]->getSize());
			minos[3]->setY(y);
		}
		else if (rotation == 3) {
			minos[0]->setY(y - minos[0]->getSize());
			minos[1]->setY(y - minos[0]->getSize());
			minos[2]->setY(y);
			minos[3]->setY(y - minos[0]->getSize());
		}
		else if (rotation == 4) {
			minos[0]->setY(y);
			minos[1]->setY(y - minos[0]->getSize());
			minos[2]->setY(y - minos[0]->getSize());
			minos[3]->setY(y - 2 *  minos[0]->getSize());
		}
		break;
	case Type::Z: 
		if (rotation == 1) {
			minos[0]->setY(y - minos[0]->getSize());
			minos[1]->setY(y - minos[0]->getSize());
			minos[2]->setY(y);
			minos[3]->setY(y);
		}
		else if (rotation == 2) {
			minos[0]->setY(y - 2 * minos[0]->getSize());
			minos[1]->setY(y - minos[0]->getSize());
			minos[2]->setY(y - minos[0]->getSize());
			minos[3]->setY(y);
		}
		else if (rotation == 3) {
			minos[0]->setY(y);
			minos[1]->setY(y);
			minos[2]->setY(y - minos[0]->getSize());
			minos[3]->setY(y - minos[0]->getSize());
		}
		else if (rotation == 4) {
			minos[0]->setY(y);
			minos[1]->setY(y - minos[0]->getSize());
			minos[2]->setY(y - minos[0]->getSize());
			minos[3]->setY(y - 2 * minos[0]->getSize());
		}
		break;
	}
}

const int Tetromino::getBottomY() const {
	switch (type) {
	case Type::I:
		if (rotation == 1) return minos[0]->getY();
		else if (rotation == 2) return minos[3]->getY();
		else if (rotation == 3) return minos[0]->getY();
		else if (rotation == 4) return minos[0]->getY();
	case Type::J: 
		if (rotation == 1) return minos[1]->getY();
		else if (rotation == 2) return minos[3]->getY();
		else if (rotation == 3) return minos[0]->getY();
		else if (rotation == 4) return minos[0]->getY();
	case Type::L:
		if (rotation == 1) return minos[0]->getY();
		else if (rotation == 2) return minos[3]->getY();
		else if (rotation == 3) return minos[3]->getY();
		else if (rotation == 4) return minos[0]->getY();
	case Type::O: return minos[0]->getY();
	case Type::S:
		if (rotation == 1) return minos[0]->getY();
		else if (rotation == 2) return minos[3]->getY();
		else if (rotation == 3) return minos[3]->getY();
		else if (rotation == 4) return minos[0]->getY();
	case Type::T:
		if (rotation == 1) return minos[0]->getY();
		else if (rotation == 2) return minos[3]->getY();
		else if (rotation == 3) return minos[2]->getY();
		else if (rotation == 4) return minos[0]->getY();
	case Type::Z:
		if (rotation == 1) return minos[2]->getY();
		else if (rotation == 2) return minos[3]->getY();
		else if (rotation == 3) return minos[0]->getY();
		else if (rotation == 4) return minos[0]->getY();
	}

	return 0;
}

const int Tetromino::getLeftmostX() const {
	switch (type) {
	case Type::I:
		if (rotation == 1) return minos[0]->getX();
		else if (rotation == 2) return minos[0]->getX();
		else if (rotation == 3) return minos[3]->getX();
		else if (rotation == 4) return minos[0]->getX();
	case Type::J:
		if (rotation == 1) return minos[0]->getX();
		else if (rotation == 2) return minos[1]->getX();
		else if (rotation == 3) return minos[3]->getX();
		else if (rotation == 4) return minos[0]->getX();
	case Type::L:
		if (rotation == 1) return minos[0]->getX();
		else if (rotation == 2) return minos[0]->getX();
		else if (rotation == 3) return minos[3]->getX();
		else if (rotation == 4) return minos[3]->getX();
	case Type::O: return minos[0]->getX();
	case Type::S:
		if (rotation == 1) return minos[0]->getX();
		else if (rotation == 2) return minos[0]->getX();
		else if (rotation == 3) return minos[3]->getX();
		else if (rotation == 4) return minos[3]->getX();
	case Type::T:
		if (rotation == 1) return minos[0]->getX();
		else if (rotation == 2) return minos[0]->getX();
		else if (rotation == 3) return minos[3]->getX();
		else if (rotation == 4) return minos[2]->getX();
	case Type::Z:
		if (rotation == 1) return minos[0]->getX();
		else if (rotation == 2) return minos[2]->getX();
		else if (rotation == 3) return minos[3]->getX();
		else if (rotation == 4) return minos[0]->getX();
	}

	return 0;
}

const int Tetromino::getRightmostX() const {
	switch (type) {
	case Type::I:
		if (rotation == 1) return minos[3]->getX();
		else if (rotation == 2) return minos[0]->getX();
		else if (rotation == 3) return minos[0]->getX();
		else if (rotation == 4) return minos[0]->getX();
	case Type::J:
		if (rotation == 1) return minos[3]->getX();
		else if (rotation == 2) return minos[0]->getX();
		else if (rotation == 3) return minos[0]->getX();
		else if (rotation == 4) return minos[3]->getX();
	case Type::L:
		if (rotation == 1) return minos[3]->getX();
		else if (rotation == 2) return minos[3]->getX();
		else if (rotation == 3) return minos[0]->getX();
		else if (rotation == 4) return minos[0]->getX();
	case Type::O: return minos[3]->getX();
	case Type::S:
		if (rotation == 1) return minos[3]->getX();
		else if (rotation == 2) return minos[3]->getX();
		else if (rotation == 3) return minos[0]->getX();
		else if (rotation == 4) return minos[0]->getX();
	case Type::T:
		if (rotation == 1) return minos[3]->getX();
		else if (rotation == 2) return minos[2]->getX();
		else if (rotation == 3) return minos[0]->getX();
		else if (rotation == 4) return minos[0]->getX();
	case Type::Z:
		if (rotation == 1) return minos[3]->getX();
		else if (rotation == 2) return minos[0]->getX();
		else if (rotation == 3) return minos[0]->getX();
		else if (rotation == 4) return minos[3]->getX();
	}

	return 0;
}

void Tetromino::rotate() {
	switch (type) {
	case Type::I: 
		if (rotation == 1) {
			++rotation;
			minos[0]->shiftX(2);
			minos[0]->shiftY(-1);
			minos[1]->shiftX(1);
			minos[2]->shiftY(1);
			minos[3]->shiftX(-1);
			minos[3]->shiftY(2);
		}
		else if (rotation == 2) {
			++rotation;
			minos[0]->shiftX(1);
			minos[0]->shiftY(2);
			minos[1]->shiftY(1);
			minos[2]->shiftX(-1);
			minos[3]->shiftX(-2);
			minos[3]->shiftY(-1);
		}
		else if (rotation == 3) {
			++rotation;
			minos[0]->shiftX(-2);
			minos[0]->shiftY(1);
			minos[1]->shiftX(-1);
			minos[2]->shiftY(-1);
			minos[3]->shiftX(1);
			minos[3]->shiftY(-2);
		}
		else if (rotation == 4) {
			rotation = 1;
			minos[0]->shiftX(-1);
			minos[0]->shiftY(-2);
			minos[1]->shiftY(-1);
			minos[2]->shiftX(1);
			minos[3]->shiftX(2);
			minos[3]->shiftY(1);
		}
		break;
	case Type::J: 
		if (rotation == 1) {
			++rotation;
			minos[0]->shiftX(2);
			minos[1]->shiftX(1);
			minos[1]->shiftY(-1);
			minos[3]->shiftX(-1);
			minos[3]->shiftY(1);
		}
		else if (rotation == 2) {
			++rotation;
			minos[0]->shiftY(2);
			minos[1]->shiftX(1);
			minos[1]->shiftY(1);
			minos[3]->shiftX(-1);
			minos[3]->shiftY(-1);
		}
		else if (rotation == 3) {
			++rotation;
			minos[0]->shiftX(-2);
			minos[1]->shiftX(-1);
			minos[1]->shiftY(1);
			minos[3]->shiftX(1);
			minos[3]->shiftY(-1);
		}
		else if (rotation == 4) {
			rotation = 1;
			minos[0]->shiftY(-2);
			minos[1]->shiftX(-1);
			minos[1]->shiftY(-1);
			minos[3]->shiftX(1);
			minos[3]->shiftY(1);
		}
		break;
	case Type::L:
		if (rotation == 1) {
			++rotation;
			minos[0]->shiftX(1);
			minos[0]->shiftY(-1);
			minos[2]->shiftX(-1);
			minos[2]->shiftY(1);
			minos[3]->shiftY(2);
		}
		else if (rotation == 2) {
			++rotation;
			minos[0]->shiftX(1);
			minos[0]->shiftY(1);
			minos[2]->shiftX(-1);
			minos[2]->shiftY(-1);
			minos[3]->shiftX(-2);
		}
		else if (rotation == 3) {
			++rotation;
			minos[0]->shiftX(-1);
			minos[0]->shiftY(1);
			minos[2]->shiftX(1);
			minos[2]->shiftY(-1);
			minos[3]->shiftY(-2);
		}
		else if (rotation == 4) {
			rotation = 1;
			minos[0]->shiftX(-1);
			minos[0]->shiftY(-1);
			minos[2]->shiftX(1);
			minos[2]->shiftY(1);
			minos[3]->shiftX(2);
		}
		break;
	case Type::O: break;
	case Type::S:
		if (rotation == 1) {
			++rotation;
			minos[0]->shiftX(1);
			minos[0]->shiftY(-1);
			minos[2]->shiftX(1);
			minos[2]->shiftY(1);
			minos[3]->shiftY(2);
		}
		else if (rotation == 2) {
			++rotation;
			minos[0]->shiftX(1);
			minos[0]->shiftY(1);
			minos[2]->shiftX(-1);
			minos[2]->shiftY(1);
			minos[3]->shiftX(-2);
		}
		else if (rotation == 3) {
			++rotation;
			minos[0]->shiftX(-1);
			minos[0]->shiftY(1);
			minos[2]->shiftX(-1);
			minos[2]->shiftY(-1);
			minos[3]->shiftY(-2);
		}
		else if (rotation == 4) {
			rotation = 1;
			minos[0]->shiftX(-1);
			minos[0]->shiftY(-1);
			minos[2]->shiftX(1);
			minos[2]->shiftY(-1);
			minos[3]->shiftX(2);
		}
		break;
	case Type::T:
		if (rotation == 1) {
			++rotation;
			minos[0]->shiftX(1);
			minos[0]->shiftY(-1);
			minos[2]->shiftX(1);
			minos[2]->shiftY(1);
			minos[3]->shiftX(-1);
			minos[3]->shiftY(1);
		}
		else if (rotation == 2) {
			++rotation;
			minos[0]->shiftX(1);
			minos[0]->shiftY(1);
			minos[2]->shiftX(-1);
			minos[2]->shiftY(1);
			minos[3]->shiftX(-1);
			minos[3]->shiftY(-1);
		}
		else if (rotation == 3) {
			++rotation;
			minos[0]->shiftX(-1);
			minos[0]->shiftY(1);
			minos[2]->shiftX(-1);
			minos[2]->shiftY(-1);
			minos[3]->shiftX(1);
			minos[3]->shiftY(-1);
		}
		else if (rotation == 4) {
			rotation = 1;
			minos[0]->shiftX(-1);
			minos[0]->shiftY(-1);
			minos[2]->shiftX(1);
			minos[2]->shiftY(-1);
			minos[3]->shiftX(1);
			minos[3]->shiftY(1);
		}
		break;
	case Type::Z:
		if (rotation == 1) {
			++rotation;
			minos[0]->shiftX(2);
			minos[1]->shiftX(1);
			minos[1]->shiftY(1);
			minos[3]->shiftX(-1);
			minos[3]->shiftY(1);
		}
		else if (rotation == 2) {
			++rotation;
			minos[0]->shiftY(2);
			minos[1]->shiftX(-1);
			minos[1]->shiftY(1);
			minos[3]->shiftX(-1);
			minos[3]->shiftY(-1);
		}
		else if (rotation == 3) {
			++rotation;
			minos[0]->shiftX(-2);
			minos[1]->shiftX(-1);
			minos[1]->shiftY(-1);
			minos[3]->shiftX(1);
			minos[3]->shiftY(-1);
		}
		else if (rotation == 4) {
			rotation = 1;
			minos[0]->shiftY(-2);
			minos[1]->shiftX(1);
			minos[1]->shiftY(-1);
			minos[3]->shiftX(1);
			minos[3]->shiftY(1);
		}
		break;
	}
}