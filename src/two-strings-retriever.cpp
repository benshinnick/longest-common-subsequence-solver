#include "two-strings-retriever.hpp"

std::string TwoStringsRetriever::getTwoStringsInputFilePath() {
    std::string twoStringsFileInputPath = TWO_STRINGS_FILE_INPUT_DIRECTORY;
    twoStringsFileInputPath += twoStringsInputFileName;
    return twoStringsFileInputPath;
}

void TwoStringsRetriever::readTwoStringsInputFile() {
    std::ifstream twoStringsInput;
    twoStringsInput.open(getTwoStringsInputFilePath());
    if(twoStringsInput.is_open()) {
        twoStringsInput >> firstString;
        twoStringsInput >> secondString;
        twoStringsInput.close();
    }
}

TwoStringsRetriever::TwoStringsRetriever(std::string twoStringsInputFileName) {
    this->twoStringsInputFileName = twoStringsInputFileName;
    readTwoStringsInputFile();
}

std::string TwoStringsRetriever::getFirstString() {
    return this->firstString;
}

std::string TwoStringsRetriever::getSecondString() {
    return this->secondString;
}

void TwoStringsRetriever::setNewInputFile(std::string twoStringsInputFileName) {
    this->twoStringsInputFileName = twoStringsInputFileName;
    readTwoStringsInputFile();
}