#include "Developer.h"


vector<Technology *> *Developer::getListOfTechnology()
{
	return &technology;
}

string Developer::getName()
{
	return name;
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