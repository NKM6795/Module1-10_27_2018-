#pragma once


#include "AnnouncementAllClass.h"
#include "Technology.h"
#include "Project.h"


class Developer
{
	string name;

	Project *project;

	vector<Technology *> technology;

	float efficiency;

public:
	Developer() :
		name(""), project(nullptr), efficiency(0.1f + float(rand() % 90) / 100) {}
	Developer(string name) :
		name(name), project(nullptr), efficiency(0.1f + float(rand() % 90) / 100) {}
	Developer(string name, float efficiency) :
		name(name), project(nullptr), efficiency(efficiency) {}

	vector<Technology *> *getListOfTechnology();

	string getName();

	friend ostream &operator << (ostream& os, const Developer &developer);
};