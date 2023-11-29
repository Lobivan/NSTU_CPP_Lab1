#pragma once

#include <algorithm>
#include <cstring>
#include <iostream>

class MyString {
 private:
  char *data;      // динамический массив сроки
  size_t curSize;  // текущая длина строки
  size_t maxSize;  // максимальная длина массива строки

 public:
  MyString()  // Конструктор по умолчанию
      : data(nullptr), curSize(0), maxSize(0) {}

  MyString(size_t size)  // Конструктор с параметром размера
      : curSize(size), maxSize(size) {
    data = new char[maxSize]();
  }

  MyString(char *arr) {  // Конструктор с параметром массива символов
    size_t size = strlen(arr);
    maxSize = size;
    curSize = size;
    data = new char[maxSize]();
    for (int i = 0; i < maxSize; i++) {
      data[i] = arr[i];
    }
  }

  MyString(const MyString &other)  // Конструктор копирования
      : curSize(other.curSize), maxSize(other.maxSize) {
    data = new char[maxSize]();
    for (int i = 0; i < maxSize; i++) {
      data[i] = other.data[i];
    }
  }

  ~MyString() {  // Деструктор
    delete[] data;
    curSize = 0;
    maxSize = 0;
    data = nullptr;
  }

  size_t size() const { return curSize; }

  size_t max_size() const { return maxSize; }

  void resize(size_t n) {
    if (n != max_size()) {
      char *new_data = new char[n]();
      curSize = std::min(n, size());
      maxSize = n;
      for (int i = 0; i < curSize; i++) {
        new_data[i] = data[i];
      }
      delete[] data;
      data = new_data;
    }
  }

  MyString &append(char *arr) {
    size_t arrlen = strlen(arr);
    while (size() + arrlen > max_size()) {
      resize(max_size() * 2);
    }
    for (int i = 0; i < arrlen; i++) {
      data[size() + i] = arr[i];
    }
    curSize += arrlen;
    return *this;
  }

  MyString &append(const MyString &str) {
    char *tmp = str.to_char();
    append(tmp);
    delete[] tmp;
    return *this;
  }

  size_t find(const MyString &str, size_t pos) const {
    size_t res = -1;
    if (str.size() == 0) {
      return res;
    }
    for (int i = pos; i <= size() - str.size(); i++) {
      if (data[i] == str.data[0]) {
        int j = 1;
        for (; j < str.size(); j++) {
          if (data[i + j] != str.data[j]) {
            break;
          }
        }
        if (j == str.size()) {
          res = i;
          break;
        }
      }
    }
    return res;
  }

  size_t find(const MyString &str) const { return find(str, 0); }

  size_t find(char *str, size_t pos) const { return find(MyString(str), pos); }

  size_t find(char *str) const { return find(str, 0); }

  MyString &insert(size_t pos, const MyString &str) {
    while (size() + str.size() > max_size()) {
      resize(max_size() * 2);
    }
    char *tmp = to_char();
    for (int i = 0; i < str.size(); i++) {
      data[i + pos] = str.data[i];
    }
    curSize = size() + str.size();
    for (int i = pos + str.size(); i < size(); i++) {
      data[i] = tmp[i - pos];
    }

    delete[] tmp;
    return *this;
  }

  MyString &insert(size_t pos, char *str) { return insert(pos, MyString(str)); }

  char *to_char() const {
    char *res = new char[size() + 1]();
    for (int i = 0; i < size(); i++) {
      res[i] = data[i];
    }
    res[size()] = '\0';
    return res;
  }

  void print() const {
    for (int i = 0; i < curSize; i++) {
      std::cout << data[i];
    };
  }

  void print_info() const {
    std::cout << "размер строки: " << size() << "\n";
    std::cout << "максимальный размер строки: " << max_size() << "\n";
    std::cout << "строка: \'";
    print();
    std::cout << "\'\n";
  }
};