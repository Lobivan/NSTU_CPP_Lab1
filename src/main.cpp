#include "MyString.hpp"

int main(void) {
  std::cout << "\n Демонстрация работы конструктора по умолчанию \n";
  MyString str1;
  std::cout << "размер строки: " << str1.size() << "\n";
  std::cout << "максимальный размер строки: " << str1.max_size() << "\n";
  std::cout << "строка: \'";
  str1.print();
  std::cout << "\'\n";

  std::cout << "\n Демонстрация работы конструктора с параметром размера \n";
  MyString str2(4);
  std::cout << "размер строки: " << str2.size() << "\n";
  std::cout << "максимальный размер строки: " << str2.max_size() << "\n";
  std::cout << "строка: \'";
  str2.print();
  std::cout << "\'\n";

  std::cout
      << "\n Демонстрация работы конструктора с параметром массива символов \n";
  size_t arrlen = 9;
  char *arr = new char[arrlen];
  for (int i = 0; i < arrlen - 1; i++) {
    arr[i] = (int)'0' + i;
  }
  MyString str3(arr);
  delete[] arr;
  std::cout << "размер строки: " << str3.size() << "\n";
  std::cout << "максимальный размер строки: " << str3.max_size() << "\n";
  std::cout << "строка: \'";
  str3.print();
  std::cout << "\'\n";

  std::cout << "\n Демонстрация работы конструктора копирования \n";
  MyString str4(str3);
  std::cout << "размер строки: " << str4.size() << "\n";
  std::cout << "максимальный размер строки: " << str4.max_size() << "\n";
  std::cout << "строка: \'";
  str4.print();
  std::cout << "\'\n";
  return 0;
}