#pragma once


#include <iostream>
#include <vector>
#include <string>


using namespace std;


extern int alphaSerialNumber;
extern int betaSerialNumber;
extern int gammaSerialNumber;
extern int S;


class Base
{
protected:
	int *N;
	vector<Base*> elements;
	
public:
	Base() {}
	virtual ~Base();

	int getN();

	vector<Base*> *getVectorBase();

	void pushBack(Base *element);

	void popBack();
};