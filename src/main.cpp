#include <fstream>
#include <iostream>

#include "MyBinaryString.hpp"
#include "MyStack.hpp"
#include "MyString.hpp"
#include "MyTaskString.hpp"

int main(void) {
  char arr[] = "100001";
  MyString str1(arr);
  MyTaskString str2(arr, 1, 2, false);
  MyBinaryString str3(arr);

  MyStack stack;
  stack.push(&str1);
  stack.push(&str2);
  stack.push(&str3);

  std::cout << " Демонстрация полиморфического поведения классов:\n";
  std::cout << "В стеке все строки хранятся как указатели на MyString, однако, "
               "поскольку функция print() виртуальная, "
               "при её вызове у данных указтелей вызывается "
               "именно фунция изначального объекта, а не только MyString:\n";
  stack.printAll();

  return 0;
}