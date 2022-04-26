#include "multi-strings-retriever.hpp"

std::string MultiStringsRetriever::getMultiStringsInputFilePath() {
    std::string multiStringsFileInputPath = MULTI_STRINGS_FILE_INPUT_DIRECTORY;
    multiStringsFileInputPath += multiStringsInputFileName;
    return multiStringsFileInputPath;
}

void MultiStringsRetriever::computeStartingPositions() {
    std::ifstream multiStringsInput(getMultiStringsInputFilePath());
    if(multiStringsInput.is_open()) {
        std::string numStringsStr;
        std::getline(multiStringsInput, numStringsStr);
        numStrings = std::stoi(numStringsStr);
        positions.resize(numStrings);
        positions[0] = numStringsStr.length()+1;
        
        std::string line;
        for(int i = 1; i < numStrings; ++i) {
            std::getline(multiStringsInput, line);
            positions[i] = positions[i-1] + line.length()+1;
        }
        multiStringsInput.close();
    }
}

MultiStringsRetriever::MultiStringsRetriever() {
    this->multiStringsInputFileName = DEFAULT_MULTI_STRINGS_FILE_NAME;
    computeStartingPositions();
}

MultiStringsRetriever::MultiStringsRetriever(std::string multiStringsInputFileName) {
    this->multiStringsInputFileName = multiStringsInputFileName;
    computeStartingPositions();
}

int MultiStringsRetriever::getNumStrings() {
    return numStrings;
}

std::string MultiStringsRetriever::getString(int stringNum) {
    std::string retrievedString;
    std::ifstream multiStringsInput(getMultiStringsInputFilePath());
    if(multiStringsInput.is_open()) {
        int stringStartPos = positions[stringNum];

        multiStringsInput.clear();
        multiStringsInput.seekg(stringStartPos);
        std::getline(multiStringsInput, retrievedString);

        multiStringsInput.close();
    }
    return retrievedString;
}

void MultiStringsRetriever::setNewInputFile(std::string multiStringsInputFileName) {
    this->multiStringsInputFileName = multiStringsInputFileName;
    computeStartingPositions();
}