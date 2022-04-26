#include "similarity-solver.hpp"

int SimilaritySolver::calculateLcsLength(
    const std::string& firstSequence, const std::string& secondSequence
) {

}

char SimilaritySolver::calucateSimularityMeasure() {

}

SimilaritySolver::SimilaritySolver() {
    sequenceRetriever = MultiStringsRetriever();
    numStrings = sequenceRetriever.getNumStrings();
}

SimilaritySolver::SimilaritySolver(std::string multiStringsInputFileName) {
    sequenceRetriever = MultiStringsRetriever(multiStringsInputFileName);
    numStrings = sequenceRetriever.getNumStrings();
}

char SimilaritySolver::getSimularityMeasure(
    const std::string& firstSequence, const std::string& secondSequence
) {

}

std::string SimilaritySolver::getSimilarityTable() {

}

void SimilaritySolver::setSequenceRetriever(std::string multiStringsInputFileName) {
    sequenceRetriever = MultiStringsRetriever(multiStringsInputFileName);
    numStrings = sequenceRetriever.getNumStrings();
}