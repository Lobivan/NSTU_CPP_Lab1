#pragma once

#include "MyString.hpp"

class MyStack {
 private:
  // Узел стека
  struct node {
    MyString *str;  // ссылка на строку
    node *prev;     // ссылка на предыдущий узел
    node() : str(nullptr), prev(nullptr) {}
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
  void push(MyString *p) {
    node *tmp = new node;
    tmp->prev = last;
    tmp->str = p;
    last = tmp;
  }
  // удаление элемента с вершины стека
  void pop() {
    node *tmp = last->prev;
    delete last;
    last = tmp;
  }
  // метод, возвращающий ссылку на строку на вершине стека
  MyString *top() { return last->str; }

  // метод, выводящий каждую строку из стека
  void printAll() {
    node *tmp = last;
    int i = 1;
    while (tmp->prev != nullptr) {
      std::cout << i++ << ": \'";

      // print() - виртуальная фунция, у базового класса печатаетя только
      // строка, у бинарного числа после строки печатается это число в
      // десятичной системе счисления, у строки из списка задач перед строкой
      // печатается время начала, время конца и признак выполнения
      tmp->str->print();

      std::cout << "\'\n";
      tmp = tmp->prev;
    }
  }
};