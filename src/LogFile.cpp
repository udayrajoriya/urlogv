#include "../include/LogFile.h"

void LogFile::unloadFile(char* filePath)
{
    logFile.open(filePath);
    std::string logLine;
    totalLines = 0;
    while (std::getline (logFile, logLine))
    {
        logFileContents.push_back(logLine);
        totalLines++;
    }
    logFile.close();
}

void LogFile::displayFile()
{
    long long int lineCounter = 0;
    std::string logLine;

    for(long long int i = 0 ; i < logFileContents.size(); i++)
    {
        lineCounter++;
        logLine = logFileContents[i];
        if(searchString != "")
        {
            std::size_t found = logLine.find(searchString);
            if(found != std::string::npos)
                displayLine(i, logLine);
        }
        else
        {
            displayLine(i, logLine);
        }
    }
}

void LogFile::displayLine(int lineNumber, std::string logLine)
{
    if(totalFlags > 0)
    {
        if(fromLine != 0 && toLine != 0)
        {
            if((lineNumber+1) >= fromLine && (lineNumber+1) <= toLine)
            {
                flagsIterator = std::find(flags.begin(), flags.end(), (lineNumber+1));
                if(flagsIterator != flags.end())
                {
                    std::cout<<"* ";
                }
                else
                {
                    std::cout<<"  ";
                }
            }
        }
        else
        {
            flagsIterator = std::find(flags.begin(), flags.end(), (lineNumber+1));
            if(flagsIterator != flags.end())
            {
                std::cout<<"* ";
            }
            else
            {
                std::cout<<"  ";
            }
        }
    }
    if(fromLine != 0 && toLine != 0)
    {
        if((lineNumber+1) >= fromLine && (lineNumber+1) <= toLine)
        {
            std::cout<<(lineNumber+1)<<"\t"<< logLine<<std::endl;
        }
    }
    else
    {
        std::cout<<(lineNumber+1)<<"\t"<< logLine<<std::endl;
    }
}

long long int LogFile::getTotalLines()
{
    return totalLines;
}

void LogFile::setTotalLines(long long int receivedLines)
{
    totalLines = receivedLines;
}

long long int LogFile::getFromLine()
{
    return fromLine;
}

void LogFile::setFromLine(long long int receivedLine)
{
    fromLine = receivedLine;
}

long long int LogFile::getToLine()
{
    return toLine;
}

void LogFile::setToLine(long long int receivedLine)
{
    toLine = receivedLine;
}

long long int LogFile::getTotalFlags()
{
    return totalFlags;
}

void LogFile::setTotalFlags(long long int receivedFlags)
{
    totalFlags = receivedFlags;
}

std::string LogFile::getSearchString()
{
    return searchString;
}

void LogFile::setSearchString(std::string incomingSearchString)
{
    searchString = incomingSearchString;
}

int LogFile::flagLine(int lineNumber)
{
    flagsIterator = std::find(flags.begin(), flags.end(), lineNumber);
    if(flagsIterator == flags.end())
    {
        flags.push_back(lineNumber);
        setTotalFlags(getTotalFlags()+1);
        displayFile();
    }
    else
    {
        return 0;
    }
    return 1;
}

int LogFile::unFlagLine(int lineNumber)
{
    flagsIterator = std::find(flags.begin(), flags.end(), lineNumber);
    if(flagsIterator != flags.end())
    {
        setTotalFlags(getTotalFlags()-1);
        flags.erase(flagsIterator);
        displayFile();
    }
    else
    {
        return 0;
    }
    return 1;
}