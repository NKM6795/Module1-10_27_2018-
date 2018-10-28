#pragma once


#include "AnnouncementAllClass.h"
#include "Technology.h"
#include "Developer.h"
#include "Project.h"


class Company
{
	string name;

	vector<Technology *> technology;

	vector<Developer *> developers;

	vector<Project *> projects;

public:
	Company() :
		name("") {}
	Company(string name) :
		name(name) {}

	~Company();

	void getTechnology(string fileName);


};