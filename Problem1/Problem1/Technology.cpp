#include "Technology.h"


string Technology::getName()
{
	return name;
}

float Technology::getCoefficientTime()
{
	return coefficientTime;
}

bool Technology::needChange()
{
	return int(probabilityOfChange * 100) > rand() % 100;
}

float Technology::getCoefficientForCountOfDeveloper()
{
	return coefficientForCountOfDeveloper;
}


ostream &operator << (ostream& os, const Technology &technology)
{
	os << "Name: " << technology.name << ",    Coefficient of time: " << technology.coefficientTime << ",     Probability of change: " << technology.probabilityOfChange << "\n";
	return os;
}