#include "Gamma.h"


Gamma::~Gamma()
{
	while (elements.size() != 0)
	{
		popBack();
	}

	S = S + 3 * *N;
}