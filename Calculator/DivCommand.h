#pragma once
#include "IBaseCommands.h"
#include "wx/wx.h"

class DivCommand : IBaseCommands
{
private:
	double _x = 0;
	double _y = 0;

public:
	DivCommand(double x, double y);
	double Divide();

	double Execute();
};

