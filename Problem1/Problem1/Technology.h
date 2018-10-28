#pragma once


#include "AnnouncementAllClass.h"
#include "Developer.h"


class Technology
{
	string name;

	float coefficientTime;
	float probabilityOfChange;

public:
	Technology() : 
		name(""), coefficientTime(0.5f + float(rand() % 100) / 100), probabilityOfChange(0.5f + float(rand() % 50) / 100) {}
	Technology(string name) : 
		name(name), coefficientTime(0.5f + float(rand() % 100) / 100), probabilityOfChange(0.5f + float(rand() % 50) / 100) {}
	Technology(string name, float coefficientTime, float probabilityOfChange) : 
		name(name), coefficientTime(coefficientTime), probabilityOfChange(probabilityOfChange) {}

	string getName();

	friend ostream &operator << (ostream& os, const Technology &technology);
};