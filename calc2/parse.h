#pragma once
#include <string>
#include <stack>
#include "compleX.h"

using namespace std;

int unarBinar(string str);
bool checkIsNum(string str);
compleX* getComplexNum(string str);
compleX* numbProcessing(string hlp);
void doOperations(stack<compleX*> &nums, stack<string> &oper);
bool checkIsOperation(string str);
compleX* getComplexNum(string str);
int prior(string str);