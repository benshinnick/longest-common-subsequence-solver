#include "similarity-solver.hpp"

//TESTING
#include <iostream>
//TESTING

int SimilaritySolver::calculateLcsLength(
    const std::string& firstSequence, const std::string& secondSequence
) {
    int twoRowCosts[2][secondSequence.size()+1];
    for(int j = 0; j < secondSequence.size(); ++j)
        twoRowCosts[0][j] = 0;
    twoRowCosts[1][0] = 0;
    
    int currRow = 1;
    for(int i = 1; i < firstSequence.size(); ++i) {
        int prevRow = (currRow == 1) ? 0 : 1;
        for(int j = 1; j < secondSequence.size(); ++j) {
            int prevCol = j - 1, currCol = j;
            if(firstSequence[i] == secondSequence[j]) {
                twoRowCosts[currRow][currCol] = twoRowCosts[prevRow][prevCol] + 1;
            }
            else if(twoRowCosts[prevRow][currCol] >= twoRowCosts[currRow][prevCol]) {
                twoRowCosts[currRow][currCol] = twoRowCosts[prevRow][currCol];
            }
            else twoRowCosts[currRow][currCol] = twoRowCosts[currRow][prevCol];
        }
        currRow = prevRow;
    }
    currRow = (currRow == 1) ? 0 : 1;
    return twoRowCosts[currRow][secondSequence.size()-1];
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
    std::string string1 = " fdsasdfxsdss";
    std::string string2 = " adfdsxasdfsdssrasadswfsfsdsx";
    // std::string string1 = multiStringsRetriever.getRightShiftedString(1);
    // std::string string2 = multiStringsRetriever.getRightShiftedString(2);
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