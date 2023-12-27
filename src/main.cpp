#include <fstream>
#include <iostream>

#include "MyBinaryString.hpp"
#include "MyStack.hpp"
#include "MyString.hpp"
#include "MyTaskString.hpp"

int main(void) {
  std::cout << "\n  Демонстрация работы стека обьектов типа MyString\n";
  char arr[] = "100001";
  MyString str1(arr);
  MyTaskString str2(arr, 1, 2, false);
  MyBinaryString str3(arr);

  MyStack<MyString> myStringStack;
  myStringStack.push(&str1);
  myStringStack.push(&str2);
  myStringStack.push(&str3);

  while (myStringStack.is_empty() == false) {
    myStringStack.top()->print();
    std::cout << "\n";
    myStringStack.pop();
  }

  std::cout << "\n  Демонстрация работы стека обьектов типа int\n";
  int a = 1;
  int b = -5;
  int c = 12345;

  MyStack<int> intStack;
  intStack.push(&a);
  intStack.push(&b);
  intStack.push(&c);

  while (intStack.is_empty() == false) {
    std::cout << *(intStack.top()) << "\n";
    intStack.pop();
  }

  std::cout << "\n  Демонстрация работы стека обьектов типа float\n";
  float d = 1.234;
  float e = -5.678;
  float f = 12345.6;

  MyStack<float> floatStack;
  floatStack.push(&d);
  floatStack.push(&e);
  floatStack.push(&f);

  while (floatStack.is_empty() == false) {
    std::cout << *(floatStack.top()) << "\n";
    floatStack.pop();
  }

  return 0;
}