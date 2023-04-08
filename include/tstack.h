// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

#include <string>
#include <iostream>

template<typename T>
class TStack {
  template <typename T>
class TStack {
 private:
  struct Item {
    T item;
    Item* next;
  };
  Item* head;
  TStack::Item* create(const T&);

 public:
  TStack() : head(nullptr){};
  bool isEmpty();
  void push(T);
  void pop();
  T getItem();
  T getNext();
  void delNext();
  ~TStack();
};
  
template<typename T>
typename TStack<T>::Item* TStack<T>::create(const T& value) {
  Item* temp = new Item;
  temp->item = value;
  temp->next = nullptr;
  return temp;
}

template <typename T>
bool TStack<T>::isEmpty() {
  if (head == nullptr) return true;
  return false;
}

template <typename T>
void TStack<T>::push(T ch) {
  if (isEmpty()) {
    head = create(ch);
  } else {
    Item* temp = create(ch);
    temp->next = head;
    head = temp;
  }
}

template <typename T>
void TStack<T>::pop() {
  if (!isEmpty()) {
    Item* temp = head->next;
    delete head;
    head = temp;
  }
}

template <typename T>
T TStack<T>::getItem() { return head->item; }

template <typename T>
T TStack<T>::getNext() { return head->next->item; }

template <typename T>
void TStack<T>::delNext() {
  Item* temp = head->next->next;
  delete head->next;
  head->next = temp;
}

template <typename T>
TStack<T>::~TStack() {
  while (!isEmpty()) pop();
}

#endif  // INCLUDE_TSTACK_H_
