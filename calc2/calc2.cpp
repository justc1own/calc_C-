//_CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <string>
#include <algorithm>
//#include <sstream>
#include "list.h"
#include "compleX.h"
#include "parse.h"

using namespace std;

const int sizeEquat = 100;
const int sizeName  = 100;
const double badSign = 5050;

string equat[sizeEquat], Name[sizeName];

// math consts
const string PI = "3.141592653589";
const string E  = "2.718281828459";



string strProcessing(string const & str) { //добавить унарные минусы
    string ans = "";
    int len = str.size();
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') continue;
        else ans += str[i];
    }
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == '-' && (i == 0 || i != 0 && ans[i - 1] == '(')) ans[i] = '~';
    }
    return ans;
}

string mkStr(string const &s, int c) {
    string ans = "";
    int len = s.size();
    if (c == 0) {
        ans = strProcessing(s);
    } else {
        int i = 0;
        string name = "";
        while (i < len && s[i] != '=') {
            if (s[i] != ' ') name += s[i];
            i++;
        }
        Name[c] = name;
        string eq = "";
        i++;
        for (; i < len; i++) {
            eq += s[i];
        }
        ans = strProcessing(eq);
    }

    return ans;
}

//node* phead = nullptr;

compleX* getRes(string str) { // строка без пробелов и с унарными минусами
  stack<compleX*> nums;
  stack<string>   oper;

  int len = str.size();
  //str += '\n';
  string hlp = "";
  cout << "getRes ::" << endl;
  for (int i = 0; i < len; i++) {
      //cout <<"hlp=" <<  hlp << endl;
    /*if (i < len - 2 && (str[i + 1] == '+' || str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == '-' || str[i + 1] == '~' || str[i + 1] == '(' || str[i + 1] == ')')
        || i == len - 1) {
      compleX* num = numbProcessing(hlp);
      nums.push(num);
      hlp = "";
    }
    */
      //cout << "i=" << i << endl;
    if (checkIsOperation(hlp)) {
          oper.push(hlp);
          hlp = "";
    } else if (str[i] == '+' || str[i] == '*' || str[i] == '/' || str[i] == '-' || str[i] == '~' || str[i] == '(' || str[i] == '|') {
      if (hlp.size() != 0) {
            compleX* num = numbProcessing(hlp);
            nums.push(num);
      }
      hlp = "";

      string symb = ""; symb += str[i];
      //oper.push(symb);
      if (symb == "|") continue;
      if (!oper.empty() && prior(oper.top()) >= prior(symb) || oper.empty()) { //добавляем знак, если все предыдущие знаки имеют больший приоритет  || oper.empty()
        oper.push(symb);
      }
      else { // если знак снизу имеет меньший приоритет, нужно освободить стек
        doOperations(nums, oper);
        oper.push(symb);
      }
    }
    else if (str[i] == ')') {
        cout << "HERE" << endl;
      compleX* num = numbProcessing(hlp);
      nums.push(num);
      hlp = "";
      cout << "ALLO nah" << nums.size() << endl;
      while (!oper.empty() && oper.top() != "(") {
        doOperations(nums, oper);
      }
    } else {
        hlp += str[i];
    }

  }

  if (hlp != "") {
      //cout << "hlp=" << hlp << endl;
      compleX* num = numbProcessing(hlp);
      nums.push(num);
  }

  while (!oper.empty()) {
    doOperations(nums, oper);
  }

  if (nums.size() != 1) {
    cout << "Bad wars\n";
  }
  if (!nums.empty()) {
    return nums.top();
  } else {
    compleX* res = new compleX(badSign, badSign);
    return res;
  }
}

int main() {
    compleX* pi = getComplexNum(PI);
    compleX* e = getComplexNum(E);
    node* Ppi = new node(pi, "pi");
    node* Pe = new node(e, "e");
    addToList(Ppi);
    addToList(Pe);


    cout << "Welcome to the calculator\nYou can explote pi and e consts\nYou can explote trig funct, log, exp, prime funct\nEnter the equats and after enter 'stop':\n";
    string s;
    int cnt = 0;
    while (getline(cin, s)) {
        if (s == "stop") {
            break;
        }
        equat[cnt] = mkStr(s, cnt);
        cnt++;
    }

    /*for (int i = 0; i < cnt; i++) {
        cout << "Name=" << Name[i] << " equ=" << equat[i] << endl;
    }*/

    for (int i = cnt - 1; i >= 0; i--) {
        //cout << equat[i] << endl;;
        compleX* tmp = getRes(equat[i]);
        //cout << Name[i] << endl;
        if (i != 0) {
            node* a = new node(tmp, Name[i]);
            addToList(a);
        } else {
            cout << tmp->real << " + " << tmp->img << " *j" << endl;
        }
    }
    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       