#include "Project.h"


bool Project::reconnect(vector<vector<int> > &techn, vector<vector<int> > &dev, vector<int> &left, vector<int> &right, int i, vector<bool> &used)
{
	bool add = false;

	for (int j = 0; j < int(dev[i].size()) && !add; ++j)
	{
		int index = dev[i][j];
		if (left[index] == -1)
		{
			left[index] = i;
			right[i] = index;
			add = true;
		}
	}

	if (!add)
	{
		bool can = false;
		for (int j = 0; j < int(dev[i].size()); ++j)
		{
			int index = dev[i][j];
			if (!used[index])
			{
				int old = left[index];
				right[i] = index;
				left[index] = i;
				right[old] = -1;

				used[index] = true;
				can = true;

				if (!reconnect(techn, dev, left, right, old, used))
				{
					used[index] = false;
					right[old] = index;
					left[index] = old;
					right[i] = -1;
					can = false;
				}
			}
		}
		if (!can)
		{
			return false;
		}
	}
	else
	{
		for (int j = 0; j < int(techn.size()); ++j)
		{
			used[j] = false;
		}
	}

	return true;
}

bool Project::addDevelopers(bool needAdd, vector<Developer *> &developersForCheck)
{
	vector<Developer *> mappingDevelopers;

	for (int i = 0; i < int(developersForCheck.size()); ++i)
	{
		if (checkDeveloper(developersForCheck[i]) && developersForCheck[i]->getProject() == nullptr)
		{
			mappingDevelopers.push_back(developersForCheck[i]);
		}
	}

	int n = int(technology.size()),
		m = int(mappingDevelopers.size());

	vector<vector<int> > techn(n, vector<int>()), dev(m, vector<int>());

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (mappingDevelopers[j]->checkTechnology(technology[i].first))
			{
				techn[i].push_back(j);
				dev[j].push_back(i);
			}
		}
	}


	vector<int> left(n, -1), right(m, -1);

	bool comp = false;
	vector<bool> used(n, false);

	for (int i = 0; i < m && !comp; ++i)
	{
		if (reconnect(techn, dev, left, right, i, used)) {}

		comp = true;
		for (int j = 0; j < n && comp; ++j)
		{
			if (left[j] == -1)
			{
				comp = false;
			}
		}
	}

	if (needAdd && comp)
	{
		for (int i = 0; i < n; ++i)
		{
			technology[i].second.push_back(mappingDevelopers[left[i]]);
			mappingDevelopers[left[i]]->setProject(this);
		}
		for (int i = 0; i < m; ++i)
		{
			if (right[i] == -1)
			{
				technology[i].second.push_back(mappingDevelopers[dev[i][0]]);
				mappingDevelopers[dev[i][0]]->setProject(this);
			}
		}
	}

	return comp;
}


vector<pair<Technology *, vector<Developer *> > > *Project::getListOfTechnology()
{
	return &technology;
}

vector<Project *> *Project::getListOfProjects()
{
	return &toComplete;
}


string Project::getName()
{
	return name;
}

float Project::getComplexity()
{
	return complexity;
}

bool Project::checkDeveloper(Developer *developer)
{
	for (int i = 0; i < int(technology.size()); ++i)
	{
		if (developer->checkTechnology(technology[i].first))
		{
			return true;
		}
	}
	return false;
}

bool Project::checkDevelopers(vector<Developer *> &developersForCheck)
{
	return addDevelopers(false, developersForCheck);
}


ostream &operator << (ostream& os, const Project &project)
{
	os << "Name: " << project.name << ",    Complexity: " << project.complexity << "\nList of technology (" << project.technology.size() << "):\n";

	for (int i = 0; i < int(project.technology.size()); ++i)
	{
		os << "Technology: " << project.technology[i].first->getName() << "\nDevelopers (" << project.technology[i].second.size() << "):\n";
		for (int j = 0; j < int(project.technology[i].second.size()); ++j)
		{
			os << project.technology[i].second[j] << '\n';
		}

	}

	os << "List of project (" << project.toComplete.size() << "):\n";
	for (int i = 0; i < int(project.toComplete.size()); ++i)
	{
		os << project.toComplete[i]->getName() << '\n';
	}

	return os;
}