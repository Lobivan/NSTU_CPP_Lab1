#include "MyString.hpp"

int main(void) {
  std::cout << "\n Демонстрация работы конструктора по умолчанию \n";
  MyString str1;
  str1.print_info();

  std::cout << "\n Демонстрация работы конструктора с параметром размера \n";
  MyString str2(4);
  str2.print_info();

  std::cout
      << "\n Демонстрация работы конструктора с параметром массива символов \n";
  size_t arrlen = 9;
  char *arr = new char[arrlen];
  for (int i = 0; i < arrlen - 1; i++) {
    arr[i] = (int)'0' + i;
  }
  MyString str3(arr);
  str3.print_info();

  std::cout << "\n Демонстрация работы конструктора копирования \n";
  MyString str4(str3);
  str4.print_info();

  delete[] arr;
  return 0;
}