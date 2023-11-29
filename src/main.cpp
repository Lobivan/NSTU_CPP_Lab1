#include "MyString.hpp"

int main(void) {
  std::cout << "\n Демонстрация работы конструктора по умолчанию: \n";
  MyString str1;
  str1.print_info();

  std::cout << "\n Демонстрация работы конструктора с параметром размера: \n";
  MyString str2(4);
  str2.print_info();

  std::cout << "\n Демонстрация работы конструктора с параметром массива "
               "символов: \n";
  size_t arrlen = 9;
  char *arr = new char[arrlen];
  for (int i = 0; i < arrlen - 1; i++) {
    arr[i] = (int)'0' + i;
  }
  MyString str3(arr);
  str3.print_info();

  std::cout << "\n Демонстрация работы конструктора копирования: \n";
  MyString str4(str3);
  str4.print_info();

  std::cout << "\n Демонстрация работы метода изменения размера: \n";
  str4.resize(5);
  str4.print_info();
  str4.resize(11);
  str4.print_info();

  std::cout << "\n Демонстрация работы метода добавления массива символов в "
               "конец строки: \n";
  str4.append(arr);
  str4.print_info();
  str4.append(str4);
  str4.print_info();

  std::cout << "\n Демонстрация работы метода поиска подстроки в строке: \n";
  std::cout
      << "Поиск подстроки \'123\' в строке \'01234012345670123401234567\': \n";
  char substr[] = "123";
  size_t res = str4.find(substr);
  do {
    std::cout << res << " ";
    res = str4.find(substr, ++res);
  } while (res != (size_t)-1);
  std::cout << "\n";

  delete[] arr;
  return 0;
}