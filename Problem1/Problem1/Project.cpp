#include "Project.h"


vector<Technology *> *Project::getListOfTechnology()
{
	return &technology;
}

vector<Project *> *Project::getListOfProjects()
{
	return &toComplete;
}