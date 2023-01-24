#include <iostream>
#include <vector>
#include "ErrorHandler.h"
#include "LogFile.h"
#include "Parser.h"


bool shouldRun = true;

ErrorHandler errorHandlerObject;

LogFile logFileObject;

Parser parserObject;

int main()
{
    std::string userCommand;
    logFileObject.unloadFile();
    logFileObject.displayFile();
    logFileObject.setTotalLines(logFileObject.getTotalLines());
    while(shouldRun)
    {
        std::cout<<":";
        getline(std::cin, userCommand);
        parserObject.parseCommand(userCommand, logFileObject, shouldRun);
    }
    return 0;
}