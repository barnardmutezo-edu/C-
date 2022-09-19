
#ifndef PG400_EKSAMEN_FILEMANAGER_H
#define PG400_EKSAMEN_FILEMANAGER_H

#include <fstream>
#include "../MyException/MyException.h"

class FileManager {
public:
    static void readFile(const std::string &filename,std::function<void(const std::string &, int& lineNumber)> &&outPut);
};


#endif //PG400_EKSAMEN_FILEMANAGER_H
