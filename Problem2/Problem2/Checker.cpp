#include "Checker.h"


void checker()
{
	string help = "Available commands: \n-1 - exit\n0 - show menu\n1 - natural(n)\n";
	cout << help;

	while (true)
	{
		int massage;
		cin >> massage;
		if (massage == -1)
		{
			break;
		}
		else if (massage == 0)
		{
			cout << help;
		}


		cout << "**********************************\n";
	}
}