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

ostream &operator << (ostream& os, const Project &project)
{
	os << "Name: " << project.name << ",    Complexity: " << project.complexity << "\nList of technology:\n";

	for (int i = 0; i < int(project.technology.size()); ++i)
	{
		os << "Technology: " << project.technology[i].first->getName() << "\nDevelopers:\n";
		for (int j = 0; j < int(project.technology[i].second.size()); ++j)
		{
			os << project.technology[i].second[j] << '\n';
		}

	}

	os << "List of project:\n";
	for (int i = 0; i < int(project.toComplete.size()); ++i)
	{
		os << project.toComplete[i]->getName() << '\n';
	}

	return os;
}