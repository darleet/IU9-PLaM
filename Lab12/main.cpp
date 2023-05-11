#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <dirent.h>

// Функция для удаления HTML-тегов и замены &lt и &gt
std::string removeHtmlTags(const std::string& input) {
    std::string output;
    bool tagOpen = false;
    size_t pos = 0;
    while (pos < input.length()) {
        if (input[pos] == '<') {
            tagOpen = true;
            pos++;
        } else if (input[pos] == '>') {
            tagOpen = false;
            pos++;
        } else if (!tagOpen) {
            if (input[pos] == '&') {
                if (input.substr(pos, 4) == "&lt;") {
                    output += '<';
                    pos += 4;
                } else if (input.substr(pos, 4) == "&gt;") {
                    output += '>';
                    pos += 4;
                } else {
                    output += input[pos];
                    pos++;
                }
            } else {
                output += input[pos];
                pos++;
            }
        } else {
            pos++;
        }
    }

    return output;
}

int main() {
    std::string directoryPath = "/home/darleet/BMSTU/IU9-CPP/Lab12/Examples";

    DIR* directory = opendir(directoryPath.c_str());
    if (directory == nullptr) {
        std::cerr << "Failed to open directory: " << directoryPath << std::endl;
        return 1;
    }

    dirent* entry;
    while ((entry = readdir(directory)) != nullptr) {
        std::string filename = entry->d_name;
        std::string filePath = directoryPath;
        filePath += "/";
        filePath += filename;

        // Проверка, что это файл с расширением .html
        if (filename.size() > 5 && filename.substr(filename.size() - 5) == ".html") {
            std::ifstream inputFile(filePath);
            if (inputFile.is_open()) {
                // Чтение содержимого файла в строку
                std::stringstream buffer;
                buffer << inputFile.rdbuf();
                std::string fileContent = buffer.str();

                // Удаление HTML-тегов и замена символов
                std::string cleanedContent = removeHtmlTags(fileContent);

                // Замена расширения файла на .txt
                std::string outputFilePath = directoryPath + "/"
                        + filename.substr(0, filename.size() - 5) + ".txt";

                // Сохранение очищенного текста в файл
                std::ofstream outputFile(outputFilePath);
                if (outputFile.is_open()) {
                    outputFile << cleanedContent;
                    outputFile.close();
                    std::cout << "File processed: " << outputFilePath << std::endl;
                } else {
                    std::cerr << "Failed to create output file: " << outputFilePath << std::endl;
                }

                // Закрытие файла после чтения
                inputFile.close();
            } else {
                std::cerr << "Failed to open input file: " << filePath << std::endl;
            }
        }
    }

    closedir(directory);
    return 0;
}