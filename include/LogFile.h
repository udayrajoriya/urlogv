#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

class LogFile
{
    private:
        std::ifstream logFile;
        std::vector<std::string> logFileContents;
        long long int totalLines = 0;
        long long int totalFlags = 0;
        long long int fromLine = 0;
        long long int toLine = 0;
        std::string searchString = "";

        std::vector<long long int> flags;
        std::vector<long long int>::iterator flagsIterator;

    public:
        void unloadFile(char* filePath);
        void displayFile();

        long long int getTotalLines();
        void setTotalLines(long long int);

        long long int getTotalFlags();
        void setTotalFlags(long long int);

        long long int getFromLine();
        void setFromLine(long long int);

        long long int getToLine();
        void setToLine(long long int);

        std::string getSearchString();
        void setSearchString(std::string);

        int flagLine(int);
        int unFlagLine(int);

        void displayLine(int, std::string);
};