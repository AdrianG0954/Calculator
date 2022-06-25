#include "DivCommand.h"

DivCommand::DivCommand(double x, double y) : _x(x), _y(y)
{}

double DivCommand::Divide() {
	return _x / _y;
}

double DivCommand::Execute() {
	return Divide();
}