#include "Checker.h"


int Base::alphaSerialNumber = 1;
int Base::betaSerialNumber = 1;
int Base::gammaSerialNumber = 1;


int afterRemoval(vector<unique_ptr<Base> > &elements, int s)
{
	int SCopy = s;
	for (int i = elements.size() - 1; i >= 0; --i)
	{
		SCopy = afterRemoval(*elements[i]->getVectorBase(), SCopy);

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

void addElement(vector<unique_ptr<Base> > &elements, int number, vector<int> &index, int type)
{
	if (number == 0)
	{
		unique_ptr<Base> newElement;
		if (type == 0)
		{
			newElement = unique_ptr<Base>(new Alpha);
		}
		else if (type == 1)
		{
			newElement = unique_ptr<Base>(new Beta);
		}
		else if (type == 2)
		{
			newElement = unique_ptr<Base>(new Gamma);
		}
		elements.push_back(move(newElement));
	}
	else
	{
		if (index[number - 1] >= 0 && index[number - 1] < int(elements.size()))
		{
			addElement(*elements[index[number - 1]]->getVectorBase(), number - 1, index, type);
		}
	}
}

void addElement(vector<unique_ptr<Base> > &elements, int type)
{
	vector<int> temp;

	addElement(elements, 0, temp, type);
}

void deleteElement(vector<unique_ptr<Base> > &elements, int number, vector<int> &index)
{
	if (number == 0)
	{
		elements.back().reset();
		elements.pop_back();
	}
	else
	{
		if (index[number - 1] >= 0 && index[number - 1] < int(elements.size()))
		{
			deleteElement(*elements[index[number - 1]]->getVectorBase(), number - 1, index);
		}
	}
}

void deleteElement(vector<unique_ptr<Base> > &elements)
{
	if (elements.size() != 0)
	{
		elements.back().reset();
		elements.pop_back();
	}
}


void coutSForCombination(vector<vector<int> > &types)
{
	int result = 0;

	int temp = types[0][0];

	for (int i = 0; i < int(types.size()); ++i)
	{
		if (temp == 0)
		{
			result = result - 2 * types[i][temp + 1] + 11;
		}
		else if (temp == 1)
		{
			result = result - types[i][temp + 1];
		}
		else
		{
			result = result + 3 * types[i][temp + 1];
		}

		if (temp != types[i][0])
		{
			result = 2 * result - types[i][temp + 1] + 11;
			temp = types[i][0];
		}
	}

	result = 2 * result - types[types.size() - 1][temp + 1] + 11;
	cout << "S = " << result << '\n';
}

void getCombination(int aSerialNumber, int bSerialNumber, int cSerialNumber, int M, vector<vector<int> > &types, bool offset)
{
	for (int i = 0; i < int(types.size()) - M - !offset; ++i)
	{
		cout << "	";
	}

	cout << "Alpha: ";
	types[M - 1] = { 0, aSerialNumber, bSerialNumber, cSerialNumber };
	if (M != 1)
	{
		getCombination(aSerialNumber + 1, bSerialNumber, cSerialNumber, M - 1, types, true);
		getCombination(aSerialNumber + 1, bSerialNumber, cSerialNumber, M - 1, types, false);
	}
	else
	{
		coutSForCombination(types);
	}

	for (int i = 0; i < int(types.size()) - M - !offset; ++i)
	{
		cout << "	";
	}

	cout << "Beta: ";
	types[M - 1] = { 1, aSerialNumber, bSerialNumber, cSerialNumber };
	if (M != 1)
	{
		getCombination(aSerialNumber, bSerialNumber + 1, cSerialNumber, M - 1, types, true);
		getCombination(aSerialNumber, bSerialNumber + 1, cSerialNumber, M - 1, types, false);
	}
	else
	{
		coutSForCombination(types);
	}

	for (int i = 0; i < int(types.size()) - M - !offset; ++i)
	{
		cout << "	";
	}

	cout << "Gamma: ";
	types[M - 1] = { 2, aSerialNumber, bSerialNumber, cSerialNumber };
	if (M != 1)
	{
		getCombination(aSerialNumber, bSerialNumber, cSerialNumber + 1, M - 1, types, true);
		getCombination(aSerialNumber, bSerialNumber, cSerialNumber + 1, M - 1, types, false);
	}
	else
	{
		coutSForCombination(types);
	}
}

void getCombination(int M)
{
	if (M > 0 && M < 7)
	{
		vector<vector<int> > types(M, { -1, -1, -1, -1 });

		getCombination(1, 1, 1, M, types, true);
	}
}


void checkerForUser()
{
	vector<unique_ptr<Base> > elements;

	string help = "Available commands: \n-1 - exit\n0 - show menu\n1 - show S\n2 - add Alpha\n3 - add Beta\n4 - add Gamma\n5 - delete back\n\
6 - add Alpha in vector[vector[i1][vector[i2][...[in]]...]] (n, i1, i2, ... , in)\n7 - add Beta invector[vector[i1][vector[i2][...[in]]...]] (n, i1, i2, ... , in)\n\
8 - add Gamma in vector[vector[i1][vector[i2][...[in]]...]] (n, i1, i2, ... , in)\n9 - delete back in vector[vector[i1][vector[i2][...[in]]...]] (n, i1, i2, ... , in)\n\
10 - S after removal\n11 - get Combination (M)\n";
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
		else if (massage >= 2 && massage <= 4)
		{
			addElement(elements, massage - 2);
		}
		else if (massage == 5)
		{
			deleteElement(elements);
		}
		else if (massage >= 6 && massage <= 8)
		{
			int n;
			cin >> n;
			vector<int> index;
			for (int i = 0; i < n; ++i)
			{
				int temp;
				cin >> temp;
				index.push_back(temp);
			}

			addElement(elements, n, index, massage - 6);
		}
		else if (massage == 9)
		{
			int n;
			cin >> n;
			vector<int> index;
			for (int i = 0; i < n; ++i)
			{
				int temp;
				cin >> temp;
				index.push_back(temp);
			}

			deleteElement(elements, n, index);
		}
		else if (massage == 10)
		{
			cout << "S(after removal) = " << afterRemoval(elements, S) << '\n';
		}
		else if (massage == 11)
		{
			int M;
			cin >> M;
			getCombination(M);
		}

		cout << "**********************************\n";
	}

	while (elements.size() != 0)
	{
		deleteElement(elements);
	}
}

void checkerForDemonstration()
{
	ifstream fileIn("Demonstration/Number of demonstrations.dat");

	int number;
	fileIn >> number;

	fileIn.close();

	for (int i = 0; i < number; ++i)
	{
		cout << "\nDemonstration number " << i << '\n';

		vector<unique_ptr<Base> > elements;


		string name;
		name = "Demonstration/" + to_string(i) + ".dat";

		fileIn.open(name);

		int countOfrequests;
		fileIn >> countOfrequests;

		string massage;

		for (int j = 0; j < countOfrequests; ++j)
		{
			getline(fileIn, massage);
			if (massage == "")
			{
				getline(fileIn, massage);
			}
			cout << massage << '\n';

			if (massage == "exit")
			{
				break;
			}
			else if (massage == "show S")
			{
				cout << "S = " << S << '\n';
			}
			else if (massage == "add Alpha")
			{
				addElement(elements, 0);
			}
			else if (massage == "add Beta")
			{
				addElement(elements, 1);
			}
			else if (massage == "add Gamma")
			{
				addElement(elements, 2);
			}
			else if (massage == "delete back")
			{
				deleteElement(elements);
			}
			else if (massage == "add Alpha in vector[vector[i1][vector[i2][...[in]]...]] (n, i1, i2, ... , in)")
			{
				int n;
				fileIn >> n;
				cout << n;
				vector<int> index;
				for (int i = 0; i < n; ++i)
				{
					int temp;
					fileIn >> temp;
					cout << ", " << temp;
					index.push_back(temp);
				}
				cout << '\n';

				addElement(elements, n, index, 0);
			}
			else if (massage == "add Beta in vector[vector[i1][vector[i2][...[in]]...]] (n, i1, i2, ... , in)")
			{
				int n;
				fileIn >> n;
				cout << n;
				vector<int> index;
				for (int i = 0; i < n; ++i)
				{
					int temp;
					fileIn >> temp;
					cout << ", " << temp;
					index.push_back(temp);
				}
				cout << '\n';

				addElement(elements, n, index, 1);
			}
			else if (massage == "add Gamma in vector[vector[i1][vector[i2][...[in]]...]] (n, i1, i2, ... , in)")
			{
				int n;
				fileIn >> n;
				cout << n;
				vector<int> index;
				for (int i = 0; i < n; ++i)
				{
					int temp;
					fileIn >> temp;
					cout << ", " << temp;
					index.push_back(temp);
				}
				cout << '\n';

				addElement(elements, n, index, 2);
			}
			else if (massage == "delete back in vector[vector[i1][vector[i2][...[in]]...]] (n, i1, i2, ... , in)")
			{
				int n;
				fileIn >> n;
				cout << n;
				vector<int> index;
				for (int i = 0; i < n; ++i)
				{
					int temp;
					fileIn >> temp;
					cout << ", " << temp;
					index.push_back(temp);
				}
				cout << '\n';

				deleteElement(elements, n, index);
			}
			else if (massage == "S after removal")
			{
				cout << "S(after removal) = " << afterRemoval(elements, S) << '\n';
			}
			else if (massage == "get Combination (M)")
			{
				int M;
				fileIn >> M;
				getCombination(M);
			}
		}

		while (elements.size() != 0)
		{
			deleteElement(elements);
		}

		fileIn.close();
	}
	cout << "Press \"Enter\" for exit\n";
	cin.get();
	cin.get();
	cin.get();
}

void checker()
{
	cout << "-1 - exit\n0 - user\n1 - demonstration\n";
	int massage;
	cin >> massage;

	if (massage == 0)
	{
		checkerForUser();
	}
	else if (massage == 1)
	{
		checkerForDemonstration();
	}
}