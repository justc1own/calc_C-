#include <iostream>
#include <string>
#include <algorithm>
#include "compleX.h"
#include "list.h"
#include "func.h"
#include <stack>



using namespace std;

const double badSign = 5050;


int prior(string str) {
	if (str == "(" || str == "exp" || str == "logBase" || str == "sin" || str == "cos" || str == "tg" || str == "ctg" || str == "~") return 1;
	else if (str == "*" || str == "/") return 2;
	else return 3;
}

int unarBinar(string str) { // бинарный или унарный оператор
	if (str == "exp"  || str == "sin" || str == "cos" || str == "tg" || str == "ctg" || str == "~") return 1;
	else return 2;
}

bool checkIsNum(string str) {
	bool isJ = 0;
	int len = str.size();
	if (len == 0) {
		return false;
	}
	for (int i = 0; i < len; i++) {
		if ('0' <= str[i] && str[i] <= '9' || str[i] == 'j' && !isJ || str[i] == '.') {
			if (str[i] == 'j') {
				isJ = 1;
			}
			continue;
		} else {
			return false;
		}
	}

	return true;
}

double getDouble(string str) {
	//cout << "str=" << str << endl;
	if (str.size() == 0) {
		return 0.0;
	}
	double x = 0.0;
	int len = str.size();

	int i = 0;
	while (i < len && str[i] != '.') {
		x *= 10;
		x += double(str[i] - '0');
		i++;
	}
	//cout << "X=" << x << endl;
	i++;
	string sh = "";
	while (i < len) {
		sh += str[i];
		i++;
	}
	reverse(sh.begin(), sh.end());
	double q = 0.0;
	for (int j = 0; j < int(sh.size()); j++) {
		q += double(sh[j] - '0');
		q /= 10.0;
	}

	return (x + q);
}

compleX* getComplexNum(string str) {
	string s1 = "", s2 = "";
	int i = 0;
	int len = str.size();
	while (i < len && str[i] != 'j') {
		s1 += str[i];
		i++;
	}
	i++;
	while (i < len) {
		s2 += str[i];
		i++;
	}

	double a1 = getDouble(s1), a2 = getDouble(s2);
	//std::cout << str << " == " << a1 << " +j*" << a2 << std::endl;
	compleX* res = new compleX(a1, a2);
	return res;
}

bool checkIsOperation(string str) {
	string sh[] = { "exp", "cos", "sin", "tg", "ctg", "logBase" };
	int sz = 6;
	for (int i = 0; i < sz; i++) {
		if (str == sh[i]) return true;
	}

	return false;
}

void doOperations(stack<compleX*> & nums, stack<string> & oper) {
	while (!oper.empty()) { //&& prior(oper.top()) != '('
		if (oper.top() == "(") {
			oper.pop();
			break;
		}
		string symb = "";
		symb += oper.top();
		int unar = unarBinar(symb);
		if (unar == 1) { // нужно расширить на другие унарные операции
			compleX* num = nums.top();
			nums.pop();

			if (symb == "~") {
				nums.push(neg(num));
			} else if (symb == "cos") {
				double tmpRes = cos(num->real);
				compleX* newNum = new compleX(tmpRes, 0);
				nums.push(newNum);
			} else if (symb == "sin") {
				double tmpRes = sin(num->real);
				compleX* newNum = new compleX(tmpRes, 0);
				nums.push(newNum);
			} else if (symb == "tg") {
				double tmpRes = tg(num->real);
				compleX* newNum = new compleX(tmpRes, 0);
				nums.push(newNum);
			} else if (symb == "ctg") {
				double tmpRes = ctg(num->real);
				compleX* newNum = new compleX(tmpRes, 0);
				nums.push(newNum);
			} else if (symb == "exp") {
				double tmpRes = exp(num->real);
				compleX* newNum = new compleX(tmpRes, 0);
				nums.push(newNum);
			}
		} else {
			cout << "HERE -- " << oper.top() << " sz=" << nums.size() << endl;
			compleX* rght = nums.top(); nums.pop(); compleX* lft = nums.top(); nums.pop();
			if (symb == "*") {
				compleX* num = mltC(lft, rght);
				nums.push(num);
			}
			else if (symb == "/") {
				compleX* num = divC(lft, rght);
				nums.push(num);
			} else if (symb == "+") {
				compleX* num = sumC(lft, rght);
				nums.push(num);
			} else if (symb == "-") {
				compleX* num = subtrC(lft, rght);
				nums.push(num);
			} else if (symb == "logBase") {
				double l = lft->real; double r = rght->real;
				double tmpRes = logBase(l, r);
				compleX* newNum = new compleX(tmpRes, 0);
				nums.push(newNum);
			} 
		}
		oper.pop();
	}
	return;
}

compleX* numbProcessing(string hlp) {
	compleX* tmp = new compleX(0, 0);
	if (checkIsNum(hlp)) {
		tmp = getComplexNum(hlp);
	}
	else { // проводим поиск по переменным списка
		if (checkInList(hlp) == false) {
			// обработаем ошибку
			compleX* res = new compleX(badSign, badSign);
			return res;
		}
		else {
			tmp = getNode(hlp);
		}
	}

	return tmp;
}