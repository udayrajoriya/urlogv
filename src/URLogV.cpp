#include "../include/ErrorHandler.h"
#include "../include/LogFile.h"
#include "../include/Parser.h"

void startProcess(char* filePath);

bool shouldRun = true;

ErrorHandler errorHandlerObject;

LogFile logFileObject;

Parser parserObject;

int main(int argc, char** argv)
{
    if(argc > 1)
    {
        std::string argument = argv[1];
        switch(argc)
        {
            case 2:
                if(argument[0] == '-')
                {
                    if(argument == "-h")
                    {
                        std::cout<<"This section is still under implementation."<<std::endl;
                    }
                    else
                    {
                        errorHandlerObject.throwError(405);
                    }
                }
                else
                {
                    startProcess(argv[1]);
                }
                break;

            default:
                errorHandlerObject.throwError(403);
                break;
        }
    }
    else
    {
        errorHandlerObject.throwError(402);
    }
    return 0;
}

void startProcess(char* filePath)
{
    std::string userCommand;
    logFileObject.unloadFile(filePath);
    logFileObject.displayFile();
    logFileObject.setTotalLines(logFileObject.getTotalLines());
    while(shouldRun)
    {
        std::cout<<":";
        getline(std::cin, userCommand);
        parserObject.parseCommand(userCommand, logFileObject, shouldRun);
    }
}