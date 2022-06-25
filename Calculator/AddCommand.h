#pragma once
#include "IBaseCommands.h"
#include "wx/wx.h"
class AddCommand : IBaseCommands
{
private:
	double _x = 0;
	double _y = 0;
	
public:
	AddCommand(double x, double y);
	double Plus();

	double Execute();
};

