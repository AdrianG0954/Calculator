#pragma once
#include "IBaseCommands.h"
#include "wx/wx.h"
class SubtractCommand : IBaseCommands
{
private:
	double _x = 0;
	double _y = 0;

public:
	SubtractCommand(double x, double y);
	double Subtract();

	double Execute();

};

