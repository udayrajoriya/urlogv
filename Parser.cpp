#include "Parser.h"

void Parser::parseCommand(std::string userCommand)
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
            
            if(lineNumber > 0 && lineNumber <= totalLines)
            {
                flagsIterator = std::find(flags.begin(), flags.end(), lineNumber);
                if(flagsIterator == flags.end())
                {
                    flags.push_back(lineNumber);
                    totalFlags++;
                    displayFile();
                }
                else
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

            if(lineNumber > 0 && lineNumber <= totalLines)
            {
                flagsIterator = std::find(flags.begin(), flags.end(), lineNumber);
                if(flagsIterator != flags.end())
                {
                    totalFlags--;
                    flags.erase(flagsIterator);
                    displayFile();
                }
                else
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
        string searchString = "";
        if(commandLength > 1)
        {
            for(int i = 0 ; i < tokens.size(); i++)
            {
                searchString += tokens[i] + " ";
            }
        }
        else
        {
            errorHandlerObject.throwError(401);
            return;
        }
    }
    errorHandlerObject.throwError(504);
}

std::vector<std::string> Parser::tokenizer(std::string userCommand)
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