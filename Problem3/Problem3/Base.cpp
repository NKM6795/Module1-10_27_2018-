#include "Base.h"


int alphaSerialNumber = 1;
int betaSerialNumber = 1;
int gammaSerialNumber = 1;
int S = 0;


Base::~Base()
{
	S = 2 * S - *N + 11;
	delete N;
}

int Base::getN()
{
	return *N;
}

vector<Base*> *Base::getVectorBase()
{
	return &elements;
}

void Base::pushBack(Base *element)
{
	elements.push_back(element);
}

void Base::popBack()
{
	if (elements.size() != 0)
	{
		delete elements.back();
		elements.pop_back();
	}
}