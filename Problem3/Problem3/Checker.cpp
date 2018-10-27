#include "Checker.h"


int afterRemoval(vector<Base*> &elements)
{
	int SCopy = S;
	for (int i = elements.size() - 1; i >= 0; --i)
	{
		if (typeid(*elements[i]) == typeid(Alpha))
		{
			SCopy = SCopy - 2 * elements[i]->getN() + 11;
		}
		else if (typeid(*elements[i]) == typeid(Beta))
		{
			SCopy = SCopy - elements[i]->getN();
		}
		else
		{
			SCopy = SCopy + 3 * elements[i]->getN();
		}

		SCopy = 2 * SCopy - elements[i]->getN() + 11;
	}

	return SCopy;
}


void checker()
{
	vector<Base*> elements;

	string help = "Available commands: \n-1 - exit\n0 - show menu\n1 - show S\n2 - add Alpha\n3 - add Beta\n4 - add Gamma\n5 - delete back\n6 - S after removal\n";
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
		else if (massage == 1)
		{
			cout << "S = " << S << '\n';
		}
		else if (massage == 2)
		{
			Base *newElement = new Alpha;
			elements.push_back(newElement);
		}
		else if (massage == 3)
		{
			Base *newElement = new Beta;
			elements.push_back(newElement);
		}
		else if (massage == 4)
		{
			Base *newElement = new Gamma;
			elements.push_back(newElement);
		}
		else if (massage == 5)
		{
			if (elements.size() != 0)
			{
				delete elements.back();
				elements.pop_back();
			}
		}
		else if (massage == 6)
		{
			cout << "S(after removal) = " << afterRemoval(elements) << '\n';
		}

		cout << "**********************************\n";
	}

}