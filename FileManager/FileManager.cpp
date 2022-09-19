
#include "FileManager.h"

void FileManager::readFile(const std::string &filename,
                           std::function<void(const std::string &, int &lineNumber)> &&outPut) {
    static std::fstream file;
    static int lineNumber;
    file.open(filename, std::ios::in);
    if (file.is_open()) {

        std::string line;

        while (std::getline(file, line)) {
            outPut(line, lineNumber); // Builds a ship from each line


        }
        file.close();

    } else {
        throw MyException("Could not find: " + filename);
    }

}

