#include "World.h"

World::World() :
	sumSquare(0),
	sumPoint(0),
	level(1),
	sumHorizonSquare(0),
	gameSpeed(START_ITERATION),
	pointUp(START_POINT)
{}

World::~World()
{
	delete tempFigure;
	for (int i = 0; i < ARRAY_Y; ++i) 
	{
		for (int j = 0; j < ARRAY_X; ++j) 
		{
			if (arrSquare[i][j] != nullptr) 
			{
				delete arrSquare[i][j];
			}
		}
	}
}

bool World::regulationFigure(const int futureX, const int futureY)
{
	int tempX = 0;
	int tempY = 0;
	int numberViolation = 0;

	for (int i = 0; i < QUANTITY_SQUARE; ++i)
	{
	    tempX = tempFigure->getArrSquareFigure(i)->m_xSquare + (futureX - tempFigure->getXFigure());
		tempY = tempFigure->getArrSquareFigure(i)->m_ySquare + (futureY - tempFigure->getYFigure());

		if (!regulationSquare(tempX, tempY)) ++numberViolation;
	} 
	if (numberViolation == 0) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool World::regulationSquare(const int squarefutureX, const int squarefutureY)
{
	if (squarefutureX >= 0 && squarefutureX < ARRAY_X && squarefutureY < ARRAY_Y)
	{
		if (arrSquare[squarefutureY][squarefutureX] == nullptr) 
		{
			return true;
		}
		else
		{
			return whoseSquare(squarefutureX, squarefutureY);
		}
	} 
	else return false;
}

bool World::whoseSquare(const int squarefutureX, const int squarefutureY)
{
	bool squareFigure = false;

	for (int i = 0; i < QUANTITY_SQUARE; ++i)
	{
		if (arrSquare[squarefutureY][squarefutureX] == tempFigure->getArrSquareFigure(i))
		{
			squareFigure = true;
			break;
		}
	}
	return squareFigure;
}

void World::calculationFutureXY(int &futureX, int &futureY, const int index)
{
	futureX = tempFigure->getArrSquareFigure(0)->m_xSquare + tempFigure->getArrSquareFigure(0)->m_ySquare - tempFigure->getArrSquareFigure(index)->m_ySquare;
	futureY = tempFigure->getArrSquareFigure(index)->m_xSquare + tempFigure->getArrSquareFigure(0)->m_ySquare - tempFigure->getArrSquareFigure(0)->m_xSquare;
}

void World::rotationMatrixSquare(const int index, int &numberViolation)
{
	int tempX(0);
	int tempY(0);

	calculationFutureXY(tempX, tempY, index);
	
	arrSquare[tempY][tempX] = tempFigure->getArrSquareFigure(index);

	arrSquare[tempFigure->getArrSquareFigure(index)->m_ySquare][tempFigure->getArrSquareFigure(index)->m_xSquare] = nullptr;

	tempFigure->getArrSquareFigure(index)->m_xSquare = tempX;
	tempFigure->getArrSquareFigure(index)->m_ySquare = tempY;
}

void World::rotationFigure()
{
	int numberViolation(0);
	int tempX(0);
	int tempY(0);

	for (int i = 1; i < QUANTITY_SQUARE; ++i)
	{
		calculationFutureXY(tempX, tempY, i);
		
		if (!regulationSquare(tempX, tempY))
		{ 
			++numberViolation; 
			break;
		}
	}
	if (numberViolation == 0) 
	{
		for (int i = 1; i < QUANTITY_SQUARE; ++i) 
		{
			rotationMatrixSquare(i, numberViolation);
		}
	}
	moveFigure(tempFigure->getXFigure(), tempFigure->getYFigure());
}

void World::checkLevel()
{
	if (sumHorizonSquare == 4) 
	{
		sumHorizonSquare = 0;
		++level;
		gameSpeed = gameSpeed - (pow(gameSpeed, 3) * 0.9);
		pointUp*=1.5;
	}
	else
	{
		++sumHorizonSquare;
	}
}

void World::checkSumSquareHorizon() 
{
	for (int i = 0; i < ARRAY_Y; ++i) 
	{
		for (int j = 0; j < ARRAY_X; ++j)
		{
			countSumSquare(j, i);
		}
		if (sumSquare == ARRAY_X) 
		{
			checkLevel();
			delHorizonSquare(i);
		}
		sumSquare = 0;
	}
}

void World::delHorizonSquare(const int y)
{
	sumPoint += pointUp;
	for (int i = y; i > 1; --i) 
	{
		for (int j = 0; j < ARRAY_X; ++j) 
		{
			delete arrSquare[i][j];
			arrSquare[i][j] = arrSquare[i-1][j];
			arrSquare[i-1][j] = nullptr;
		}
	}
}

void World::countSumSquare(const int x, const int y)
{
	if (arrSquare[y][x] != nullptr) 
	{
		sumSquare++;
	}
}

void World::moveFigure(const int x, const int y) 
{
	for (int i = 0; i < QUANTITY_SQUARE; i++)
	{
		arrSquare[tempFigure->getArrSquareFigure(i)->m_ySquare][tempFigure->getArrSquareFigure(i)->m_xSquare] = nullptr;
	}

	tempFigure->moveFigure(x, y);

	for (int i = 0; i < QUANTITY_SQUARE; i++)
	{
		arrSquare[tempFigure->getArrSquareFigure(i)->m_ySquare][tempFigure->getArrSquareFigure(i)->m_xSquare] = tempFigure->getArrSquareFigure(i);
	}
}

void World::addFigure(Figure* figure) 
{
	tempFigure = figure;

	for (int i = 0; i < QUANTITY_SQUARE; i++) 
	{
		arrSquare[figure->getArrSquareFigure(i)->m_ySquare][figure->getArrSquareFigure(i)->m_xSquare] = figure->getArrSquareFigure(i);
	}
}