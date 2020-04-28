#include "Square.h"


Square::Square(int x_Square, int y_Square): xSquare(x_Square), ySquare(y_Square)
{}

void Square::moveSquare(int xSquare, int ySquare)
{
	this->xSquare += xSquare;
	this->ySquare += ySquare;
}
