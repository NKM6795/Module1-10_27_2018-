#include "Company.h"


float Company::getMaxEfficiency(Project *project, vector<Developer *> &developer)
{
	float result = 0;

	for (int i = 0; i < int(developer.size()); ++i)
	{
		if (developer[i]->getProject() == nullptr && project->checkDeveloper(developer[i]))
		{
			result += developer[i]->getEfficiency();
		}
	}
	return result;
}


Company::~Company()
{
	while (technology.size() != 0)
	{
		delete technology.back();
		technology.pop_back();
	}

	while (developers.size() != 0)
	{
		delete developers.back();
		developers.pop_back();
	}

	while (projects.size() != 0)
	{
		delete projects.back();
		projects.pop_back();
	}
}


void Company::setTechnology(string fileName)
{
	ifstream fileIn(fileName);

	int number;
	fileIn >> number;

	string tempName;
	getline(fileIn, tempName);

	for (int i = 0; i < number; ++i)
	{
		getline(fileIn, tempName);

		Technology *newTechnology = new Technology(tempName);
		technology.push_back(newTechnology);
	}

	fileIn.close();
}

void Company::setDevelopers(string fileName)
{
	ifstream fileIn(fileName);

	int number;
	fileIn >> number;

	string tempName;
	getline(fileIn, tempName);

	for (int i = 0; i < number; ++i)
	{
		getline(fileIn, tempName);

		Developer *newDeveloper = new Developer(tempName);
		developers.push_back(newDeveloper);
	}

	fileIn.close();
}

void Company::setProjects(string fileName)
{
	ifstream fileIn(fileName);

	int number;
	fileIn >> number;

	string tempName;
	getline(fileIn, tempName);

	for (int i = 0; i < number; ++i)
	{
		getline(fileIn, tempName);

		Project *newProject = new Project(tempName);
		projects.push_back(newProject);
	}

	fileIn.close();
}


void Company::coutAllTechnology()
{
	cout << "Technology:\n";
	for (int i = 0; i < int(technology.size()); ++i)
	{
		cout << *technology[i];
	}
	cout << "*********************************************************************************************************************\n\
*********************************************************************************************************************\n";
}

void Company::coutAllDeveloper()
{
	cout << "Developers:\n";
	for (int i = 0; i < int(developers.size()); ++i)
	{
		cout << *developers[i] << '\n';
	}
	cout << "*********************************************************************************************************************\n\
*********************************************************************************************************************\n";
}

void Company::coutAllProject()
{
	cout << "Projects:\n";
	for (int i = 0; i < int(projects.size()); ++i)
	{
		cout << *projects[i] << '\n';
	}
	cout << "*********************************************************************************************************************\n\
*********************************************************************************************************************\n";
}

void Company::coutAllElement()
{
	coutAllTechnology();

	coutAllDeveloper();

	coutAllProject();
}


void Company::randomConnectionsInDevelopers()
{
	vector<int> indexes;
	for (int i = 0; i < int(technology.size()); ++i)
	{
		indexes.push_back(i);
	}

	for (int i = 0; i < int(developers.size()); ++i)
	{
		random_shuffle(indexes.begin(), indexes.end());

		int number = 1 + rand() % int(technology.size() / 10);

		for (int j = 0; j < number; ++j)
		{
			developers[i]->getListOfTechnology()->push_back(technology[indexes[j]]);
		}
	}
}

void Company::randomConnectionsInProjects()
{
	vector<int> indexes;
	for (int i = 0; i < int(technology.size()); ++i)
	{
		indexes.push_back(i);
	}

	for (int i = 0; i < int(projects.size()); ++i)
	{
		random_shuffle(indexes.begin(), indexes.end());

		int number = 1 + rand() % int(technology.size() / 10);

		for (int j = 0; j < number; ++j)
		{
			projects[i]->getListOfTechnology()->push_back({ technology[indexes[j]], vector<Developer *>() });
		}
	}

	for (int i = 0; i < int(projects.size()); ++i)
	{
		if (rand() % 5 == 0)
		{
			vector<int> indexes2;
			for (int j = i + 1; j < int(projects.size()); ++j)
			{
				indexes2.push_back(j);
			}

			random_shuffle(indexes2.begin(), indexes2.end());

			for (int j = 0; j < int(projects.size()) - i - 1; ++j)
			{
				if (rand() % 3 == 0)
				{
					projects[i]->getListOfProjects()->push_back(projects[indexes2[j]]);
				}
			}
		}
	}
}

void Company::coutListOfNotMadeProjects()
{
	vector<Project *> sortProjects;
	vector<float> maxEfficiency;

	for (int i = 0; i < int(projects.size()); ++i)
	{
		if (!projects[i]->completed)
		{
			sortProjects.push_back(projects[i]);

			maxEfficiency.push_back(getMaxEfficiency(projects[i], developers));

			for (int j = int(sortProjects.size()) - 1; j > 0; --j)
			{
				if (sortProjects[j - 1]->getListOfTechnology()->size() > sortProjects[j]->getListOfTechnology()->size())
				{
					swap(sortProjects[j - 1], sortProjects[j]);
					swap(maxEfficiency[j - 1], maxEfficiency[j]);
				}
				else if (sortProjects[j - 1]->getListOfTechnology()->size() == sortProjects[j]->getListOfTechnology()->size() &&
					sortProjects[j - 1]->getComplexity() > sortProjects[j]->getComplexity())
				{
					swap(sortProjects[j - 1], sortProjects[j]);
					swap(maxEfficiency[j - 1], maxEfficiency[j]);
				}
				else if (sortProjects[j - 1]->getListOfTechnology()->size() == sortProjects[j]->getListOfTechnology()->size() &&
					sortProjects[j - 1]->getComplexity() == sortProjects[j]->getComplexity() && 
					maxEfficiency[j - 1] < maxEfficiency[j])
				{
					swap(sortProjects[j - 1], sortProjects[j]);
					swap(maxEfficiency[j - 1], maxEfficiency[j]);
				}
				else
				{
					j = 0;
				}
			}
		}
	}

	cout << "List of not made projects:\n";
	for (int i = 0; i < int(sortProjects.size()); ++i)
	{
		cout << *sortProjects[i];
		cout << "Max efficiency: " << maxEfficiency[i] << "\n\n";
	}
	cout << "*********************************************************************************************************************\n\
*********************************************************************************************************************\n";
}