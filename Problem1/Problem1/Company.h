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

	void setTechnology(string fileName);

	void setDevelopers(string fileName);

	void setProjects(string fileName);


	void coutAllTechnology();

	void coutAllDeveloper();

	void coutAllProject();

	void coutAllElement();


	void randomConnectionsInDevelopers();

	void randomConnectionsInProjects();
};