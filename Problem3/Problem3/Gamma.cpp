#include "Gamma.h"


Gamma::Gamma()
{
	N = gammaSerialNumber;
	++gammaSerialNumber;
}

Gamma::~Gamma()
{
	while (elements.size() != 0)
	{
		popBack();
	}

	S = S + 3 * N;
}