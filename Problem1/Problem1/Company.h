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

	float getMaxEfficiency(Project *project, vector<Developer *> &developer);

public:
	Company() :
		name("") {}
	Company(string name) :
		name(name) {}

	~Company();

	void setTechnology(string fileName, bool shortDemonstration);

	void setDevelopers(string fileName, bool shortDemonstration);

	void setProjects(string fileName, bool shortDemonstration);


	void coutAllTechnology();

	void coutAllDeveloper();

	void coutAllProject();

	void coutAllElement();


	void randomConnectionsInDevelopers();

	void randomConnectionsInProjects();

	void coutListOfNotMadeProjects();
};