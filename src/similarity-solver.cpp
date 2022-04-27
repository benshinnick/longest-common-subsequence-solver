#include "similarity-solver.hpp"

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

char SimilaritySolver::calcucateSimularityMeasure(int firstLen, int secondLen, int lcsLen) {
    int shorterLen = firstLen < secondLen ? firstLen : secondLen;
    int longerLen = firstLen > secondLen ? firstLen : secondLen;
    
    float shorterLenPercentOfLonger = (float) shorterLen / longerLen;
    float lcsLenPercentOfShorter = (float) lcsLen / shorterLen;

    if(shorterLenPercentOfLonger >= 0.9 && lcsLenPercentOfShorter >= 0.9)
        return 'H';
    else if(shorterLenPercentOfLonger >= 0.8 && lcsLenPercentOfShorter >= 0.8)
        return 'M';
    else if(shorterLenPercentOfLonger >= 0.6 && lcsLenPercentOfShorter >= 0.5)
        return 'L';
    else
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

char SimilaritySolver::getSimularityMeasure(int firstStringNum, int secondStringNum) {
    std::string firstSequence = multiStringsRetriever.getRightShiftedString(firstStringNum);
    std::string secondSequence = multiStringsRetriever.getRightShiftedString(secondStringNum);
    
    int lcsLen = calculateLcsLength(firstSequence, secondSequence);
    return calcucateSimularityMeasure(firstSequence.size(), secondSequence.size(), lcsLen);
}

std::string SimilaritySolver::getSimilarityTable() {
    std::stringstream tableStream;

    for(int i = 0; i < numSequences; ++i) {
        if(i == 0) tableStream << std::setw(3) << ' ';
        tableStream << std::setw(2) << std::setfill('0') << i+1 << ' ';
        if(i == numSequences - 1) tableStream << std::endl;
    }

    for(int i = 0; i < numSequences; ++i) {
        tableStream << std::setw(2) << std::setfill('0') << i+1 << ' ';
        tableStream << std::setfill(' ');
        for(int j = 0; j < numSequences; ++j) {
            if(j <= i) tableStream << std::setw(2) << '-' << ' ';
            else tableStream << std::setw(2) <<  getSimularityMeasure(i, j) << ' ';
            if(j == numSequences - 1) tableStream << std::endl;
        }
    }

    return tableStream.str();
}

void SimilaritySolver::setMultiStringsRetriever(std::string multiStringsInputFileName) {
    multiStringsRetriever.setNewInputFile(multiStringsInputFileName);
    numSequences = multiStringsRetriever.getNumStrings();
}

int SimilaritySolver::getNumSequences() {
    return numSequences;
}