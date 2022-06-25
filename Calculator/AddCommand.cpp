#include "AddCommand.h"

AddCommand::AddCommand(double x, double y) : _x(x), _y(y)
{}

double AddCommand::Plus() {
	return _x + _y;
}

double AddCommand::Execute() {
	return Plus();
}