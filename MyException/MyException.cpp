
#include "MyException.h"

MyException::MyException(const std::string &msg) {
    m_exceptionMsg = msg;
}

const char *MyException::what() const noexcept {
    return m_exceptionMsg.c_str();
}
