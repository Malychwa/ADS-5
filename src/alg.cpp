// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int priority(char ch);
std::string infx2pstfx(std::string inf);
int calcul(char ch, int a, int b);
int eval(std::string pref);


int priority(char ch) {
  switch (ch) {
    case '(':
      return 0;
    case ')':
      return 1;
    case '+':
      return 2;
    case '-':
      return 2;
    case '*':
      return 3;
    case '/':
      return 3;
    default:
      return -1;
  }
}


std::string infx2pstfx(std::string inf) {
  std::string postf;
  TStack <char, 100> stack1;
  for (int i = 0; i < inf.size(); i++) {
    int pr = priority(inf[i]);
    if (pr == -1) {
      postf.push_back(inf[i]);
      postf.push_back(' ');
    } else if (pr == 0 || pr > priority(stack1.get()) || stack1.isEmpty()) {
      stack1.push(inf[i]);
    } else {
      if (pr == 1) {
        while (stack1.get() != '(') {
          postf.push_back(stack1.get());
          stack1.pop();
        }
        stack1.pop();
      } else {
        while (priority(stack1.get()) >= pr) {
          postf.push_back(stack1.get());
          stack1.pop();
        }
        stack1.push(inf[i]);
      }
    }
  }
  while (!stack1.isEmpty()) {
    postf.push_back(stack1.get());
    stack1.pop();
  }
  return postf;
}

int calcul(char ch, int a, int b) {
switch (ch) {
  case '+':
    return (a + b);
  case '-':
    return (a - b);
  case '*':
    return (a * b);
  case '/':
    if (b != 0) {
      return a / b;
    }
  default: return 0;
  }
}


int eval(std::string pref) {
  TStack <int, 100> stack2;
  int res = 0;
  for (int i = 0; i < pref.size(); i++) {
    if (priority(pref[i]) == -1) {
      stack2.push(pref[i] - '0');
    } else if (priority(pref[i]) <= 3) {
      int op2 = stack2.get();
      stack2.pop();
      int op1 = stack2.get();
      stack2.pop();
      stack2.push(calcul(pref[i], op1, op2));
    }
  }
  res = stack2.get();
  return res;
}
