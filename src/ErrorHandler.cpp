#include "../include/ErrorHandler.h"

void ErrorHandler::throwError(int errorCode)
{
    switch(errorCode)
    {
        case 401:
            printError(errorCode, "Invalid number of parameters.");
            break;

        case 402:
            printError(errorCode, ": Filename missing. Please use \"urlogv -h\" to get usage instructions.");
            break;

        case 403:
            printError(errorCode, "Invalid number of arguments passed. Please run urlogv -h for usage instructions.");
            break;

        case 405:
            printError(errorCode, "Invalid option. Please run urlogv -h for usage instructions.");
            break;

        case 504:
            printError(errorCode, "Command not found.");
            break;
        
        case 601:
            printError(errorCode, "Line is not flagged.");
            break;

        case 602:
            printError(errorCode, "Line already flagged.");
            break;

        case 603:
            printError(errorCode, "Invalid Line Number.");
            break;
            
        case 604:
            printError(errorCode, "Invalid Range of Line Numbers.");
            break;
    }
}

void ErrorHandler::printError(int errorCode, std::string errorMessage)
{
    std::cout<<"ERROR "<<errorCode<<": "<<errorMessage<<std::endl;
}