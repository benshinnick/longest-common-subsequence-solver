#include "similarity-solver.hpp"

int SimilaritySolver::calculateLcsLength(
    const std::string& firstSequence, const std::string& secondSequence
) {
    // int firstSequenceLength = firstSequence.size();
    // int secondSequenceLength = secondSequence.size();

    // int twoRowCosts[2][firstSequenceLength+1];
    // int currWorkingRow = 1;

    // for(int i = 1; i < firstSequenceLength; ++i) {
    //     for(int j = 1; j < secondSequenceLength; ++j) {
    //         if(firstSequence[i] == secondSequence[j]) {
    //             costs[r][c] = costs[r-1][c-1] + 1;
    //             continue;
    //         }
    //         if(costs[r-1][c] >= costs[r][c-1]) {
    //             costs[r][c] = costs[r-1][c];
    //             continue;
    //         }
    //         costs[r][c] = costs[r][c-1];
    //     }
    // }

    return -1;
}

char SimilaritySolver::calucateSimularityMeasure() {
    return 'D';
}

SimilaritySolver::SimilaritySolver() {
    numSequences = multiStringsRetriever.getNumStrings();
}

SimilaritySolver::SimilaritySolver(std::string multiStringsInputFileName) {
    multiStringsRetriever.setNewInputFile(multiStringsInputFileName);
    numSequences = multiStringsRetriever.getNumStrings();
}

char SimilaritySolver::getSimularityMeasure(
    const std::string& firstSequence, const std::string& secondSequence
) {
    return 'D';
}

std::string SimilaritySolver::getSimilarityTable() {
    return "";
}

void SimilaritySolver::setMultiStringsRetriever(std::string multiStringsInputFileName) {
    multiStringsRetriever.setNewInputFile(multiStringsInputFileName);
    numSequences = multiStringsRetriever.getNumStrings();
}

int SimilaritySolver::getNumSequences() {
    return numSequences;
}