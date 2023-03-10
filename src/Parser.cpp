#include "../include/Parser.h"

void Parser::parseCommand(std::string userCommand, LogFile &logFileObject, bool &shouldRun)
{
    std::vector<std::string> tokens = tokenizer(userCommand);
    int commandLength = tokens.size();
    if(tokens[0] == "f") //Add flag to a line
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
                }
            }
            else
            {
                errorHandlerObject.throwError(603);
            }
        }
        else
        {
            errorHandlerObject.throwError(401);
        }
        return;
    }
    if(tokens[0] == "rf") //Remove flag from a line
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
                }
            }
            else
            {
                errorHandlerObject.throwError(603);
            }
        }
        else
        {
            errorHandlerObject.throwError(401);
        }
        return;
    }
    if(tokens[0] == "vr") //View lines only in range
    {
        if(commandLength == 3)
        {
            long long int fromLine;
            long long int toLine;
            try
            {
                fromLine = stoi(tokens[1]);
                toLine = stoi(tokens[2]);
                if(fromLine == 0 || toLine == 0)
                    throw 505;
            }
            catch(...)
            {
                errorHandlerObject.throwError(604);
                return;
            }

            if((fromLine > 0 && fromLine <= logFileObject.getTotalLines()) && (toLine > 0 && toLine <= logFileObject.getTotalLines()) && (fromLine < toLine))
            {
                logFileObject.setFromLine(fromLine);
                logFileObject.setToLine(toLine);
                logFileObject.setSearchString("");
                logFileObject.setLastLineViewed(fromLine-2);
                logFileObject.displayFile();
            }
            else
            {
                errorHandlerObject.throwError(604);
            }
        }
        else
        {
            errorHandlerObject.throwError(401);
        }
        return;
    }
    if(tokens[0] == "va") //View all lines
    {
        if(commandLength == 1)
        {
            logFileObject.setSearchString("");
            logFileObject.setFromLine(0);
            logFileObject.setToLine(0);
            logFileObject.resetPagination();
            logFileObject.displayFile();
        }
        else
        {
            errorHandlerObject.throwError(401);
        }
        return;
    }
    if(tokens[0] == "q") //Quit
    {
        if(commandLength == 1)
        {
            shouldRun = false;
        }
        else
        {
            errorHandlerObject.throwError(401);
        }
        return;
    }
    if(tokens[0] == "s") //Search
    {
        bool foundCmd = false;
        logFileObject.setSearchString("");
        std::string tempString = "";
        if(commandLength > 1)
        {
            for(int i = 0; i < userCommand.length(); i++)
            {
                if(userCommand[i] == 's' && foundCmd == false)
                {
                    foundCmd = true;
                    i++;
                }
                else
                {
                    tempString += userCommand[i];
                }
            }
            logFileObject.setFromLine(0);
            logFileObject.setToLine(0);
            logFileObject.setSearchString(tempString);
            logFileObject.setLastLineViewed(-1);
            logFileObject.searchFile();
            logFileObject.viewSearchResults();
            return;
        }
        else
        {
            errorHandlerObject.throwError(401);
            return;
        }
    }
    if(tokens[0] == "sc") //Clear search string
    {
        if(commandLength == 1)
        {
            logFileObject.setSearchString("");
            logFileObject.resetPagination();
            logFileObject.displayFile();
        }
        else
        {
            errorHandlerObject.throwError(401);
        }
        return;
    }
    if(tokens[0] == "n") //Quit
    {
        if(commandLength == 1)
        {
            if(logFileObject.getSearchString() == "")
                logFileObject.displayFile();
            else
                logFileObject.viewSearchResults();
        }
        else
        {
            errorHandlerObject.throwError(401);
        }
        return;
    }
    if(tokens[0] == "p") //Quit
    {
        if(commandLength == 1)
        {
            logFileObject.setPreviousPage();
            
            if(logFileObject.getSearchString() == "")
                logFileObject.displayFile();
            else
                logFileObject.viewSearchResults();
        }
        else
        {
            errorHandlerObject.throwError(401);
        }
        return;
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