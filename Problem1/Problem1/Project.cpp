#include "Project.h"


vector<pair<Technology *, vector<Developer *> > > *Project::getListOfTechnology()
{
	return &technology;
}

vector<Project *> *Project::getListOfProjects()
{
	return &toComplete;
}


string Project::getName()
{
	return name;
}

float Project::getComplexity()
{
	return complexity;
}

bool Project::checkDeveloper(Developer *developer)
{
	for (int i = 0; i < int(technology.size()); ++i)
	{
		if (developer->checkTechnology(technology[i].first))
		{
			return true;
		}
	}
	return false;
}


ostream &operator << (ostream& os, const Project &project)
{
	os << "Name: " << project.name << ",    Complexity: " << project.complexity << "\nList of technology (" << project.technology.size() << "):\n";

	for (int i = 0; i < int(project.technology.size()); ++i)
	{
		os << "Technology: " << project.technology[i].first->getName() << "\nDevelopers (" << project.technology[i].second.size() << "):\n";
		for (int j = 0; j < int(project.technology[i].second.size()); ++j)
		{
			os << project.technology[i].second[j] << '\n';
		}

	}

	os << "List of project (" << project.toComplete.size() << "):\n";
	for (int i = 0; i < int(project.toComplete.size()); ++i)
	{
		os << project.toComplete[i]->getName() << '\n';
	}

	return os;
}