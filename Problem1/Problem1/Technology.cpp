#include "Technology.h"


string Technology::getName()
{
	return name;
}

ostream &operator << (ostream& os, const Technology &technology)
{
	os << "Name: " << technology.name << ",    Coefficient of time: " << technology.coefficientTime << ",     Probability of change: " << technology.probabilityOfChange << "\n";
	return os;
}