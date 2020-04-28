#ifndef SQUARE_H
#define SQUARE_H

class Square
{
public:
	Square(const int xSquare, const int ySquare, const int color);

	void moveSquare(int xSquare, int ySquare);

	int m_color;
	int m_xSquare;
	int m_ySquare;
};

#endif