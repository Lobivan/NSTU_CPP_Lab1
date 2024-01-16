#include "MyString.hpp"

// сложение со строкой типа char*
MyString MyString::operator+(char *arr) const {
  MyString res(*this);
  res.append(arr);
  return res;
}
// используется дружественная функция для сложения со строкой типа char*,
// когда эта строка является левым операндом
MyString operator+(char *arr, MyString const &self) {
  MyString res(self);
  res.append(arr);
  return res;
}

// сложение 2-х объектов класса
MyString MyString::operator+(const MyString &str) const {
  MyString res(*this);
  res.append(str);
  return res;
}

// операция вычитания как удаление подстроки
MyString MyString::operator-(const MyString &str) const {
  MyString res(*this);
  size_t pos = res.find(str);
  if (pos != (size_t)-1) {
    for (int i = pos; i < curSize - str.curSize; i++) {
      res.data[i] = res.data[i + str.curSize];
    }
    res.curSize -= str.curSize;
  }
  return res;
}

// операция индексирования
char &MyString::operator[](size_t pos) { return data[pos]; }
char MyString::operator[](size_t pos) const { return data[pos]; }

// операция присваивания
MyString &MyString::operator=(const MyString &other) {
  if (this != &other) {
    this->resize(other.maxSize);
    for (int i = 0; i < other.curSize; i++) {
      data[i] = other.data[i];
    }
    curSize = other.curSize;
  }
  return *this;
}

// операция сравнения
bool MyString::operator==(const MyString &other) const {
  bool res = true;
  if (this != &other) {
    if (size() != other.size()) {
      res = false;
    } else {
      for (int i = 0; i < size(); i++) {
        if (data[i] != other.data[i]) {
          res = false;
          break;
        }
      }
    }
  }
  return res;
}
bool MyString::operator<(const MyString &other) const {
  bool res = false;
  if (this != &other) {
    if (size() != other.size()) {
      res = (size() < other.size());
    } else {
      for (int i = 0; i < size(); i++) {
        if (data[i] < other.data[i]) {
          res = true;
          break;
        }
        if (data[i] > other.data[i]) {
          break;
        }
      }
    }
  }
  return res;
}