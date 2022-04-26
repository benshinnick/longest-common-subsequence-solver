#include "two-strings-retriever.hpp"

std::string TwoStringsRetriever::getTwoStringsInputFilePath() {
    std::string twoStringsFileInputPath = TWO_STRINGS_FILE_INPUT_DIRECTORY;
    twoStringsFileInputPath += twoStringsInputFileName;
    return twoStringsFileInputPath;
}

void TwoStringsRetriever::readTwoStringsInputFile() {
    std::ifstream twoStringsInput(getTwoStringsInputFilePath());
    if(twoStringsInput.is_open()) {
        twoStringsInput >> firstString;
        twoStringsInput >> secondString;
        twoStringsInput.close();
    }
}

TwoStringsRetriever::TwoStringsRetriever() {
    this->twoStringsInputFileName = DEFAULT_TWO_STRINGS_FILE_NAME;
    readTwoStringsInputFile();
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