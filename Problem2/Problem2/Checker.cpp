#include "Checker.h"


vector<int> getResult(string &help, bool &needBreak)
{
	vector<int> result;

	int massage;
	cin >> massage;
	
	if (massage == -1)
	{
		needBreak = true;
	}
	else if (massage == 0)
	{
		cout << help;
	}
	else if (massage == 1)
	{
		unsigned int  n;
		cin >> n;

		result = function(n);
	}
	else if (massage == 2)
	{
		int n;
		cin >> n;

		result = function(n);
	}
	else if (massage == 3)
	{
		float d;
		cin >> d;

		result = function(d);
	}
	else if (massage == 4)
	{
		string s;
		getline(cin, s);

		result = function(s);
	}
	else if (massage == 5)
	{
		vector<int> temp1, temp2;

		temp1 = getResult(help, needBreak);
		if (needBreak)
		{
			return result;
		}

		temp2 = getResult(help, needBreak);
		if (needBreak)
		{
			return result;
		}

		if (temp1.size() == temp2.size())
		{
			for (int i = 0; i < int(temp1.size()); ++i)
			{
				for (int j = 0; j < temp2[i]; ++j)
				{
					result.push_back(temp1[i]);
				}
			}
		}

	}
	else if (massage == 6)
	{
		int n;
		cin >> n;

		vector<vector<int> > temp(n);

		for (int i = 0; i < n; ++i)
		{
			temp[i] = getResult(help, needBreak);
			if (needBreak)
			{
				return result;
			}
			for (int j = 0; j < int(temp[i].size()) / 2; ++j)
			{
				swap(temp[i][j], temp[i][temp[i].size() - j - 1]);
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < int(temp[i].size()); ++j)
			{
				result.push_back(temp[i][j]);
			}
		}
	}
	else if (massage == 7)
	{
		string s;
		getline(cin, s);

		short temp = 0;

		result = function(temp);
	}

	return result;
}

vector<int> getResult(ifstream &fileIn)
{
	vector<int> result;

	string massage;
	getline(fileIn, massage);
	if (massage == "")
	{
		getline(fileIn, massage);
	}
	cout << massage << '\n';


	if (massage == "natural (n)")
	{
		unsigned int  n;
		fileIn >> n;
		cout << n << '\n';

		result = function(n);
	}
	else if (massage == "negative (n)")
	{
		int n;
		fileIn >> n;
		cout << n << '\n';

		result = function(n);
	}
	else if (massage == "real (d)")
	{
		float d;
		fileIn >> d;
		cout << d << '\n';

		result = function(d);
	}
	else if (massage == "text (s)")
	{
		string s;
		getline(fileIn, s);
		cout << s << '\n';

		result = function(s);
	}
	else if (massage == "pair (a, b)")
	{
		vector<int> temp1, temp2;

		temp1 = getResult(fileIn);

		temp2 = getResult(fileIn);

		if (temp1.size() == temp2.size())
		{
			for (int i = 0; i < int(temp1.size()); ++i)
			{
				for (int j = 0; j < temp2[i]; ++j)
				{
					result.push_back(temp1[i]);
				}
			}
		}

	}
	else if (massage == "list (n, v1, v2, .... , vn)")
	{
		int n;
		fileIn >> n;
		cout << n << '\n';

		vector<vector<int> > temp(n);

		for (int i = 0; i < n; ++i)
		{
			temp[i] = getResult(fileIn);
			for (int j = 0; j < int(temp[i].size()) / 2; ++j)
			{
				swap(temp[i][j], temp[i][temp[i].size() - j - 1]);
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < int(temp[i].size()); ++j)
			{
				result.push_back(temp[i][j]);
			}
		}
	}
	else if (massage == "else (s)")
	{
		string s;
		getline(fileIn, s);

		short temp = 0;

		result = function(temp);
	}


	return result;
}


void checkerForUser()
{
	string help = "Available commands: \n-1 - exit\n0 - show menu\n1 - natural (n)\n2 - negative (n)\n3 - real (d)\n4 - text (s)\n\
5 - pair (a, b)\n6 - list (n, v1, v2, .... , vn)\n7 - else (s)\n";
	cout << help;

	bool needBreak = false;

	while (!needBreak)
	{
		vector<int> result;

		result = getResult(help, needBreak);

		if (needBreak)
		{
			return;
		}

		cout << "Result: ";
		for (int i = 0; i < int(result.size()); ++i)
		{
			cout << result[i] << ' ';
		}
		cout << '\n';

		result.clear();

		cout << "**********************************\n";
	}
}

void checkerForUnitTest()
{
	ifstream fileIn("Unit tests/Number of unit test.dat");

	int number;
	fileIn >> number;

	fileIn.close();

	for (int i = 0; i < number; ++i)
	{
		cout << "\nUnit test number " << i << '\n';

		string name;
		name = "Unit tests/" + to_string(i) + ".dat";

		fileIn.open(name);

		vector<int> result;

		int countOfrequests;
		fileIn >> countOfrequests;

		for (int j = 0; j < countOfrequests; ++j)
		{

			result = getResult(fileIn);

			cout << "Result: ";
			for (int i = 0; i < int(result.size()); ++i)
			{
				cout << result[i] << ' ';
			}
			cout << '\n';

			result.clear();
		}

		fileIn.close();
	}

	cin.get();
	cin.get();
	cin.get();
}

void checker()
{
	cout << "Available commands: \n-1 - exit\n0 - user\n1 - unit test\n";

	int massege;
	cin >> massege;
	if (massege == 0)
	{
		checkerForUser();
	}
	else if (massege == 1)
	{
		checkerForUnitTest();
	}
}