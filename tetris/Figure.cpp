#include "Figure.h"

Figure:: Figure() {}

Figure::~Figure() {}

void Figure::moveFigure(const int xFigure, const int yFigure)
{
	for (int i = 0; i < QUANTITY_SQUARE; i++) 
	{
		arrSquareFigure[i]->moveSquare((xFigure - this->xFigure), (yFigure - this->yFigure));
	}

	this->xFigure = xFigure;
	this->yFigure = yFigure;
}

Square* Figure::getArrSquareFigure(const int index)
{
	return arrSquareFigure[index];
}

int Figure::getXFigure()
{
	return xFigure;
}
int Figure::getYFigure()
{
	return yFigure;
}

TFigure::TFigure(const int _xFigure, const int _yFigure)
{
	xFigure = _xFigure;
	yFigure = _yFigure;
	createSquareFigure();
}

void TFigure::createSquareFigure() 
{
	arrSquareFigure[0] = new Square(xFigure + TFIGURE_COORD_1_X, yFigure + TFIGURE_COORD_1_Y, RED);
	arrSquareFigure[1] = new Square(xFigure + TFIGURE_COORD_2_X, yFigure + TFIGURE_COORD_2_Y, RED);
	arrSquareFigure[2] = new Square(xFigure + TFIGURE_COORD_3_X, yFigure + TFIGURE_COORD_3_Y, RED);
	arrSquareFigure[3] = new Square(xFigure + TFIGURE_COORD_4_X, yFigure + TFIGURE_COORD_4_Y, RED);
}

QFigure::QFigure(const int _xFigure, const int _yFigure)
{
	xFigure = _xFigure;
	yFigure = _yFigure;
	createSquareFigure();
}

void QFigure::createSquareFigure()
{
	arrSquareFigure[0] = new Square(xFigure + QFIGURE_COORD_1_X, yFigure + QFIGURE_COORD_1_Y, VIOLET);
	arrSquareFigure[1] = new Square(xFigure + QFIGURE_COORD_2_X, yFigure + QFIGURE_COORD_2_Y, VIOLET);
	arrSquareFigure[2] = new Square(xFigure + QFIGURE_COORD_3_X, yFigure + QFIGURE_COORD_3_Y, VIOLET);
	arrSquareFigure[3] = new Square(xFigure + QFIGURE_COORD_4_X, yFigure + QFIGURE_COORD_4_Y, VIOLET);
}

IFigure::IFigure(const int _xFigure, const int _yFigure)
{
	xFigure = _xFigure;
	yFigure = _yFigure;
	createSquareFigure();
}

void IFigure::createSquareFigure()
{
	arrSquareFigure[2] = new Square(xFigure + IFIGURE_COORD_1_X, yFigure + IFIGURE_COORD_1_Y, GREEN);
	arrSquareFigure[1] = new Square(xFigure + IFIGURE_COORD_2_X, yFigure + IFIGURE_COORD_2_Y, GREEN);
	arrSquareFigure[0] = new Square(xFigure + IFIGURE_COORD_3_X, yFigure + IFIGURE_COORD_3_Y, GREEN);
	arrSquareFigure[3] = new Square(xFigure + IFIGURE_COORD_4_X, yFigure + IFIGURE_COORD_4_Y, GREEN);
}

ZFigure::ZFigure(const int _xFigure, const int _yFigure)
{
	xFigure = _xFigure;
	yFigure = _yFigure;
	createSquareFigure();
}

void ZFigure::createSquareFigure()
{
	arrSquareFigure[0] = new Square(xFigure + ZFIGURE_COORD_1_X, yFigure + ZFIGURE_COORD_1_Y, PURPURE);
	arrSquareFigure[1] = new Square(xFigure + ZFIGURE_COORD_2_X, yFigure + ZFIGURE_COORD_2_Y, PURPURE);
	arrSquareFigure[2] = new Square(xFigure + ZFIGURE_COORD_3_X, yFigure + ZFIGURE_COORD_3_Y, PURPURE);
	arrSquareFigure[3] = new Square(xFigure + ZFIGURE_COORD_4_X, yFigure + ZFIGURE_COORD_4_Y, PURPURE);
}

JFigure::JFigure(const int _xFigure, const int _yFigure)
{
	xFigure = _xFigure;
	yFigure = _yFigure;
	createSquareFigure();
}

void JFigure::createSquareFigure()
{
	arrSquareFigure[2] = new Square(xFigure + JFIGURE_COORD_1_X, yFigure + JFIGURE_COORD_1_Y, YELLOW);
	arrSquareFigure[1] = new Square(xFigure + JFIGURE_COORD_2_X, yFigure + JFIGURE_COORD_2_Y, YELLOW);
	arrSquareFigure[0] = new Square(xFigure + JFIGURE_COORD_3_X, yFigure + JFIGURE_COORD_3_Y, YELLOW);
	arrSquareFigure[3] = new Square(xFigure + JFIGURE_COORD_4_X, yFigure + JFIGURE_COORD_4_Y, YELLOW);
}

SFigure::SFigure(const int _xFigure, const int _yFigure)
{
	xFigure = _xFigure;
	yFigure = _yFigure;
	createSquareFigure();
}

void SFigure::createSquareFigure()
{
	arrSquareFigure[0] = new Square(xFigure + SFIGURE_COORD_1_X, yFigure + SFIGURE_COORD_1_Y, PURPURE);
	arrSquareFigure[1] = new Square(xFigure + SFIGURE_COORD_2_X, yFigure + SFIGURE_COORD_2_Y, PURPURE);
	arrSquareFigure[2] = new Square(xFigure + SFIGURE_COORD_3_X, yFigure + SFIGURE_COORD_3_Y, PURPURE);
	arrSquareFigure[3] = new Square(xFigure + SFIGURE_COORD_4_X, yFigure + SFIGURE_COORD_4_Y, PURPURE);
}

LFigure::LFigure(const int _xFigure, const int _yFigure)
{
	xFigure = _xFigure;
	yFigure = _yFigure;
	createSquareFigure();
}

void LFigure::createSquareFigure()
{
	arrSquareFigure[2] = new Square(xFigure + LFIGURE_COORD_1_X, yFigure + LFIGURE_COORD_1_Y, LILAS);
	arrSquareFigure[1] = new Square(xFigure + LFIGURE_COORD_2_X, yFigure + LFIGURE_COORD_2_Y, LILAS);
	arrSquareFigure[0] = new Square(xFigure + LFIGURE_COORD_3_X, yFigure + LFIGURE_COORD_3_Y, LILAS);
	arrSquareFigure[3] = new Square(xFigure + LFIGURE_COORD_4_X, yFigure + LFIGURE_COORD_4_Y, LILAS);
}