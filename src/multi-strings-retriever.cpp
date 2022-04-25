#include "multi-strings-retriever.hpp"

bool MultiStringsRetriever::openMultiStringsInputFile(std::string fileName) {
    std::string multiStringsFileInputPath = MULTI_STRINGS_FILE_INPUT_DIRECTORY;
    multiStringsFileInputPath += fileName;
    multiStringsInput.open(multiStringsFileInputPath);

    if(multiStringsInput.is_open()) return true;
    return false;
}

void MultiStringsRetriever::computeStartingPositions() {
    std::string numStringsStr;
    std::getline(multiStringsInput, numStringsStr);

    numStrings = std::stoi(numStringsStr);
    positions = new int [numStrings];
    positions[0] = numStringsStr.length()+1;
    
    std::string line;
    int currStrIdx = 0;
    while(std::getline(multiStringsInput, line)) {
        positions[++currStrIdx] = positions[currStrIdx] + line.length()+1;
    }
}

MultiStringsRetriever::MultiStringsRetriever(std::string multiStringsInputFileName) {
    if(openMultiStringsInputFile(multiStringsInputFileName)) computeStartingPositions();
}

MultiStringsRetriever::~MultiStringsRetriever() {
    delete positions;
    multiStringsInput.close();
}

int MultiStringsRetriever::getNumStrings() {
    return numStrings;
}

std::string MultiStringsRetriever::getString(int stringNum) {
    std::string retrievedString;
    int stringStartPos = positions[stringNum];

    multiStringsInput.clear();
    multiStringsInput.seekg(stringStartPos);

    std::getline(multiStringsInput, retrievedString);
    return retrievedString;
}