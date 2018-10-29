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

void checker()
{
	//cout << "Available commands: \n-1 - exit\n0 - user\n1 - demonstration\n";

	//int massege;
	//cin >> massege;
	//if (massege == 0)
	//{
	//	checkerForUser();
	//}
	//else if (massege == 1)
	//{
		demonstration();
	//}
}