#include <fstream>
#include <iostream>

#include "MyBinaryString.hpp"
#include "MyString.hpp"
#include "MyTaskString.hpp"

int main(void) {
  std::cout << "\n   Строка - число в двоичной системе счисления: \n";
  std::cout << "\n Демонстрация работы конструкторов: \n";
  MyBinaryString str;
  str.print_info();
  char arr[] = "100101";
  MyBinaryString str1(arr);
  str1.print_info();
  MyBinaryString str2(str1);
  str2.print_info();

  std::cout << "\n Демонстрация работы нового метода: \n";
  std::cout << str1.to_int() << "\n";

  std::cout << "\n Демонстрация работы некоторых старых методов: \n";
  str.resize(2);
  str.print_info();
  std::cout << str.size() << " " << str.max_size() << "\n";

  std::cout << "\n Демонстрация работы некоторых переопределённых методов: \n";
  str.append(arr);
  str.print_info();
  str.insert(3, arr);
  str.print_info();

  std::cout << "\n Демонстрация работы некоторых переопределённых "
               "дружественных методов: \n";
  str = arr + str1;
  std::cout << str << "\n";

  std::cout << "\n   Строка - запись в списке запланированных дел: \n";
  std::cout << "\n Демонстрация работы конструкторов: \n";
  MyTaskString tstr;
  tstr.print_info();
  char tarr[] = "Уборка";
  MyTaskString tstr1(tarr, 10, 12, false);
  tstr1.print_info();
  MyTaskString tstr2(str1);
  tstr2.print_info();

  std::cout << "\n Демонстрация работы новых метода: \n";
  tstr1.setStartHour(9);
  tstr1.setEndHour(11);
  tstr1.setCompletion(true);
  std::cout << tstr1.getStartHour() << " " << tstr1.getEndHour() << " "
            << tstr1.isDone() << "\n";

  std::cout << "\n Демонстрация работы некоторых старых методов: \n";
  tstr.resize(2);
  tstr.print_info();
  std::cout << tstr.size() << " " << tstr.max_size() << "\n";

  std::cout << "\n Демонстрация работы некоторых переопределённых "
               "дружественных методов: \n";
  tstr = tarr + tstr1;
  std::cout << tstr << "\n";

  return 0;
}