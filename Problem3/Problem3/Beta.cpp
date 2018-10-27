#include "Beta.h"


Beta::Beta()
{
	N = betaSerialNumber;
	++betaSerialNumber;
}

Beta::~Beta()
{
	while (elements.size() != 0)
	{
		popBack();
	}

	S = S - N;
}