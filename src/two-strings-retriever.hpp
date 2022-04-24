#ifndef TWO_STRINGS_RETRIEVER_HPP
#define TWO_STRINGS_RETRIEVER_HPP

#include <fstream>
#include <string>

class TwoStringsRetriever {

    const std::string TWO_STRINGS_FILE_INPUT_DIRECTORY = "input-files/";

    private:
        std::string firstString;
        std::string secondString;
        std::ifstream twoStringsInput;

        bool openTwoStringsInputFile(std::string twoStringsInputFileName);
        void readTwoStringsInputFile();

    public:
        TwoStringsRetriever(std::string twoStringsInputFileName);
        std::string getFirstString();
        std::string getSecondString();

};

#endif