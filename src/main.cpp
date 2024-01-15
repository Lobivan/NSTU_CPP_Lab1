#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <map>

#include "MyBinaryString.hpp"
#include "MyStack.hpp"
#include "MyString.hpp"
#include "MyTaskString.hpp"

#define N 5000
#define SIGNS 7
#define STEP 50

using namespace std::chrono;

void deque_push(MyString* my_arr) {
  std::deque<int> d;
  auto start = high_resolution_clock::now();
  for (int i = 0; i < N; i++) {
    d.push_back(i);
    d.push_front(i);
  }
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end - start);
  std::cout << "Время добавления int в deque: " << duration.count() << '\n';

  std::deque<MyString> d1;
  auto start1 = high_resolution_clock::now();
  for (int i = 0; i < N; i++) {
    d1.push_back(MyString(my_arr[i]));
    d1.push_front(MyString(my_arr[i]));
  }
  auto end1 = high_resolution_clock::now();
  auto duration1 = duration_cast<microseconds>(end1 - start1);
  std::cout << "Время добавления MyString в deque: " << duration1.count()
            << "\n\n";
}

void deque_pop(MyString* my_arr) {
  std::deque<int> d;
  for (int i = 0; i < N; i++) {
    d.push_back(i);
    d.push_front(i);
  }
  std::deque<MyString> d1;
  for (int i = 0; i < N; i++) {
    d1.push_back(MyString(my_arr[i]));
    d1.push_front(MyString(my_arr[i]));
  }

  auto start = high_resolution_clock::now();
  for (int i = 0; i < N; i++) {
    d.pop_back();
    d.pop_front();
  }
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end - start);
  std::cout << "Время удаления int из deque: " << duration.count() << '\n';

  auto start1 = high_resolution_clock::now();
  for (int i = 0; i < N; i++) {
    d1.pop_back();
    d1.pop_front();
  }
  auto end1 = high_resolution_clock::now();
  auto duration1 = duration_cast<microseconds>(end1 - start1);
  std::cout << "Время удаления MyString из deque: " << duration1.count()
            << "\n\n";
}

void deque_search(MyString* my_arr) {
  std::deque<int> d;
  for (int i = 0; i < N; i++) {
    d.push_back(i);
    d.push_front(i);
  }
  std::deque<MyString> d1;
  for (int i = 0; i < N; i++) {
    d1.push_back(MyString(my_arr[i]));
    d1.push_front(MyString(my_arr[i]));
  }

  auto start = high_resolution_clock::now();
  for (int i = 0; i < N; i += STEP) {
    find(d.begin(), d.end(), i);
  }
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end - start);
  std::cout << "Время поиска int в deque: " << duration.count() << '\n';

  auto start1 = high_resolution_clock::now();
  for (int i = 0; i < N; i += STEP) {
    find(d1.begin(), d1.end(), my_arr[i]);
  }
  auto end1 = high_resolution_clock::now();
  auto duration1 = duration_cast<microseconds>(end1 - start1);
  std::cout << "Время поиска MyString в deque: " << duration1.count() << "\n\n";
}

void deque_sort(MyString* my_arr) {
  std::deque<int> d;
  for (int i = 0; i < N; i++) {
    d.push_back(rand() % N);
    d.push_front(rand() % N);
  }
  std::deque<MyString> d1;
  for (int i = 0; i < N; i++) {
    d1.push_back(MyString(my_arr[i]));
    d1.push_front(MyString(my_arr[i]));
  }

  auto start = high_resolution_clock::now();
  sort(d.begin(), d.end());
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end - start);
  std::cout << "Время сортировки int в deque: " << duration.count() << '\n';

  auto start1 = high_resolution_clock::now();
  sort(d1.begin(), d1.end());
  auto end1 = high_resolution_clock::now();
  auto duration1 = duration_cast<microseconds>(end1 - start1);
  std::cout << "Время сортировки MyString в deque: " << duration1.count()
            << "\n\n";
}

void int_to_char(char* arr, int n) {
  for (int i = SIGNS - 1; i >= 0; i--) {
    arr[i] = '0' + (n % 10);
    n /= 10;
  }
}

int main(void) {
  char* tmp = new char[SIGNS + 1];
  tmp[SIGNS] = '\n';
  MyString* my_arr = new MyString[N];
  for (int i = 0; i < N; i++) {
    int_to_char(tmp, rand() % N);
    my_arr[i].append(tmp);
  }
  deque_push(my_arr);
  deque_pop(my_arr);
  deque_search(my_arr);
  deque_sort(my_arr);
  return 0;
}