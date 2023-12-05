/*
Словом, входящим в состав строки, назовём непрерывную
последовательность символов, ограниченную символами–разделителями,
началом и концом строки. Символы, относящиеся к разделителям, определяет
пользователь, если иное не сказано в условии задачи. Если решить задачу
невозможно, программа должна выдать соответствующее сообщение.

Строка состоит из слов, разделённых знаками препинания. За один
просмотр символов строки найти все слова, представляющие собой числа
Армстронга и занести их в новую строку. Слова в новой строке должны
разделяться ровно одним пробелом.
*/

#include <iostream>
#include <string>
#include <exception>
#include "seekNumbersInLine.hpp"


int main() {
 try {
  std::string line;
  getText(line, "line");
  std::string delimiters;
  getText(delimiters, "delimiters");
  std::string ArmstrongNumbers; // since the first word is the name, that this name is a camelCase
  findArmstrongsWords(line, delimiters, ArmstrongNumbers);
  std::cout << "Armstrong numbers:" << ArmstrongNumbers;
 }catch(std::exception &err) {
  std::cout << err.what() << std::endl;
 }
 return 0;
}