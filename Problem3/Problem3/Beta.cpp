#include "Beta.h"


Beta::Beta()
{
	N = new int(betaSerialNumber);
	++betaSerialNumber;
}

Beta::~Beta()
{
	while (elements.size() != 0)
	{
		popBack();
	}

	S = S - *N;
}