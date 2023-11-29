/*Программа перезаписывает себя же в файл txt*/

#include <iostream>
#include <fstream>


int checkFile(std::ifstream &file){
    if (!file.is_open()) throw "File unopened";
    if (!file) throw "File not founded";
    if (file.eof()) throw "File is epmty";
    return 0;
}

int copyFiles(std::ifstream &file, std::ofstream &newFile){
    checkFile(file);
    std::string text, line;
    while(!file.eof()){
        std::getline(file ,line);
        text += line + '\n';
    }
    newFile << text;
    return 0;
}


int main(){
    try{
    std::ifstream file ("/home/nikita/Desktop/FolderByWorcsk/WorkWithFies.cpp");
    std::ofstream newFile("WorckWithFiles.txt");
    copyFiles(file, newFile);
    }catch(const char* error){
        std::cout << error;
    } 
    return 0;
}
