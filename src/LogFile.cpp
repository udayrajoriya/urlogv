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

void LogFile::searchFile()
{
    std::string logLine;
    searchResults.clear();
    searchLineNo.clear();
    for(long long int i = 0 ; i < logFileContents.size(); i++)
    {
        logLine = logFileContents[i];
        if(searchString != "")
        {
            std::size_t found = logLine.find(searchString);
            if(found != std::string::npos)
            {
                searchResults.push_back(logLine);
                searchLineNo.push_back(i);
            }
                
        }
    }
}

void LogFile::updateFirstLine()
{
    long long int lengthToCover = 0;
    if(searchString == "")
    {
        lengthToCover = logFileContents.size()-1;
    }
    else
    {
        lengthToCover = searchResults.size()-1;
    }
    if(lastLineViewed < (lengthToCover))
    {
        if(fromLine == 0 && toLine == 0)
        {
            long long int tempLine = lastLineViewed + 1;
            if(tempLine < lengthToCover)
            {
                pageFirstLine = tempLine;
            }
        }
        else
        {
            if((lastLineViewed + 1) < toLine)
            {
                if((lastLineViewed + 1) >= fromLine)
                {
                    pageFirstLine = lastLineViewed + 1;
                }
                else
                {
                    lastLineViewed = fromLine - 2;
                    pageFirstLine = lastLineViewed + 1;
                }
            }
        }
    }
    else
    {
        if(lastLineViewed == -1)
        {
            pageFirstLine = 0;
        }
    }
}

void LogFile::viewSearchResults()
{
    std::string logLine;
    long long int logLineNo;
    linesViewed = 0;
    updateFirstLine();
    for(long long int i = pageFirstLine ; i < searchResults.size(); i++)
    {
        if(linesViewed < linesPerPage)
        {
            lastLineViewed = i;
            logLine = searchResults[i];
            logLineNo = searchLineNo[i];
            displayLine(logLineNo, logLine);
        }
        else
        {
            break;
        }
    }
}

void LogFile::displayFile()
{
    std::string logLine;
    linesViewed = 0;
    updateFirstLine();
    for(long long int i = pageFirstLine ; i < logFileContents.size(); i++)
    {
        if(linesViewed < linesPerPage)
        {
            lastLineViewed = i;
            logLine = logFileContents[i];
            displayLine(i, logLine);
        }
        else
        {
            break;
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
    linesViewed++;
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

    if(incomingSearchString == "")
    {
        searchResults.clear();
        searchLineNo.clear();
    }
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

void LogFile::setPreviousPage()
{
    lastLineViewed = pageFirstLine - linesPerPage - 1;
    if(fromLine == 0 && toLine == 0)
    {
        
    }
    else
    {
        if((lastLineViewed + 1) >= fromLine)
        {
            pageFirstLine = lastLineViewed;
        }
        else
        {
            lastLineViewed = fromLine - 2;
            pageFirstLine = lastLineViewed + 1;
        }
    }
    
    if(lastLineViewed < 0)
    {
        lastLineViewed = -1;
    }
}

void LogFile::setLastLineViewed(long long int lineNo)
{
    lastLineViewed = lineNo;
}

void LogFile::resetPagination()
{
    lastLineViewed = -1;
    pageFirstLine = 0;
}