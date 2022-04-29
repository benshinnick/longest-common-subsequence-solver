/*
    Student Name: Ben Shinnick
    File Name: two-strings-retriever.hpp
    Assignment: COP4534 Project 5
*/

#ifndef TWO_STRINGS_RETRIEVER_HPP
#define TWO_STRINGS_RETRIEVER_HPP

#include <fstream>
#include <string>

const std::string TWO_STRINGS_FILE_INPUT_DIRECTORY = "";
const std::string DEFAULT_TWO_STRINGS_FILE_NAME = "twoStrings.txt";

class TwoStringsRetriever {

    private:
        std::string firstString;
        std::string secondString;
        std::string twoStringsInputFileName;

        std::string getTwoStringsInputFilePath();
        void readTwoStringsInputFile();

    public:
        TwoStringsRetriever();
        TwoStringsRetriever(std::string twoStringsInputFileName);
        std::string getFirstString();
        std::string getSecondString();
        void setNewInputFile(std::string twoStringsInputFileName);

};

#endif