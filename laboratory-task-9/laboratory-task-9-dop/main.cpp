/*4. В текстовом файле input.txt в первой строке записаны два слова,
разделенные пробелами, в остальных строках - текст, слова в котором
разделены знаками препинания. Нужно найти эти слова в тексте и поменять
местами строки, содержащие эти слова. Если таких слов несколько – брать
первые.*/

#include <iostream>
#include "swapLines.hpp"


int main() {
 try {
  const char* path = "input.txt";
  std::pair<std::string, std::string> searchWords = getSearchWordsFromFile(path);
  std::vector<std::string> mainText = getMainTextFromFile(path);
  swapLinesInText(mainText, searchWords);
  writingTextInFile(mainText, searchWords, path);
 }
 catch (std::exception& err) {
  std::cerr << err.what() << std::endl;
 }
 return 0;
}