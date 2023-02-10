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
        std::vector<std::string> searchResults;
        std::vector<long long int> searchLineNo;
        long long int totalLines = 0;
        long long int totalFlags = 0;
        long long int fromLine = 0;
        long long int toLine = 0;
        std::string searchString = "";
        long long int linesPerPage = 20;
        long long int linesViewed = 0;
        long long int lastLineViewed = -1;
        long long int pageFirstLine = 0;

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

        void searchFile();
        void viewSearchResults();

        int flagLine(int);
        int unFlagLine(int);

        void displayLine(int, std::string);

        void setPreviousPage();
        
        void setLastLineViewed(long long int);

        void resetPagination();

        void updateFirstLine();
};