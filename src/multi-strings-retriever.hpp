#ifndef MULTI_STRINGS_RETRIEVER_HPP
#define MULTI_STRINGS_RETRIEVER_HPP

#include <fstream>
#include <string>

class MultiStringsRetriever {

    const std::string MULTI_STRINGS_FILE_INPUT_DIRECTORY = "input-files/";
    const std::string DEFAULT_MULTI_STRINGS_FILE_NAME = "multiStrings.txt";

    private:
        int numStrings;
        int* positions;
        std::ifstream multiStringsInput;

        bool openMultiStringsInputFile(std::string fileName);
        void computeStartingPositions();

    public:
        MultiStringsRetriever();
        MultiStringsRetriever(std::string multiStringsInputFileName);
        ~MultiStringsRetriever();
        int getNumStrings();
        std::string getString(int stringNum);
    
};

#endif