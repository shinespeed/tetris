#ifndef WORLD_H
#define WORLD_H

#include "GlobalConstant.h"
#include "Figure.h"
#include "Square.h"
#include <cmath>
#include <iostream>

class World
{
public:
	World();
	~World();

	Square* arrSquare[ARRAY_Y][ARRAY_X];

	int sumSquare;
	int sumPoint;
	int pointUp;
	int level;
	int sumHorizonSquare;
	
	float gameSpeed;

	bool regulationFigure(const int futureX, const int futureY);
	bool whoseSquare(const int squarefutureX, const int squarefutureY);

	void checkLevel();
	void moveFigure(const int x, const int y);
	void rotationFigure();
	void addFigure(Figure* figure);
	void checkSumSquareHorizon();

private:
	Figure* tempFigure;

	void calculationFutureXY(int &futureX, int &futureY, const int index);//
	void rotationMatrixSquare(const int index, int &numberViolation);
	void countSumSquare(const int x, const int y);
	void delHorizonSquare(const int y);

	bool regulationSquare(const int squarefutureX, const int squarefutureY);
};

#endif