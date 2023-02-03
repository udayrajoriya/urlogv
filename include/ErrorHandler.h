#pragma once
#include <iostream>

class ErrorHandler
{
    public:
    void throwError(int);
    void printError(int, std::string);
};