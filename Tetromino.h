#ifndef TETROMINO_H
#define TETROMINO_H

#include<array>
#include<iostream>
#include<vector>
#include"Window.h"
#include"Config.h"
#include"Mino.h"

class Tetromino {
public:
	enum class Type{ I, O, T, S, Z, J, L };

	Tetromino(Window* const window, const Type& type, int x, int y);
	~Tetromino();

	const std::array<Mino*, 4>& getMinos() const { return minos; }

	void goDown();
	void goLeft();
	void goRight();

	void setY(const int& y);

	const int getBottomY() const;
	const int getLeftmostX() const;
	const int getRightmostX() const;

	void rotate();

private:
	Window* const window;
	std::array<Mino*, 4> minos = {nullptr, nullptr, nullptr, nullptr};
	Type type;
	char rotation = 1;
};

#endif