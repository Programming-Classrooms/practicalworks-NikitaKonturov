/*Программа перезаписывает себя же в файл txt*/

#include <iostream>
#include <fstream>
#include <exception>


void checkFile(std::ifstream &file){
    if (!file) throw "File not founded";
    if (!file.is_open()) throw "File unopened";
    if (file.eof()) throw "File is epmty";
}


void copyFiles(std::ifstream &file, std::ofstream &newFile){
    checkFile(file);
    std::string text, line;
    while(!file.eof()){
        std::getline(file ,line);
        text += line + '\n';
    }
    newFile << text;
}


int main(){
    try{
    const std::string path = "/home/nikita/Desktop/FolderByWorcsk/WorkWithFies.cpp";
    std::ifstream file (path);
    std::ofstream newFile("WorkWithFiles.txt");
    copyFiles(file, newFile);
    }catch(std::exception &err){
        std::cerr << "Exeption: "<< err.what() << std::endl;
    } 
    return 0;
}
