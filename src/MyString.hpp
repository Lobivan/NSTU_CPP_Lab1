// MyString.hpp
#pragma once

#include <fstream>
#include <iostream>

class MyString {
 private:
  char *data;      // динамический массив сроки
  size_t curSize;  // текущая длина строки
  size_t maxSize;  // максимальная длина массива строки

 public:
  MyString();             // Конструктор по умолчанию
  MyString(size_t size);  // Конструктор с параметром размера
  MyString(char *arr);  // Конструктор с параметром массива символов
  MyString(const MyString &other);  // Конструктор копирования
  ~MyString();                      // Деструктор

  // Метод, возвращающий текущий размер строки
  size_t size() const;

  // Метод, возвращающий максимальный размер строки
  size_t max_size() const;

  // Метод для изменения максисального размера строки
  void resize(size_t n);

  // Методы, добавляющий массив символов в конец строки
  MyString &append(char *arr);
  MyString &append(const MyString &str);

  // Методы поиска подстроки в строке (начиная с позиции pos)
  size_t find(const MyString &str, size_t pos) const;
  size_t find(const MyString &str) const;
  size_t find(char *str, size_t pos) const;
  size_t find(char *str) const;

  // Методы вставки подстроки в строку перед позицией pos
  MyString &insert(size_t pos, const MyString &str);
  MyString &insert(size_t pos, char *str);

  // Метод очистки строки
  MyString &erase();

  // Метод превращения строки в массив символов
  char *to_char() const;

  // Метод вывода строки на экран
  virtual void print() const;

  // Метод печати всей информации о строке
  void print_info() const;

  // сложение со строкой типа char*
  MyString operator+(char *arr) const;
  // используется дружественная функция для сложения со строкой типа char*,
  // когда эта строка является левым операндом
  friend MyString operator+(char *arr, MyString const &self);

  // сложение 2-х объектов класса
  MyString operator+(const MyString &str) const;

  // операция вычитания как удаление подстроки
  MyString operator-(const MyString &str) const;

  // операция индексирования
  char &operator[](size_t pos);
  char operator[](size_t pos) const;

  // операция присваивания
  MyString &operator=(const MyString &other);

  // операция сравнения
  bool operator==(const MyString &other) const;
  bool operator<(const MyString &other) const;

  // операция вывода в поток
  friend std::ostream &operator<<(std::ostream &os, MyString &str);

  // операция ввода из поток
  friend std::istream &operator>>(std::istream &is, MyString &str);

  // операция вывода в файловый поток
  friend std::ofstream &operator<<(std::ofstream &os, MyString &str);

  // операция ввода из файлового потока
  friend std::ifstream &operator>>(std::ifstream &is, MyString &str);

  // операция вывода в файловый поток(в двоичном виде)
  void writeBinary(std::ofstream &os);

  // операция ввода из файлового потока(в двоичном виде)
  void readBinary(std::ifstream &is);
};