/*
    Student Name: Ben Shinnick
    File Name: multi-strings-retriever.hpp
    Assignment: COP4534 Project 5
*/

#ifndef MULTI_STRINGS_RETRIEVER_HPP
#define MULTI_STRINGS_RETRIEVER_HPP

#include <fstream>
#include <string>
#include <vector>

const std::string MULTI_STRINGS_FILE_INPUT_DIRECTORY = "input-files/";
const std::string DEFAULT_MULTI_STRINGS_FILE_NAME = "multiStrings.txt";

class MultiStringsRetriever {

    private:
        int numStrings;
        std::vector<int> positions;
        std::string multiStringsInputFileName;

        std::string getMultiStringsInputFilePath();
        void computeStartingPositions();

    public:
        MultiStringsRetriever();
        MultiStringsRetriever(std::string multiStringsInputFileName);
        int getNumStrings();
        std::string getStr(int strNum);
        int getStrLen(int strNum);
        std::string getRightShiftedString(int strNum);
        void setNewInputFile(std::string multiStringsInputFileName);
        
};

#endif