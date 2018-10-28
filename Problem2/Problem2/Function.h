#pragma once


#include <iostream>
#include <vector>
#include <math.h>
#include <string>


using namespace std;


unsigned int factorial(unsigned int value);


int pow(int value, int power);

int pow(int value, int power, int mod);

template<typename T>
inline vector<int> function(T value);


template<>
inline vector<int> function(unsigned int value)
{
	vector<int> result;

	int number = int(factorial(value)) - int(value * value);

	for (int k = 2; k <= 111; ++k)
	{
		result.push_back(number % k);
	}

	return result;
}

template<>
inline vector<int> function(int value)
{
	vector<int> result;

	int number = (pow(value, 8) + pow(value, 3)) % 211;

	int maxPow = 0;

	while (pow(4, maxPow) < number)
	{
		++maxPow;
	}
	result.resize(maxPow + 1, 0);

	while (number != 0)
	{
		int power = 0;
		while (number - pow(4, maxPow) >= 0)
		{
			number -= pow(4, maxPow);
			++power;
		}
		result[maxPow] = power;

		--maxPow;
	}

	return result;
}

template<>
inline vector<int> function(float value)
{
	vector<int> result;

	for (int k = 1; k <= 42; ++k)
	{
		int number = int(exp(1.f / cos(k * value)));

		result.push_back(number % 311);
	}

	return result;
}

template<>
inline vector<int> function(string value)
{
	vector<int> result;

	int k = -1;

	for (int i = 0; i < int(value.size()); ++i)
	{
		if (value[i] >= 48 && value[i] <= 57 && k == -1)
		{
			k = int(value[i]) - 48;
		}
		else if (value[i] >= 48 && value[i] <= 57 && k >= 0 && k <= 9)
		{
			k = k * 10 + int(value[i]) - 48;
		}
		else if (value[i] >= 48 && value[i] <= 57 && k >= 10 && k <= 99)
		{
			k = -1;
		}
		else if (k >= 10 && k <= 99)
		{
			int number = pow(k, k, 411);
			number += number < 0 ? 411 : 0;
			result.push_back(number);
			k = -1;
		}
		else
		{
			k = -1;
		}
	}
	if (k >= 10 && k <= 99)
	{
		int number = pow(k, k, 411);
		number += number < 0 ? 411 : 0;
		result.push_back(number);
		k = -1;
	}

	return result;
}


template<typename T>
inline vector<int> function(T value)
{
	vector<int> result({ 4, 0, 71 });
	return result;
}