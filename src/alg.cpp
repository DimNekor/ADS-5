// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int PrioritySym(char sym) {
  if (sym == '*' || sym == '/')
    return 1;
  else if (sym == '-' || sym == '+')
    return 2;
  return 0;
}

bool isNum(char ch) {
  if (ch >= '0' && ch <= '9') return true;
  return false;
}

bool isOper(char ch) {
  if (ch == '-' || ch == '+' || ch == '*' || ch == '/')
    return true;
  else
    return false;
}

int ChToInt(char str) {
  char mas[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  for (int i = 0; i < 10; i++) {
    if (str == mas[i]) return i;
  }
}

std::string infx2pstfx(std::string inf) {
  std::string rez = "";
  TStack<char> stack;
  stack.push('(');
  for (int i = 0; i < inf.length(); i++) {
    if (isNum(inf[i])) {
      rez = rez + inf[i] + ' ';
    } else if (inf[i] == '(')
      stack.push(inf[i]);
    else if (isOper(inf[i])) {
      stack.push(inf[i]);
      if (isOper(stack.getNext())) {
        if (PrioritySym(inf[i]) >= PrioritySym(stack.getNext())) {
          rez = rez + stack.getNext() + ' ';
          stack.delNext();
        }
      } else if (i == inf.length() - 1)
        rez = rez + stack.getItem();
    } else if (inf[i] = ')') {
      while (stack.getItem() != '(') {
        rez = rez + stack.getItem() + ' ';
        stack.pop();
      }
      stack.pop();
    }
    if (i == inf.length() - 1) {
      while (stack.getItem() != '(') {
        if (stack.getNext() == '(') {
          rez = rez + stack.getItem();
          stack.pop();
        } else {
          rez = rez + stack.getItem() + ' ';
          stack.pop();
        }
      }
    }
  }
  return rez;
}

int eval(std::string post) {
  int rez = 0;
  TStack<int> stack;
  for (int i = 0; i < post.length(); i++) {
    if (isNum(post[i])) {
      stack.push(ChToInt(post[i]));
    } else if (isOper(post[i])) {
      if (post[i] == '+') rez = stack.getNext() + stack.getItem();
      if (post[i] == '-') rez = stack.getNext() - stack.getItem();
      if (post[i] == '*') rez = stack.getNext() * stack.getItem();
      if (post[i] == '/') rez = stack.getNext() / stack.getItem();
      stack.pop();
      stack.pop();
      stack.push(rez);
    }
  }
  return rez;
}
