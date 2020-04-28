#include "Square.h"

Square::Square(const int xSquare, const int ySquare, const int color): 
	m_xSquare(xSquare), 
	m_ySquare(ySquare),
	m_color(color)
{}

void Square::moveSquare(const int xSquare, const int ySquare)
{
	this->m_xSquare += xSquare;
	this->m_ySquare += ySquare;
}
