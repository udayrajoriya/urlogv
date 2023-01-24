#include <iostream>
#include "ErrorHandler.cpp"

ErrorHandler errorHandlerObject;
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
                    if(argument == "-help")
                    {
                        std::cout<<"This section is still under implementation."<<std::endl;
                    }
                    else
                    {
                        errorHandlerObject.throwError(405);
                    }
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