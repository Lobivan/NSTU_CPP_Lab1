#pragma once

#include "MyString.hpp"

class MyTaskString : public MyString {
 private:
  // Правильность ввода начала и конца работы не проверяется
  int start_h;   // Начало работы (час)
  int end_h;     // Конец работы (час)
  bool is_done;  // Признак выполнения

 public:
  // Конструкторы нового класса
  MyTaskString()  // Конструктор по умолчанию
      : MyString(), start_h(-1), end_h(-1), is_done(false) {}

  MyTaskString(size_t size)  // Конструктор с параметром размера
      : MyString(size), start_h(-1), end_h(-1), is_done(false) {}

  MyTaskString(char *arr)  // Конструктор с параметром массива символов
      : MyString(arr), start_h(-1), end_h(-1), is_done(false) {}

  MyTaskString(const MyString &other)  // Конструктор копирования
      : MyString(other), start_h(-1), end_h(-1), is_done(false) {}

  MyTaskString(char *arr, int start, int end,
               bool done)  // Конструктор с параметрами
      : MyString(arr), start_h(start), end_h(end), is_done(done) {}

  MyTaskString(const MyString &other, int start, int end,
               bool done)  // Конструктор копирования
      : MyString(other), start_h(start), end_h(end), is_done(done) {}

  MyTaskString(const MyTaskString &other)  // Конструктор копирования
      : MyString(other),
        start_h(other.start_h),
        end_h(other.end_h),
        is_done(other.is_done) {}

  // Новые методы
  int getStartHour() { return start_h; }
  int getEndHour() { return end_h; }
  bool isDone() { return is_done; }
  void setStartHour(int hour) { start_h = hour; }
  void setEndHour(int hour) { end_h = hour; }
  void setCompletion(bool isdone) { is_done = isdone; }

  // Переопределение методов
  // Метод вывода строки на экран
  void print() const {
    std::cout << start_h << " " << end_h << " " << is_done << " ";
    for (int i = 0; i < size(); i++) {
      std::cout << (this->to_char())[i];
    };
  }

  // Метод печати всей информации о строке
  void print_info() const {
    std::cout << "размер строки: " << size() << "\n";
    std::cout << "максимальный размер строки: " << max_size() << "\n";
    std::cout << "строка: \'";
    print();
    std::cout << "\'\n";
  }

  MyString &operator=(const MyString &other) {
    MyString::operator=(other);
    start_h = -1;
    end_h = -1;
    is_done = false;
    return *this;
  }

  MyTaskString &operator=(const MyTaskString &other) {
    MyString::operator=(other);
    start_h = other.start_h;
    end_h = other.end_h;
    is_done = other.is_done;
    return *this;
  }

  // Дружественные методы не наследуются, поэтому их необходимо переопределить
  friend MyTaskString operator+(char *arr, MyTaskString const &self) {
    MyTaskString res(self);
    res.append(arr);
    return res;
  }
  friend std::ostream &operator<<(std::ostream &os, MyTaskString &str) {
    os << "start: " << str.start_h << "\n";
    os << "end: " << str.end_h << "\n";
    os << "done: " << str.is_done << "\n";
    os << "task: " << static_cast<MyString &>(str);
    return os;
  }
  friend std::istream &operator>>(std::istream &is, MyTaskString &str) {
    is >> str.start_h;
    is >> str.end_h;
    is >> str.is_done;
    std::cin.clear();
    char c;
    is >> std::noskipws >> c;
    MyString tmp;
    is >> tmp;
    str.erase();
    str.append(tmp);
    return is;
  }
  friend std::ofstream &operator<<(std::ofstream &os, MyTaskString &str) {
    os << "start: " << str.start_h << "\n";
    os << "end: " << str.end_h << "\n";
    os << "done: " << str.is_done << "\n";
    os << "task: " << static_cast<MyString &>(str);
    return os;
  }
  friend std::ifstream &operator>>(std::ifstream &is, MyTaskString &str) {
    is >> str.start_h;
    is >> str.end_h;
    is >> str.is_done;
    MyString tmp;
    is >> tmp;
    str.erase();
    str.append(tmp);
    return is;
  }
};