#pragma once


#include <iostream>
#include <vector>
#include <string>


using namespace std;


extern int S;


class Base
{
protected:
	static int alphaSerialNumber;
	static int betaSerialNumber;
	static int gammaSerialNumber;


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