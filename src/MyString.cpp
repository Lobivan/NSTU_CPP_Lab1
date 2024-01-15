#include "MyString.hpp"

#include <algorithm>
#include <cstring>

MyString::MyString()  // Конструктор по умолчанию
    : data(nullptr), curSize(0), maxSize(0) {}

MyString::MyString(size_t size)  // Конструктор с параметром размера
    : curSize(size), maxSize(size) {
  data = new char[maxSize]();
}

MyString::MyString(char *arr) {  // Конструктор с параметром массива символов
  size_t size = strlen(arr);
  maxSize = size;
  curSize = size;
  data = new char[maxSize]();
  for (int i = 0; i < maxSize; i++) {
    data[i] = arr[i];
  }
}

MyString::MyString(const MyString &other)  // Конструктор копирования
    : curSize(other.curSize), maxSize(other.maxSize) {
  data = new char[maxSize]();
  for (int i = 0; i < maxSize; i++) {
    data[i] = other.data[i];
  }
}

MyString::~MyString() {  // Деструктор
  delete[] data;
  curSize = 0;
  maxSize = 0;
  data = nullptr;
}

// Метод, возвращающий текущий размер строки
size_t MyString::size() const { return curSize; }

// Метод, возвращающий максимальный размер строки
size_t MyString::max_size() const { return maxSize; }

// Метод для изменения максисального размера строки
void MyString::resize(size_t n) {
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

// Методы, добавляющий массив символов в конец строки
MyString &MyString::append(char *arr) {
  size_t arrlen = strlen(arr);
  while (size() + arrlen > max_size()) {
    if (max_size() == 0) maxSize = 1;
    resize(max_size() * 2);
  }
  for (int i = 0; i < arrlen; i++) {
    data[size() + i] = arr[i];
  }
  curSize += arrlen;
  return *this;
}

MyString &MyString::append(const MyString &str) {
  char *tmp = str.to_char();
  append(tmp);
  delete[] tmp;
  return *this;
}

// Методы поиска подстроки в строке (начиная с позиции pos)
size_t MyString::find(const MyString &str, size_t pos) const {
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

size_t MyString::find(const MyString &str) const { return find(str, 0); }

size_t MyString::find(char *str, size_t pos) const {
  return find(MyString(str), pos);
}

size_t MyString::find(char *str) const { return find(str, 0); }

// Методы вставки подстроки в строку перед позицией pos
MyString &MyString::insert(size_t pos, const MyString &str) {
  while (size() + str.size() > max_size()) {
    resize(max_size() * 2);
  }
  char *tmp = to_char();
  for (int i = 0; i < str.size(); i++) {
    data[i + pos] = str.data[i];
  }
  curSize = size() + str.size();
  for (int i = pos + str.size(); i < size(); i++) {
    data[i] = tmp[i - str.size()];
  }

  delete[] tmp;
  return *this;
}

MyString &MyString::insert(size_t pos, char *str) {
  return insert(pos, MyString(str));
}

// Метод очистки строки
MyString &MyString::erase() {
  curSize = 0;
  return *this;
}

// Метод превращения строки в массив символов
char *MyString::to_char() const {
  char *res = new char[size() + 1]();
  for (int i = 0; i < size(); i++) {
    res[i] = data[i];
  }
  res[size()] = '\0';
  return res;
}

// Метод вывода строки на экран
void MyString::print() const {
  for (int i = 0; i < curSize; i++) {
    std::cout << data[i];
  };
}

// Метод печати всей информации о строке
void MyString::print_info() const {
  std::cout << "размер строки: " << size() << "\n";
  std::cout << "максимальный размер строки: " << max_size() << "\n";
  std::cout << "строка: \'";
  print();
  std::cout << "\'\n";
}
