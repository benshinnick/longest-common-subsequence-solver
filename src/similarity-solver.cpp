#include "similarity-solver.hpp"

//TESTING
#include <iostream>
//TESTING

int SimilaritySolver::calculateLcsLength(
    const std::string& firstSequence, const std::string& secondSequence
) {
    int firstSequenceLength = firstSequence.size();
    int secondSequenceLength = secondSequence.size();
    int twoRowCosts[2][firstSequenceLength+1];
    for(int i = 0; i < firstSequenceLength; ++i) twoRowCosts[0][i] = 0;
    twoRowCosts[1][0] = 0;
    
    int currWorkingRow = 1;
    for(int i = 1; i < firstSequenceLength; ++i) {
        int prevRow = (currWorkingRow == 1) ? 0 : 1;
        std::cout << "Curr Working Row = " << currWorkingRow << std::endl;
        std::cout << "Prev Row = " << prevRow << std::endl;
        for(int row = 0; row < 2; ++row) {
            for(int col = 0; col < secondSequenceLength; ++col) {
                std::cout << twoRowCosts[row][col] << " ";
            }
            std::cout << std::endl;
        }
        for(int j = 1; j < secondSequenceLength; ++j) {
            std::cout << "[" << firstSequence[i] << "] == [" << secondSequence[j] << "]" << std::endl;
            if(firstSequence[i] == secondSequence[j]) {
                twoRowCosts[currWorkingRow][j] = twoRowCosts[prevRow][j-1] + 1;
                std::cout << "case 1: " << twoRowCosts[currWorkingRow][j] << std::endl;
                continue;
            }
            if(twoRowCosts[prevRow][j] >= twoRowCosts[currWorkingRow][j-1]) {
                twoRowCosts[currWorkingRow][j] = twoRowCosts[prevRow][j];
                std::cout << "case 2: " << twoRowCosts[currWorkingRow][j] << std::endl;
                continue;
            }
            twoRowCosts[currWorkingRow][j] = twoRowCosts[currWorkingRow][j-1];
            std::cout << "case 3: " << twoRowCosts[currWorkingRow][j] << std::endl;
        }
        if(i < firstSequenceLength - 1) currWorkingRow = prevRow;
    }
    return twoRowCosts[currWorkingRow][secondSequenceLength-1];
}

char SimilaritySolver::calucateSimularityMeasure() {
    return 'D';
}

SimilaritySolver::SimilaritySolver() {
    multiStringsRetriever = MultiStringsRetriever();
    numSequences = multiStringsRetriever.getNumStrings();
}

SimilaritySolver::SimilaritySolver(std::string multiStringsInputFileName) {
    multiStringsRetriever = MultiStringsRetriever(multiStringsInputFileName);
    numSequences = multiStringsRetriever.getNumStrings();
}

char SimilaritySolver::getSimularityMeasure(
    const std::string& firstSequence, const std::string& secondSequence
) {
    return 'D';
}

std::string SimilaritySolver::getSimilarityTable() {
    std::string string1 = multiStringsRetriever.getRightShiftedString(0);
    std::string string2 = multiStringsRetriever.getRightShiftedString(1);
    std::cout << "Comparing [" << string1 << "] and [" << string2 << "]" << std::endl;
    std::cout << calculateLcsLength(string1, string2) << std::endl;
    return "";
}

void SimilaritySolver::setMultiStringsRetriever(std::string multiStringsInputFileName) {
    multiStringsRetriever.setNewInputFile(multiStringsInputFileName);
    numSequences = multiStringsRetriever.getNumStrings();
}

int SimilaritySolver::getNumSequences() {
    return numSequences;
}