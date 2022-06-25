#pragma once
#include "IBaseCommands.h"
#include "wx/wx.h"
class TimesCommand : IBaseCommands
{
private:
	double _x = 0;
	double _y = 0;

public:
	TimesCommand(double x, double y);
	double Times();

	double Execute();

};

