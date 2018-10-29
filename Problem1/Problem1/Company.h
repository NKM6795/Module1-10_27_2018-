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


	float timer;


	float getMaxEfficiency(Project *project, vector<Developer *> &developer);

	pair<vector<Project *>, vector<float> > getListOfNotMadeProjects();

public:
	Company() :
		name(""), timer(0.f) {}
	Company(string name) :
		name(name), timer(0.f) {}

	~Company();

	void setTechnology(string fileName, bool shortDemonstration);

	void setDevelopers(string fileName, bool shortDemonstration);

	void setProjects(string fileName, bool shortDemonstration);


	void setTechnology();

	void setDevelopers();

	void setProjects();


	void coutAllTechnology();

	void coutAllDeveloper();

	void coutAllProject();

	void coutAllElement();


	void randomConnectionsInDevelopers();

	void randomConnectionsInProjects();

	void coutListOfNotMadeProjects();


	void work(float deltaTime);

	bool canWork();
};