#include "Base.h"


int alphaSerialNumber = 1;
int betaSerialNumber = 1;
int gammaSerialNumber = 1;
int S = 0;


Base::~Base()
{
	S = 2 * S - N + 11;
}

int Base::getN()
{
	return N;
}

vector<unique_ptr<Base> > *Base::getVectorBase()
{
	return &elements;
}

void Base::pushBack(unique_ptr<Base> element)
{
	elements.push_back(move(element));
}

void Base::popBack()
{
	if (elements.size() != 0)
	{
		elements.back().reset();
		elements.pop_back();
	}
}