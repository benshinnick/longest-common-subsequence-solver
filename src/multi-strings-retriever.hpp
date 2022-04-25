#ifndef MULTI_STRINGS_RETRIEVER_HPP
#define MULTI_STRINGS_RETRIEVER_HPP

#include <fstream>
#include <string>

class MultiStringsRetriever {

    const std::string MULTI_STRINGS_FILE_INPUT_DIRECTORY = "input-files/";

    private:
        int numStrings;
        int* positions;
        std::ifstream multiStringsInput;

        bool openMultiStringsInputFile(std::string fileName);
        void computeLengths();

    public:
        MultiStringsRetriever(std::string multiStringsInputFileName);
        ~MultiStringsRetriever();
        int getNumStrings();
        std::string getString(int stringNum);
    
};

#endif