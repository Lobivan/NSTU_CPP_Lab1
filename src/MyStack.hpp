#pragma once

#include "MyString.hpp"

template <class T>
class MyStack {
 private:
  // Узел стека
  struct node {
    T *data;     // ссылка на строку
    node *prev;  // ссылка на предыдущий узел
    node() : data(nullptr), prev(nullptr) {}
  };

  node *last;  // ссылка на вершину стека

 public:
  MyStack() : last(new node) {}
  ~MyStack() {
    node *tmp = last->prev;
    delete last;
    while (tmp != nullptr) {
      last = tmp;
      tmp = last->prev;
      delete last;
    }
  }

  // добавление элемента на вершину стека
  void push(T *p) {
    node *tmp = new node;
    tmp->prev = last;
    tmp->data = p;
    last = tmp;
  }
  // удаление элемента с вершины стека
  void pop() {
    node *tmp = last->prev;
    delete last;
    last = tmp;
  }
  // метод, возвращающий ссылку на строку на вершине стека
  T *top() { return last->data; }

  bool is_empty() { return (last->prev == nullptr); }
};