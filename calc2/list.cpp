#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "list.h"
#include "compleX.h"

using namespace std;


const double badSign = 5050;

node* phead = nullptr;

bool checkInList(string s) {
	node* tmp = phead;
	while (tmp) {
		if (tmp->name == s) {
			return true;
		}
		else {
			tmp = tmp->next;
		}
	}
	return false;
}

compleX* getNode(string s) {
	node* tmp = phead;
	while (tmp) {
		if (tmp->name == s) {
			return (tmp->data);
		}
		else {
			tmp = tmp->next;
		}
	}

	
	compleX* res = new compleX(badSign, badSign);
	return res;
}

node* create(compleX* a, string name) {
	node* Node = new node(a, name);
	return Node;
}

void addToList(node* pnew) {

	if (phead == nullptr) phead = pnew;
	else {
		node* tmp = phead;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = pnew;
		//tmp->prev->next = tmp;
	}

	return;
}