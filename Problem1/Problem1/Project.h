#pragma once


#include "AnnouncementAllClass.h"
#include "Developer.h"


class Project
{
	string name;

	float complexity;

	vector<Technology *> technology;

	vector<Developer *> developers;

	vector<Project *> toComplete;

	vector<float> coefficientForTime;		//[0] * ([1] * complexity + [2] * (technology(developer().efficiency, developer.size())) + [3] * float(rand() % 100) / 100)

public:
	Project() :
		name(""), complexity(0.5f), coefficientForTime({ 168.f, 0.5f, 0.4f, 0.1f }) {}
	Project(string name) :
		name(name), complexity(0.5f), coefficientForTime({ 168.f, 0.5f, 0.4f, 0.1f }) {}
	Project(string name, float complexity, vector<float> coefficientForTime) :
		name(name), complexity(complexity), coefficientForTime(coefficientForTime) {}

	vector<Technology *> *getListOfTechnology();

	vector<Project *> *getListOfProjects();
};