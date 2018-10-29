#pragma once


#include "AnnouncementAllClass.h"
#include "Developer.h"


class Technology
{
	string name;

	float coefficientTime;
	float probabilityOfChange;
	float coefficientForCountOfDeveloper;

public:
	Technology() : 
		name(""), coefficientTime(0.5f + float(rand() % 100) / 100), probabilityOfChange(0.5f + float(rand() % 50) / 100), coefficientForCountOfDeveloper(0.5f + float(rand() % 100) / 100) {}
	Technology(string name) : 
		name(name), coefficientTime(0.5f + float(rand() % 100) / 100), probabilityOfChange(0.5f + float(rand() % 50) / 100), coefficientForCountOfDeveloper(0.5f + float(rand() % 100) / 100) {}
	Technology(string name, float coefficientTime, float probabilityOfChange, float coefficientForCountOfDeveloper) :
		name(name), coefficientTime(coefficientTime), probabilityOfChange(probabilityOfChange), coefficientForCountOfDeveloper(coefficientForCountOfDeveloper) {}


	string getName();

	float getCoefficientTime();

	bool needChange();

	float getCoefficientForCountOfDeveloper();


	friend ostream &operator << (ostream& os, const Technology &technology);
};