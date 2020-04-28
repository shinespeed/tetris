#ifndef FIGURE_H
#define FIGURE_H

#include "GlobalConstant.h"
#include "Square.h"
#include <vector>

class Figure
{
public:
	Figure();
	~Figure();

	int getXFigure();
	int getYFigure();

	void moveFigure(const int xFigure, const int yFigure);
	Square* getArrSquareFigure(const int index);

protected:
	int xFigure;
	int yFigure;
	Square* arrSquareFigure[QUANTITY_SQUARE];
};

class TFigure : public Figure
{
public:
	TFigure(const int xFigure, const int yFigure);

private:
	void createSquareFigure();
};

class QFigure : public Figure
{
public:
	QFigure(const int xFigure, const int yFigure);

private:
	void createSquareFigure();
};

class IFigure : public Figure
{
public:
	IFigure(const int xFigure, const int yFigure);

private:
	void createSquareFigure();
};

class ZFigure : public Figure
{
public:
	ZFigure(int xFigure, int yFigure);

private:
	void createSquareFigure();
};

class SFigure : public Figure
{
public:
	SFigure(const int xFigure, const int yFigure);

private:
	void createSquareFigure();
};

class JFigure : public Figure
{
public:
	JFigure(const int xFigure, const int yFigure);

private:
	void createSquareFigure();
};

class LFigure : public Figure
{
public:
	LFigure(const int xFigure, const int yFigure);

private:
	void createSquareFigure();
};

#endif