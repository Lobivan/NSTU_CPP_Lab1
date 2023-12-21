#pragma once

#include <cstring>

#include "MyString.hpp"

class MyBinaryString : public MyString {
 protected:
  // Методы для проверки введённой строки и её очистки в случае ошибки
  int is_char_arr_valid(char *arr) const {
    int res = 1;
    for (int i = 0; i < strlen(arr); i++) {
      if (arr[i] != '1' && arr[i] != '0') {
        res = 0;
        break;
      }
    }
    return res;
  }
  int is_valid() {
    int res = 1;
    for (int i = 0; i < size(); i++) {
      if (operator[](i) != '1' && operator[](i) != '0') {
        res = 0;
        break;
      }
    }
    return res;
  }
  void destroy_if_invalid() {
    if (is_valid() == 0) {
      erase();
      std::cout << "Ошибка: Строка должна содержать только символы 0 или 1\n";
    }
  }

 public:
  // Конструкторы нового класса
  MyBinaryString()  // Конструктор по умолчанию
      : MyString() {}

  MyBinaryString(size_t size)  // Конструктор с параметром размера
      : MyString(size) {}

  MyBinaryString(char *arr)  // Конструктор с параметром массива символов
      : MyString(arr) {
    destroy_if_invalid();
  }

  MyBinaryString(const MyString &other)  // Конструктор копирования
      : MyString(other) {
    destroy_if_invalid();
  }

  // Новый метод
  int to_int() {
    int res = 0;
    int pow_2 = 1;
    for (int i = size() - 1; i >= 0; i--) {
      res += (operator[](i) - '0') * pow_2;
      pow_2 *= 2;
    }
    return res;
  }

  // Переопределение методов, как-либо изменяющих строку (добавление проверки
  // корректности новой строки)
  MyString &append(char *arr) {
    if (is_char_arr_valid(arr)) {
      MyString::append(arr);
    } else {
      std::cout << "Ошибка: Строка должна содержать только символы 0 или 1\n";
    }
    return *this;
  }

  MyString &insert(size_t pos, const MyString &str) {
    if (is_char_arr_valid(str.to_char())) {
      MyString::insert(pos, str);
    } else {
      std::cout << "Ошибка: Строка должна содержать только символы 0 или 1\n";
    }
    return *this;
  }

  MyString &operator=(const MyString &other) {
    if (is_char_arr_valid(other.to_char())) {
      MyString::operator=(other);
    } else {
      std::cout << "Ошибка: Строка должна содержать только символы 0 или 1\n";
    }
    return *this;
  }

  void readBinary(std::ifstream &is) {
    MyString tmp;
    tmp.readBinary(is);
    if (is_char_arr_valid(tmp.to_char())) {
      *this = tmp;
    } else {
      std::cout << "Ошибка: Строка должна содержать только символы 0 или 1\n";
    }
  }

  // Дружественные методы не наследуются, поэтому их необходимо переопределить
  friend MyBinaryString operator+(char *arr, MyBinaryString const &self) {
    MyBinaryString res(self);
    res.append(arr);
    return res;
  }
  friend std::ostream &operator<<(std::ostream &os, MyBinaryString &str) {
    os << static_cast<MyString &>(str);
    return os;
  }
  friend std::istream &operator>>(std::istream &is, MyBinaryString &str) {
    MyString tmp;
    is >> tmp;
    if (str.is_char_arr_valid(tmp.to_char())) {
      str = tmp;
    } else {
      std::cout << "Ошибка: Строка должна содержать только символы 0 или 1\n";
    }
    return is;
  }
  friend std::ofstream &operator<<(std::ofstream &os, MyBinaryString &str) {
    os << static_cast<MyString &>(str);
    return os;
  }
  friend std::ifstream &operator>>(std::ifstream &is, MyBinaryString &str) {
    MyString tmp;
    is >> tmp;
    if (str.is_char_arr_valid(tmp.to_char())) {
      str = tmp;
    } else {
      std::cout << "Ошибка: Строка должна содержать только символы 0 или 1\n";
    }
    return is;
  }
};