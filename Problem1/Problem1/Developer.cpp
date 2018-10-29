#include "Developer.h"


vector<Technology *> *Developer::getListOfTechnology()
{
	return &technology;
}


string Developer::getName()
{
	return name;
}

float Developer::getEfficiency()
{
	return efficiency;
}

Project *Developer::getProject()
{
	return project;
}

void Developer::setProject(Project *projectForDeveloper)
{
	project = projectForDeveloper;
}

bool Developer::checkTechnology(Technology *technologyForCheck)
{
	for (int i = 0; i < int(technology.size()); ++i)
	{
		if (technology[i] == technologyForCheck)
		{
			return true;
		}
	}
	return false;
}


ostream &operator << (ostream& os, const Developer &developer)
{
	os << "Name: " << developer.name << ",    Efficiency: " << developer.efficiency << ",    Project: ";
	if (developer.project != nullptr)
	{
		os << developer.project->getName();
	}
	os << "\nList of technology (" << developer.technology.size() << "):\n";

	for (int i = 0; i < int(developer.technology.size()); ++i)
	{
		os << developer.technology[i]->getName() << '\n';
	}

	return os;
}