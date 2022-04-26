#include "multi-strings-retriever.hpp"

std::string MultiStringsRetriever::getMultiStringsInputFilePath() {
    std::string multiStringsFileInputPath = MULTI_STRINGS_FILE_INPUT_DIRECTORY;
    multiStringsFileInputPath += multiStringsInputFileName;
    return multiStringsFileInputPath;
}

void MultiStringsRetriever::computeStartingPositions() {
    std::ifstream multiStringsInput;
    multiStringsInput.open(getMultiStringsInputFilePath());
    if(multiStringsInput.is_open()) {
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

MultiStringsRetriever::~MultiStringsRetriever() {
    delete positions;
}

int MultiStringsRetriever::getNumStrings() {
    return numStrings;
}

std::string MultiStringsRetriever::getString(int stringNum) {
    std::string retrievedString;
    std::ifstream multiStringsInput;
    multiStringsInput.open(getMultiStringsInputFilePath());
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

MultiStringsRetriever& MultiStringsRetriever::operator=(const MultiStringsRetriever& rhs) {
    if(this != &rhs) {
        this->numStrings = rhs.numStrings;
        this->positions = rhs.positions;
        this->multiStringsInputFileName = rhs.multiStringsInputFileName;
    }
    return *this;
}