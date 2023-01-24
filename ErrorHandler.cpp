#include "ErrorHandler.h"

void ErrorHandler::throwError(int errorCode)
{
    switch(errorCode)
    {
        case 401:
            std::cout<<"ERROR "<<errorCode<<": Invalid number of parameters."<<std::endl;
            break;

        case 402:
            std::cout<<"ERROR "<<errorCode<<": No log file mentioned. Please run urlogv -help for usage instructions."<<std::endl;
            break;

        case 403:
            std::cout<<"ERROR "<<errorCode<<": Invalid number of arguments passed. Please run urlogv -help for usage instructions."<<std::endl;
            break;

        case 405:
            std::cout<<"ERROR "<<errorCode<<": Invalid option. Please run urlogv -help for usage instructions."<<std::endl;
            break;

        case 504:
            std::cout<<"ERROR "<<errorCode<<": Command not found."<<std::endl;
            break;
        
        case 601:
            std::cout<<"ERROR "<<errorCode<<": Line is not flagged."<<std::endl;
            break;
        case 602:
            std::cout<<"ERROR "<<errorCode<<": Line already flagged."<<std::endl;
            break;
        case 603:
            std::cout<<"ERROR "<<errorCode<<": Invalid Line Number."<<std::endl;
            break;
    }
}