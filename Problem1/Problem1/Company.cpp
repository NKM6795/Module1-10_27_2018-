#include "Company.h"


Company::~Company()
{
	while (technology.size() != 0)
	{
		delete technology.back();
		technology.pop_back();
	}

	while (developers.size() != 0)
	{
		delete developers.back();
		developers.pop_back();
	}

	while (projects.size() != 0)
	{
		delete projects.back();
		projects.pop_back();
	}
}


void Company::getTechnology(string fileName)
{
	ifstream fileIn(fileName);





	fileIn.close();
}