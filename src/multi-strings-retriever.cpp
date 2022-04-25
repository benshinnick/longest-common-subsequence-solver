#include "multi-strings-retriever.hpp"

bool MultiStringsRetriever::openMultiStringsInputFile(std::string fileName) {
    std::string multiStringsFileInputPath = MULTI_STRINGS_FILE_INPUT_DIRECTORY;
    multiStringsFileInputPath += fileName;
    multiStringsInput.open(multiStringsFileInputPath);

    if(multiStringsInput.is_open()) return true;
    return false;
}

void MultiStringsRetriever::computeLengths() {
    multiStringsInput >> numStrings;
    positions = new int [numStrings];
    positions[0] = 0;
    
    std::string line;
    int currString = 0;
    while(std::getline(multiStringsInput, line)) {
        positions[currString++] = line.length()+1;
    }
}

MultiStringsRetriever::MultiStringsRetriever(std::string multiStringsInputFileName) {
    if(openMultiStringsInputFile(multiStringsInputFileName)) computeLengths();
}

MultiStringsRetriever::~MultiStringsRetriever() {
    delete positions;
    multiStringsInput.close();
}

int MultiStringsRetriever::getNumStrings() {
    return numStrings;
}

std::string MultiStringsRetriever::getString(int stringNum) {
    multiStringsInput.seekg(positions[stringNum]);
    std::string string;
    std::getline(multiStringsInput, string);
    return string;
}