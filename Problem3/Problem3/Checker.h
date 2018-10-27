#pragma once


#include <fstream>
#include "Alpha.h"
#include "Beta.h"
#include "Gamma.h"


int afterRemoval(vector<unique_ptr<Base> > &elements, int s);

void addElement(vector<unique_ptr<Base> > &elements, int number, vector<int> &index, int type);

void addElement(vector<unique_ptr<Base> > &elements, int type);

void deleteElement(vector<unique_ptr<Base> > &elements, int number, vector<int> &index);

void deleteElement(vector<unique_ptr<Base> > &elements);

void checkerForUser();

void checkerForUnitTest();

void checker();