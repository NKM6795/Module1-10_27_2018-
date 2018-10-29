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


void coutSForCombination(vector<vector<int> > &types);

void getCombination(int aSerialNumber, int bSerialNumber, int cSerialNumber, int M, vector<vector<int> > &types, bool offset);

void getCombination(int M);


void checkerForUser();

void checkerForDemonstration();

void checker();