#include "Beta.h"


Beta::~Beta()
{
	while (elements.size() != 0)
	{
		popBack();
	}

	S = S - *N;
}