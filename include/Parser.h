#pragma once
#include "ErrorHandler.h"
#include "LogFile.h"
#include <iostream>
#include <vector>

class Parser
{
    private:
        ErrorHandler errorHandlerObject;
    public:
        void parseCommand(std::string, LogFile&, bool&);
        std::vector<std::string> tokenizer(std::string userCommand);
};