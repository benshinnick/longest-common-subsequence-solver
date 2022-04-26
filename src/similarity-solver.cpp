#include "similarity-solver.hpp"

int SimilaritySolver::calculateLcsLength(
    const std::string& firstSequence, const std::string& secondSequence
) {

}

char SimilaritySolver::calucateSimularityMeasure() {

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

}

std::string SimilaritySolver::getSimilarityTable() {

}

void SimilaritySolver::setSequenceRetriever(std::string multiStringsInputFileName) {
    sequenceRetriever.setNewInputFile(multiStringsInputFileName);
    numStrings = sequenceRetriever.getNumStrings();
}

int SimilaritySolver::getNumStrings() {

}