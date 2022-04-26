#include "similarity-solver.hpp"

int SimilaritySolver::calculateLcsLength(
    const std::string& firstSequence, const std::string& secondSequence
) {
    return -1;
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
    return "";
}

void SimilaritySolver::setMultiStringsRetriever(std::string multiStringsInputFileName) {
    multiStringsRetriever.setNewInputFile(multiStringsInputFileName);
    numSequences = multiStringsRetriever.getNumStrings();
}

int SimilaritySolver::getNumSequences() {
    return numSequences;
}