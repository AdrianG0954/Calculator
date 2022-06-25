#include "TimesCommand.h"

TimesCommand::TimesCommand(double x, double y) : _x(x), _y(y)
{}

double TimesCommand::Times() {
	return _x * _y;
}

double TimesCommand::Execute() {
	return Times();
}