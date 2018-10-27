#pragma once


#include <iostream>
#include <vector>
#include <string>


using namespace std;


extern int serialNumber;
extern int S;


class Base
{
protected:
	int *N;
	
public:
	Base();
	virtual ~Base();

};