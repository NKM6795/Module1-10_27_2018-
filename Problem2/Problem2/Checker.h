#pragma once


#include <fstream>
#include "Function.h"



vector<int> getResult(string &help, bool &needBreak);

vector<int> getResult(ifstream &fileIn);

void checkerForUser();

void checkerForUnitTest();

void checker();