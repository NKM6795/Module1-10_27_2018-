#include "Checker.h"


void demonstration()
{
	Company *company = new Company("F");

	company->setTechnology("Data/Technology.dat");

	company->setDevelopers("Data/Developers.dat");
	
	company->setProjects("Data/Projects.dat");

	company->randomConnectionsInProjects();

	company->randomConnectionsInDevelopers();

	delete company;
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