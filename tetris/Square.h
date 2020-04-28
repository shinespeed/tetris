#ifndef SQUARE_H
#define SQUARE_H

class Square
{
public:
	Square(const int x_Square, const int y_Square);

	void moveSquare(int xSquare, int ySquare);

	int xSquare;
	int ySquare;
};

#endif