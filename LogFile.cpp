#include "LogFile.h"

void LogFile::unloadFile()
{
    logFile.open("logs.log");
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
                std::cout<<(i+1)<<"\t"<< logLine<<std::endl;
        }
        else
        {
            if(totalFlags > 0)
            {
                flagsIterator = std::find(flags.begin(), flags.end(), (i+1));
                if(flagsIterator != flags.end())
                {
                    std::cout<<"* ";
                }
                else
                {
                    std::cout<<"  ";
                }
                
            }
            std::cout<<(i+1)<<"\t"<< logLine<<std::endl;
        }
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