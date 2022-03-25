#ifndef MINO_H
#define MINO_H

#include<SDL.h>
#include"Window.h"
#include"Square.h"

class Mino {
public:
	Mino(Window* const window, const int x, const int y, const SDL_Color color);
	~Mino();

	SDL_Texture* const getTexture() const { return square->getTexture(); }
	const SDL_Rect& getRect() const { return square->getRect(); }

	const int getX() const { return square->getX(); }
	const int getY() const { return square->getY(); }

	void setY(const int& y);

	const int getSize() const { return square->getH(); }

	void shiftX(const int& shift);
	void shiftY(const int& shift);

private:
	Window* const window;
	Square* square = nullptr;
};

#endif