
#ifndef PG400_EKSAMEN_MYEXCEPTION_H
#define PG400_EKSAMEN_MYEXCEPTION_H
#include "MyException.h"
#include <exception>
#include <string>

class MyException : public std::exception{
    public:
    MyException(const std::string & msg);
    [[nodiscard]] const char* what() const noexcept override;

    ~MyException() noexcept override = default;
private:
   std::string m_exceptionMsg;

};


#endif //PG400_EKSAMEN_MYEXCEPTION_H
