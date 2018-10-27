#pragma once


#include "Alpha.h"
#include "Beta.h"
#include "Gamma.h"


int afterRemoval(vector<Base*> &elements, int s);

void addElement(vector<Base*> &elements, int number, vector<int> &index, int type);

void addElement(vector<Base*> &elements, int type);

void deleteElement(vector<Base*> &elements, int number, vector<int> &index);

void deleteElement(vector<Base*> &elements);

void checker();