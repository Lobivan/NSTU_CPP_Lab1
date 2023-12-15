#include <fstream>
#include <iostream>

#include "MyString.hpp"

int main(void) {
  std::cout << "\n Демонстрация работы операций ввода и вывода из потока: \n";
  MyString str;
  str.print_info();
  std::cout << "введите строку: \n";
  std::cin >> str;
  std::cout << "введённая строка: \n";
  std::cout << str << '\n';
  str.print_info();

  std::cout << "\n Демонстрация работы операций ввода и вывода из файлового "
               "потока: \n";
  char arr[] = "aaa";
  MyString str1(arr);
  str1.print_info();
  std::ofstream f1("text.txt");
  if (!f1) {
    std::cout << "Ошибка открытия файла";
    return 1;
  }
  f1 << str1;
  f1.close();
  MyString str2;
  str2.print_info();
  std::ifstream f2("text.txt");
  if (!f2) {
    std::cout << "Ошибка открытия файла";
    return 1;
  }
  f2 >> str2;
  f2.close();
  str2.print_info();

  std::cout << "\n Демонстрация работы операций ввода и вывода из файлового "
               "потока (в двоичном виде): \n";
  MyString str3(arr);
  str3.print_info();
  std::ofstream f3("text.dat");
  if (!f3) {
    std::cout << "Ошибка открытия файла";
    return 1;
  }
  f3 << str3;
  f3.close();
  MyString str4;
  str4.print_info();
  std::ifstream f4("text.dat");
  if (!f4) {
    std::cout << "Ошибка открытия файла";
    return 1;
  }
  f4 >> str4;
  f4.close();
  str4.print_info();

  return 0;
}