#pragma once


#include "AnnouncementAllClass.h"
#include "Developer.h"


class Project
{
	string name;

	float complexity;

	vector<pair<Technology *, vector<Developer *> > > technology;

	vector<Project *> toComplete;

	vector<float> coefficientForTime;		//[0] * ([1] * complexity + [2] * (technology(developer().efficiency, developer.size())) + [3] * float(rand() % 100) / 100)


	bool reconnect(vector<vector<int> > &techn, vector<vector<int> > &dev, vector<int> &left, vector<int> &right, int i, vector<bool> &used);

	bool addDevelopers(bool needAdd, vector<Developer *> &developersForCheck);

public:
	bool completed;


	Project() :
		name(""), complexity(0.1f + float(rand() % 8) / 10), coefficientForTime({ 168.f, 0.5f, 0.4f, 0.1f }), completed(false) {}
	Project(string name) :
		name(name), complexity(0.1f + float(rand() % 8) / 10), coefficientForTime({ 168.f, 0.5f, 0.4f, 0.1f }), completed(false) {}
	Project(string name, float complexity, vector<float> coefficientForTime) :
		name(name), complexity(complexity), coefficientForTime(coefficientForTime), completed(false) {}


	vector<pair<Technology *, vector<Developer *> > > *getListOfTechnology();

	vector<Project *> *getListOfProjects();


	string getName();

	float getComplexity();

	bool checkDeveloper(Developer *developer);

	bool checkDevelopers(vector<Developer *> &developersForCheck);


	friend ostream &operator << (ostream& os, const Project &project);
};