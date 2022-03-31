// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

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



std::string infx2pstfx(std::string inf) {
  std::string postf;
  TStack <char, 100> stack1;
  for (int i = 0; i < inf.size(); i++) {
    int pr = priority(inf[i]);
    if (pr == -1){
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
  return postf;
}

int eval(std::string pref) {
  // добавьте код
  return 0;
}
