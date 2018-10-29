#include "Checker.h"


void demonstration()
{
	bool shortDemonstration;

	cout << "Available commands: \n-1 - exit\n0 - short demonstration\n1 - demonstration\n";

	int massege;
	cin >> massege;
	if (massege == -1)
	{
		return;
	}
	if (massege == 0)
	{
		shortDemonstration = true;
	}
	else if (massege == 1)
	{
		shortDemonstration = false;
	}

	Company *company = new Company("F");


	company->setTechnology("Data/Technology.dat", shortDemonstration);

	company->setDevelopers("Data/Developers.dat", shortDemonstration);
	
	company->setProjects("Data/Projects.dat", shortDemonstration);


	company->randomConnectionsInProjects();

	company->randomConnectionsInDevelopers();


	company->coutAllElement();

	company->coutListOfNotMadeProjects();

	cout << "Work company with period 24h:\n\n";

	while (company->canWork())
	{
		company->work(24.f);

		company->coutAllProject();
	}

	delete company;

	cin.get();
	cin.get();
	cin.get();
}

void checkerForUser()
{
	cout << "Input company name\n";
	string name;
	getline(cin, name);
	getline(cin, name);

	Company *company = new Company(name);

	cout << "Input technology: count, name[i], coefficientTime[i], probabilityOfChange[i], coefficientForCountOfDeveloper[i]\n";
	company->setTechnology();

	cout << "Input developers: count, name[i], efficiency[i], count of technology[i], \n\
        technology name[j]\n";
	company->setDevelopers();


	cout <<  "Input projects: count, name[i], complexity[i], coefficientForTime[i][4], count of technology[i], \n\
        technology name[j]\ncount of project[i], \n        project name[j]\n";
	company->setProjects();

	company->coutAllElement();

	company->coutListOfNotMadeProjects();

	cout << "Input delta time\n";
	float delta;
	cin >> delta;

	while (company->canWork())
	{
		company->work(24.f);

		company->coutAllProject();
	}

	delete company;

	cin.get();
	cin.get();
	cin.get();

}

void checker()
{
	cout << "Available commands: \n-1 - exit\n0 - user\n1 - demonstration\n";

	int massege;
	cin >> massege;
	if (massege == 0)
	{
		checkerForUser();
	}
	else if (massege == 1)
	{	
		demonstration();
	}
}