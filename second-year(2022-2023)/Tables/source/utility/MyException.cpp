//
// Created by Андрей Юрин on 15.05.2023.
//

#include "../../include/utility/MyException.h"

MyException::MyException(const char *str) {
    errorMsg =  str;
}

const char *MyException::what() const throw() {
    return errorMsg;
}
