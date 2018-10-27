#include "Gamma.h"


Gamma::Gamma()
{
	N = new int(gammaSerialNumber);
	++gammaSerialNumber;
}

Gamma::~Gamma()
{
	while (elements.size() != 0)
	{
		popBack();
	}

	S = S + 3 * *N;
}