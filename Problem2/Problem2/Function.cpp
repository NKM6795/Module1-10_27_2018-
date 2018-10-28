#include "Function.h"


unsigned int factorial(unsigned int value)
{
	if (value == 0 || value == 1)
	{
		return 1;
	}
	else
	{
		return value * factorial(value - 1);
	}
}


int pow(int value, int power)
{
	if (value == 0)
	{
		return 0;
	}
	else if (value == 1)
	{
		return 1;
	}
	else if (power == 0)
	{
		return 1;
	}
	else if (power == 1)
	{
		return value;
	}
	else if (power % 2 == 0)
	{
		return pow(value, power / 2) * pow(value, power / 2);
	}
	else
	{
		return pow(value, power - 1) * value;
	}
}

int pow(int value, int power, int mod)
{
	if (power == 0)
	{
		return 1;
	}
	else if (power % 2 == 0)
	{
		int x = pow(value, power / 2, mod);
		return (x * x) % mod;
	}
	else
	{
		int x = pow(value, power - 1, mod);
		return (x * value) % mod;
	}
}
