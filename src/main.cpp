#include <exception>
#include <iostream>

#include "MyBinaryString.hpp"
#include "MyStack.hpp"
#include "MyString.hpp"
#include "MyTaskString.hpp"

int main(void) {
  char arr[] = "abcd";
  MyString str1(arr);
  MyBinaryString str2;
  MyTaskString str3;

  std::cout << "  Демонстрация обработки исключений:\n";

  std::cout << "\n Выход за границу массива(строки):\n";
  try {
    for (int i = 0; i < 10; i++) {
      std::cout << str1[i] << "\n";
    }
  } catch (std::exception &e) {
    std::cerr << "exeption: " << e.what() << "\n";
  }

  std::cout << "\n Попытка записать в бинарную строку что-то кроме 0 или 1:\n";
  try {
    str2.append(arr);
  } catch (std::exception &e) {
    std::cerr << "exeption: " << e.what() << "\n";
  }

  std::cout << "\n Попытка указать некорректное время начала или конца в "
               "строке-задании:\n";
  try {
    str3.setStartHour(25);
  } catch (std::exception &e) {
    std::cerr << "exeption: " << e.what() << "\n";
  }

  return 0;
}