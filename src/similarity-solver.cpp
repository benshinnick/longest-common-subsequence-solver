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
    numStrings = sequenceRetriever.getNumStrings();
}

SimilaritySolver::SimilaritySolver(std::string multiStringsInputFileName) {
    sequenceRetriever.setNewInputFile(multiStringsInputFileName);
    numStrings = sequenceRetriever.getNumStrings();
}

char SimilaritySolver::getSimularityMeasure(
    const std::string& firstSequence, const std::string& secondSequence
) {
    return 'D';
}

std::string SimilaritySolver::getSimilarityTable() {
    return "";
}

void SimilaritySolver::setSequenceRetriever(std::string multiStringsInputFileName) {
    sequenceRetriever.setNewInputFile(multiStringsInputFileName);
    numStrings = sequenceRetriever.getNumStrings();
}

int SimilaritySolver::getNumStrings() {
    return numStrings;
}