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
	int N;
	vector<unique_ptr<Base> > elements;
	
public:
	Base() {}
	virtual ~Base();

	int getN();

	vector<unique_ptr<Base> > *getVectorBase();

	void pushBack(unique_ptr<Base> element);

	void popBack();
};