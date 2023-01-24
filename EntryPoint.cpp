#include <iostream>
#include <vector>
#include "ErrorHandler.h"
#include "LogFile.h"

void parseCommand(std::string);
std::vector<std::string> tokenizer(std::string);



bool shouldRun = true;

ErrorHandler errorHandlerObject;

LogFile logFileObject;


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
        parseCommand(userCommand);
    }
    return 0;
}

void parseCommand(std::string userCommand)
{
    std::vector<std::string> tokens = tokenizer(userCommand);
    int commandLength = tokens.size();
    if(tokens[0] == "f")
    {
        if(commandLength == 2)
        {
            long long int lineNumber = 0;
            try
            {
                lineNumber = stoi(tokens[1]);
                if(lineNumber == 0)
                    throw 505;
            }
            catch(...)
            {
                errorHandlerObject.throwError(603);
                return;
            }
            
            if(lineNumber > 0 && lineNumber <= logFileObject.getTotalLines())
            {
                int lineFlagged = logFileObject.flagLine(lineNumber);
                if(!lineFlagged)
                {
                    errorHandlerObject.throwError(602);
                    return;
                }
            }
            else
            {
                errorHandlerObject.throwError(603);
                return;
            }
        }
        else
        {
            errorHandlerObject.throwError(401);
            return;
        }
        return;
    }
    if(tokens[0] == "rf")
    {
        if(commandLength == 2)
        {
            long long int lineNumber;
            try
            {
                lineNumber = stoi(tokens[1]);
                if(lineNumber == 0)
                    throw 505;
            }
            catch(...)
            {
                errorHandlerObject.throwError(603);
                return;
            }

            if(lineNumber > 0 && lineNumber <= logFileObject.getTotalLines())
            {
                int lineUnFlagged = logFileObject.unFlagLine(lineNumber);
                if(!lineUnFlagged)
                {
                    errorHandlerObject.throwError(601);
                    return;
                }
            }
            else
            {
                errorHandlerObject.throwError(603);
                return;
            }
        }
        else
        {
            errorHandlerObject.throwError(401);
            return;
        }
        return;
    }
    if(tokens[0] == "q")
    {
        if(commandLength == 1)
        {
            shouldRun = false;
        }
        else
        {
            errorHandlerObject.throwError(401);
            return;
        }
        return;
    }
    if(tokens[0] == "s")
    {
        logFileObject.setSearchString("");
        std::string tempString = "";
        if(commandLength > 1)
        {
            // for(int i = 1 ; i < tokens.size(); i++)
            // {
            //     tempString += tokens[i] + " ";
            // }
            tempString += tokens[1];
            logFileObject.setSearchString(tempString);
            logFileObject.displayFile();
            return;
        }
        else
        {
            errorHandlerObject.throwError(401);
            return;
        }
    }
    errorHandlerObject.throwError(504);
}

void totalLinesCalculator()
{
    // while (std::getline (logFile, logLine))
    // {
    //     totalLines++;
    // }
}

std::vector<std::string> tokenizer(std::string userCommand)
{
    std::string temp = "";
    std::vector<std::string> tokens;
    for(int i = 0; i < userCommand.length(); i++)
    {
        if(userCommand[i] == ' ')
        {
            if(temp != "")
                tokens.push_back(temp);
            temp = "";
        }
        else
        {
            temp += userCommand[i];
        }
    }
    if(temp != "")
        tokens.push_back(temp);

    return tokens;
}

