#include <fstream>

#include "MyString.hpp"

std::ostream &operator<<(std::ostream &os, MyString &str) {
  for (int i = 0; i < str.size(); i++) {
    os << str.data[i];
  }
  return os;
}

std::istream &operator>>(std::istream &is, MyString &str) {
  if (str.max_size() == 0) {
    str.resize(1);
  }
  size_t i = 0;
  char c;
  is >> std::noskipws >> c;
  while (c != '\n') {
    if (i == str.max_size()) {
      str.resize(str.max_size() * 2);
    }
    str.data[i] = c;
    str.curSize++;
    i++;
    is >> std::noskipws >> c;
  }
  return is;
}

// операция вывода в файловый поток
std::ofstream &operator<<(std::ofstream &os, MyString &str) {
  for (int i = 0; i < str.size(); i++) {
    os << str.data[i];
  }
  return os;
}

// операция ввода из файлового потока
std::ifstream &operator>>(std::ifstream &is, MyString &str) {
  if (str.max_size() == 0) {
    str.resize(1);
  }
  str.curSize = 0;
  while (!is.eof()) {
    if (str.curSize == str.max_size()) {
      str.resize(str.max_size() * 2);
    }
    is >> std::noskipws >> str.data[str.curSize++];
  }
  str.curSize--;
  return is;
}

// операция вывода в файловый поток(в двоичном виде)
void MyString::writeBinary(std::ofstream &os) {
  os.write(data, sizeof(char) * curSize);
}

// операция ввода из файлового потока(в двоичном виде)
void MyString::readBinary(std::ifstream &is) {
  is.seekg(0, is.end);
  int length = is.tellg();
  is.seekg(0, is.beg);

  resize(length);
  is.read(data, length);
  curSize = length;
}