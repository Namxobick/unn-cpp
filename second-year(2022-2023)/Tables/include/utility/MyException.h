//
// Created by Андрей Юрин on 15.05.2023.
//

#ifndef TABLES_MYEXCEPTION_H
#define TABLES_MYEXCEPTION_H

#include <exception>


class MyException : public std::exception{
protected:
    const char *errorMsg;

public:
    explicit MyException (const char* str);
    [[nodiscard]] const char * what () const noexcept override;
};


#endif //TABLES_MYEXCEPTION_H
