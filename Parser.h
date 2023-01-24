#pragma once
#include "ErrorHandler.h"

class Parser
{
    private:
        ErrorHandler errorHandlerObject;
    public:
        void parseCommand(std::string userCommand);
        std::vector<std::string> tokenizer(std::string userCommand);
};