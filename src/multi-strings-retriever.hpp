#ifndef MULTI_STRINGS_RETRIEVER_HPP
#define MULTI_STRINGS_RETRIEVER_HPP

#include <fstream>
#include <string>
#include <vector>

class MultiStringsRetriever {

    const std::string MULTI_STRINGS_FILE_INPUT_DIRECTORY = "input-files/";
    const std::string DEFAULT_MULTI_STRINGS_FILE_NAME = "multiStrings.txt";

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
        std::string getString(int stringNum);
        void setNewInputFile(std::string multiStringsInputFileName);
};

#endif