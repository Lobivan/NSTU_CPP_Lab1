#include "MyString.hpp"

int main(void) {
  std::cout << "\n Демонстрация работы оператора сложения со строкой типа "
               "char* и оператора присваивания: \n";
  size_t arrlen = 9;
  char *arr = new char[arrlen];
  for (int i = 0; i < arrlen - 1; i++) {
    arr[i] = (int)'0' + i;
  }
  MyString str3(arr);
  str3.print_info();
  str3 = str3 + arr;  // Вызов оператора сложения со строкой типа char* и
  // оператора присваивания
  str3.print_info();
  str3 = arr + str3;
  str3.print_info();

  std::cout
      << "\n Демонстрация работы оператора сложения 2-х объектов класса: \n";
  MyString str4(arr);
  str3.print_info();
  str3 = str3 + str4;  // Вызов оператора сложения 2-х объектов класса
  str3.print_info();

  std::cout << "\n Демонстрация работы оператора вычитания как удаления "
               "подстроки: \n";
  str4.resize(4);
  str3.print_info();
  str3 = str3 - str4;  // Вызов оператора вычитания как удаления подстроки
  str3.print_info();

  std::cout << "\n Демонстрация работы операции индексирования: \n";
  str3.print();
  std::cout << "\n";
  for (int i = 0; i < str3.size(); i += 5) {
    char c = str3[i];  // Вызов операции индексирования
    std::cout << "По индексу " << i << " находится символ " << c << "\n";
  }

  delete[] arr;
  return 0;
}