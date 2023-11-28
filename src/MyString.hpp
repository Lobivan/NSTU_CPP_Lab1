#pragma once

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
  size_t size() { return curSize; }
  size_t max_size() { return maxSize; }
};