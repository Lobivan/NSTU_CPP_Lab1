#pragma once

#include <cstring>
#include <exception>

#include "MyString.hpp"

class MyBinaryString : public MyString {
 protected:
  // Методы для проверки введённой строки и её очистки в случае ошибки
  bool is_char_arr_valid(char *arr) const {
    int res = true;
    for (int i = 0; i < strlen(arr); i++) {
      if (arr[i] != '1' && arr[i] != '0') {
        res = false;
        break;
      }
    }
    return res;
  }
  bool is_valid() const {
    int res = true;
    for (int i = 0; i < size(); i++) {
      if (operator[](i) != '1' && operator[](i) != '0') {
        res = false;
        break;
      }
    }
    return res;
  }
  void invalid_arg_exeption() {
    throw std::invalid_argument(
        "Строка должна содержать только символы 0 или 1");
  }
  void exeption_if_invalid() {
    if (is_valid() == false) {
      invalid_arg_exeption();
    }
  }
  void exeption_if_invalid(const MyString &other) {
    char *tmp = other.to_char();
    if (is_char_arr_valid(tmp) == false) {
      delete[] tmp;
      invalid_arg_exeption();
    }
    delete[] tmp;
  }

 public:
  // Конструкторы нового класса
  MyBinaryString()  // Конструктор по умолчанию
      : MyString() {}

  MyBinaryString(size_t size)  // Конструктор с параметром размера
      : MyString(size) {}

  MyBinaryString(char *arr)  // Конструктор с параметром массива символов
      : MyString(arr) {
    exeption_if_invalid();
  }

  MyBinaryString(const MyString &other)  // Конструктор копирования
      : MyString(other) {
    exeption_if_invalid();
  }

  // Новый метод
  int to_int() const {
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

  virtual void print() const {
    for (int i = 0; i < size(); i++) {
      std::cout << (this->to_char())[i];
    };
    std::cout << " = " << to_int();
  }

  MyString &append(char *arr) {
    if (is_char_arr_valid(arr)) {
      MyString::append(arr);
    } else {
      invalid_arg_exeption();
    }
    return *this;
  }

  MyString &insert(size_t pos, const MyString &str) {
    exeption_if_invalid(str);
    MyString::insert(pos, str);
    return *this;
  }

  MyString &operator=(const MyString &other) {
    exeption_if_invalid(other);
    MyString::operator=(other);
    return *this;
  }

  void readBinary(std::ifstream &is) {
    MyString tmp;
    tmp.readBinary(is);
    exeption_if_invalid(tmp);
    *this = tmp;
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
    str.exeption_if_invalid(tmp);
    str = tmp;
    return is;
  }
  friend std::ofstream &operator<<(std::ofstream &os, MyBinaryString &str) {
    os << static_cast<MyString &>(str);
    return os;
  }
  friend std::ifstream &operator>>(std::ifstream &is, MyBinaryString &str) {
    MyString tmp;
    is >> tmp;
    str.exeption_if_invalid(tmp);
    str = tmp;
    return is;
  }
};