/*Программа перезаписывает себя же в файл txt*/

#include <iostream>
#include <fstream>
#include <exception>


void checkFile(std::ifstream &file){
    if (!file) throw "File not founded";
    if (!file.is_open()) throw "File unopened";
    if (file.eof()) throw "File is epmty";
    std::string text;
    std::string line;
    while(!file.eof()){
        std::getline(file, line);
        text += line; 
    }
    if (text.size() == 0) throw "File is epmty";
}


void copyFiles(const std::string pathForCopy, const std::string pathToCopy){
    try{
    std::ifstream file (pathForCopy);
    checkFile(file);
    std::ofstream newFile(pathToCopy);
    if (!newFile.is_open()) throw "File WorkWithFiles.txt unopened";
    std::string text, line;
    while(!file.eof()){
        std::getline(file ,line);
        text += line + '\n';
    }
    file.close();
    newFile << text;
    newFile.close();
    }catch(std::exception &err){
        std::cerr << "Exeption: "<< err.what() << std::endl;
    }
}


int main(){
    const std::string pathForCopy = "/home/nikita/Desktop/FolderByWorcsk/WorkWithFies.cpp";
    const std::string pathToCopy = "WorkWithFiles.txt";
    copyFiles(pathForCopy, pathToCopy);
    return 0;
}
