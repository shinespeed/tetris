#include "Square.h"

Square::Square(const int x_Square, const int y_Square): xSquare(x_Square), ySquare(y_Square)
{}

void Square::moveSquare(const int xSquare, const int ySquare)
{
	this->xSquare += xSquare;
	this->ySquare += ySquare;
}
