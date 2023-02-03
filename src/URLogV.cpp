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
                        std::cout<<"Usage: urlogv <path of file>"<<std::endl;
                        std::cout<<"Commands:"<<std::endl;
                        std::cout<<"  f <line number>"<<"              To flag a line. Example: f 256"<<std::endl;
                        std::cout<<"  q"<<"                            To exit the program. Example: q"<<std::endl;
                        std::cout<<"  rf <line number>"<<"             To remove flag of a line. Example: rf 115"<<std::endl;
                        std::cout<<"  s <text or string to search>"<<" To search for some text or string. Example: s Generating report"<<std::endl;
                        std::cout<<"  sc"<<"                           To clear a search. Example: sc"<<std::endl;
                        std::cout<<"  va"<<"                           To view all lines from file. Example: va"<<std::endl;
                        std::cout<<"  vr <from line> <to line>"<<"     To view lines having line number in range. Example: vr 215 232"<<std::endl;
                        std::cout<<std::endl;
                        std::cout<<"URLogV: developed by Uday Rajoriya."<<std::endl;
                        std::cout<<"Report any issues or bugs to hello@udayrajoriya.com."<<std::endl;
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