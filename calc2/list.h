#pragma once
#include <string>
#include "compleX"
#include "compleX.h"

using namespace std;

struct node {
	compleX* data;
	string name;
	node* next;
	node* prev;

	node(compleX* data, string name, node* next = nullptr, node* prev = nullptr) :
		data(data), name(name), next(next), prev(prev) {}

	//~node();
};



bool checkInList(string s);
compleX* getNode(string s);
void addToList(node* pnew);
node* create(compleX* a, string s);