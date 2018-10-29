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

pair<vector<Project *>, vector<float> > Company::getListOfNotMadeProjects()
{
	vector<Project *> sortProjects;
	vector<float> maxEfficiency;

	for (int i = 0; i < int(projects.size()); ++i)
	{
		if (!projects[i]->completed && projects[i]->checkDevelopers(developers))
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

	return { sortProjects,  maxEfficiency };
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


void Company::setTechnology(string fileName, bool shortDemonstration)
{
	ifstream fileIn(fileName);

	int number;
	fileIn >> number;

	string tempName;
	getline(fileIn, tempName);

	if (!shortDemonstration)
	{
		fileIn >> number;
	}
	getline(fileIn, tempName);

	for (int i = 0; i < number; ++i)
	{
		getline(fileIn, tempName);

		Technology *newTechnology = new Technology(tempName);
		technology.push_back(newTechnology);
	}

	fileIn.close();
}

void Company::setDevelopers(string fileName, bool shortDemonstration)
{
	ifstream fileIn(fileName);

	int number;
	fileIn >> number;

	string tempName;
	getline(fileIn, tempName);

	if (!shortDemonstration)
	{
		fileIn >> number;
	}
	getline(fileIn, tempName);

	for (int i = 0; i < number; ++i)
	{
		getline(fileIn, tempName);

		Developer *newDeveloper = new Developer(tempName);
		developers.push_back(newDeveloper);
	}

	fileIn.close();
}

void Company::setProjects(string fileName, bool shortDemonstration)
{
	ifstream fileIn(fileName);

	int number;
	fileIn >> number;

	string tempName;
	getline(fileIn, tempName);

	if (!shortDemonstration)
	{
		fileIn >> number;
	}
	getline(fileIn, tempName);

	for (int i = 0; i < number; ++i)
	{
		getline(fileIn, tempName);

		Project *newProject = new Project(tempName);
		projects.push_back(newProject);
	}

	fileIn.close();
}


void Company::setTechnology()
{
	int n;
	cin >> n;
	cout << "----------\n";

	for (int i = 0; i < n; ++i)
	{
		string temp;
		getline(cin, temp);
		getline(cin, temp);

		float tempFloat[3];
		cin >> tempFloat[0] >> tempFloat[1] >> tempFloat[2];

		Technology *newTechnology = new Technology(temp, tempFloat[0], tempFloat[1], tempFloat[2]);
		technology.push_back(newTechnology);

		cout << "**************************************************\n";
	}
}

void Company::setDevelopers()
{
	int n;
	cin >> n;
	cout << "----------\n";

	for (int i = 0; i < n; ++i)
	{
		string temp;
		getline(cin, temp);
		getline(cin, temp);

		float tempFloat;
		cin >> tempFloat;

		Developer *newDeveloper = new Developer(temp, tempFloat);
		developers.push_back(newDeveloper);

		int countOfTechnology;
		cin >> countOfTechnology;
		cout << "----------\n";

		getline(cin, temp);
		for (int j = 0; j < countOfTechnology; ++j)
		{
			getline(cin, temp);
			int index = -1;
			for (int k = 0; k < int(technology.size()) && index == -1; ++k)
			{
				if (technology[k]->getName() == temp)
				{
					index = k;
				}
			}

			if (index != -1)
			{
				developers.back()->getListOfTechnology()->push_back(technology[index]);
			}
		}
		cout << "**************************************************\n";
	}
}

void Company::setProjects()
{
	int n;
	cin >> n;
	cout << "----------\n";

	for (int i = 0; i < n; ++i)
	{
		string temp;
		getline(cin, temp);
		getline(cin, temp);

		float tempFloat[5];
		cin >> tempFloat[0] >> tempFloat[1] >> tempFloat[2] >> tempFloat[3] >> tempFloat[4];

		Project *newProject = new Project(temp, tempFloat[0], { tempFloat[1], tempFloat[2], tempFloat[3], tempFloat[4] });
		projects.push_back(newProject);

		int countOfTechnology;
		cin >> countOfTechnology;
		cout << "----------\n";

		getline(cin, temp);
		for (int j = 0; j < countOfTechnology; ++j)
		{
			getline(cin, temp);
			int index = -1;
			for (int k = 0; k < int(technology.size()) && index == -1; ++k)
			{
				if (technology[k]->getName() == temp)
				{
					index = k;
				}
			}

			if (index != -1)
			{
				projects.back()->getListOfTechnology()->push_back({ technology[index], vector<Developer *>() });
			}
		}

		int countOfProjects;
		cin >> countOfProjects;
		cout << "----------\n";

		getline(cin, temp);
		for (int j = 0; j < countOfProjects; ++j)
		{
			getline(cin, temp);
			int index = -1;
			for (int k = 0; k < int(projects.size()) && index == -1; ++k)
			{
				if (projects[k]->getName() == temp)
				{
					index = k;
				}
			}

			if (index != -1)
			{
				projects.back()->getListOfProjects()->push_back(projects[index]);
			}
		}
		cout << "**************************************************\n";
	}
}


void Company::coutAllTechnology()
{
	cout << "Technology (" << technology.size()  << "):\n";
	for (int i = 0; i < int(technology.size()); ++i)
	{
		cout << *technology[i];
	}
	cout << "*********************************************************************************************************************\n\
*********************************************************************************************************************\n";
}

void Company::coutAllDeveloper()
{
	cout << "Developers (" << developers.size() << "):\n";
	for (int i = 0; i < int(developers.size()); ++i)
	{
		cout << *developers[i] << '\n';
	}
	cout << "*********************************************************************************************************************\n\
*********************************************************************************************************************\n";
}

void Company::coutAllProject()
{
	cout << "Projects (" << projects.size()  << "):\n";
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

		int number = 1 + rand() % int(1 + technology.size() / 10);

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

		int number = 1 + rand() % int(1 + technology.size() / 10);

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
	pair<vector<Project *>, vector<float>> listOfNotMadeProjects = getListOfNotMadeProjects();

	cout << "List of not made projects (" << listOfNotMadeProjects.first.size()  << "):\n";
	for (int i = 0; i < int(listOfNotMadeProjects.first.size()); ++i)
	{
		cout << *listOfNotMadeProjects.first[i];
		cout << "Max efficiency: " << listOfNotMadeProjects.second[i] << "\n\n";
	}
	cout << "*********************************************************************************************************************\n\
*********************************************************************************************************************\n";
}


void Company::work(float deltaTime)
{
	bool comp = false;
	while (!comp)
	{
		pair<vector<Project *>, vector<float>> listOfNotMadeProjects = getListOfNotMadeProjects();

		for (int i = 0; i < int(listOfNotMadeProjects.first.size()); ++i)
		{
			bool check = true;

			for (int j = 0; j < int(listOfNotMadeProjects.first[i]->getListOfProjects()->size()) && check; ++j)
			{
				if (!listOfNotMadeProjects.first[i]->getListOfProjects()->operator[](j)->completed)
				{
					check = false;
				}
			}

			if (check)
			{
				listOfNotMadeProjects.first[i]->developersFill(developers, timer);
				i = int(listOfNotMadeProjects.first.size());
			}
			else
			{
				comp = true;
			}
		}

		if (listOfNotMadeProjects.first.size() == 0)
		{
			comp = true;
		}

	}

	timer += deltaTime;

	for (int i = 0; i < int(projects.size()); ++i)
	{
		if (!projects[i]->completed && projects[i]->wasStarted())
		{
			projects[i]->work(timer);
		}
	}
}

bool Company::canWork()
{
	pair<vector<Project *>, vector<float>> listOfNotMadeProjects = getListOfNotMadeProjects();

	bool check1 = false;

	for (int i = 0; i < int(listOfNotMadeProjects.first.size()) && !check1; ++i)
	{
		bool check = true;

		for (int j = 0; j < int(listOfNotMadeProjects.first[i]->getListOfProjects()->size()) && check; ++j)
		{
			if (!listOfNotMadeProjects.first[i]->getListOfProjects()->operator[](j)->completed)
			{
				check = false;
			}
		}

		if (check)
		{
			check1 = true;
		}
	}

	if (check1)
	{
		return true;
	}

	bool check2 = false;

	for (int i = 0; i < int(projects.size()) && !check2; ++i)
	{
		if (!projects[i]->completed && projects[i]->wasStarted())
		{
			check2 = true;
		}
	}

	if (check2)
	{
		return true;
	}
	return false;
}
