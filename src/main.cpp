#include <fstream>
#include <iostream>

#include "MyBinaryString.hpp"
#include "MyString.hpp"

int main(void) {
  std::cout << "\n Демонстрация работы конструкторов: \n";
  MyBinaryString str;
  str.print_info();
  char arr[] = "100101";
  MyBinaryString str1(arr);
  str1.print_info();
  MyBinaryString str2(str1);
  str2.print_info();

  std::cout << "\n Демонстрация работы нового метода: \n";
  std::cout << str1.to_int() << "\n";

  std::cout << "\n Демонстрация работы некоторых старых методов: \n";
  str.resize(2);
  str.print_info();
  std::cout << str.size() << " " << str.max_size() << "\n";

  std::cout << "\n Демонстрация работы некоторых переопределённых методов: \n";
  str.append(arr);
  str.print_info();
  str.insert(3, arr);
  str.print_info();

  std::cout << "\n Демонстрация работы некоторых переопределённых "
               "дружественных методов: \n";
  str = arr + str1;
  std::cout << str << "\n";

  return 0;
}