#include"Mino.h"

Mino::Mino(Window* const window, const int x, const int y, const SDL_Color color) : window(window) {
	square = new Square(window->getRenderer(), x * window->getGridSize(), y  * window->getGridSize(), window->getGridSize(), window->getGridSize(), color);
}

Mino::~Mino() {
	delete square;
}

void Mino::setY(const int& y) {
	square->setY(y);
}

void Mino::shiftX(const int& shift) {
	square->shiftX(shift * window->getGridSize());
}

void Mino::shiftY(const int& shift) {
	square->shiftY(shift * window->getGridSize());
}