#include "two-strings-retriever.hpp"

bool TwoStringsRetriever::openTwoStringsInputFile(std::string twoStringsInputFileName) {
    std::string twoStringsFileInputPath = TWO_STRINGS_FILE_INPUT_DIRECTORY;
    twoStringsFileInputPath += twoStringsInputFileName;
    twoStringsInput.open(twoStringsFileInputPath);

    if(twoStringsInput.is_open()) return true;
    return false;
}

void TwoStringsRetriever::readTwoStringsInputFile() {
    twoStringsInput >> firstString;
    twoStringsInput >> secondString;
}

TwoStringsRetriever::TwoStringsRetriever(std::string twoStringsInputFileName) {
    if(openTwoStringsInputFile(twoStringsInputFileName)) readTwoStringsInputFile();
}

std::string TwoStringsRetriever::getFirstString() {
    return this->firstString;
}

std::string TwoStringsRetriever::getSecondString() {
    return this->secondString;
}