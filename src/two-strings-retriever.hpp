#ifndef TWO_STRINGS_RETRIEVER_HPP
#define TWO_STRINGS_RETRIEVER_HPP

#include <fstream>
#include <string>

class TwoStringsRetriever {

    const std::string TWO_STRINGS_FILE_INPUT_DIRECTORY = "input-files/";
    const std::string DEFAULT_TWO_STRINGS_FILE_NAME = "twoStrings.txt";

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