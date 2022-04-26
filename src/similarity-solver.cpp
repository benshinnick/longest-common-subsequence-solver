#include "similarity-solver.hpp"

int SimilaritySolver::calculateLcsLength(
    const std::string& firstSequence, const std::string& secondSequence
) {

}

char SimilaritySolver::calucateSimularityMeasure() {

}

SimilaritySolver::SimilaritySolver() {
    sequenceRetriever = new MultiStringsRetriever();
    numStrings = sequenceRetriever->getNumStrings();
}

SimilaritySolver::SimilaritySolver(std::string multiStringsInputFileName) {
    sequenceRetriever = new MultiStringsRetriever(multiStringsInputFileName);
    numStrings = sequenceRetriever->getNumStrings();
}

SimilaritySolver::~SimilaritySolver() {
    delete sequenceRetriever;
}

char SimilaritySolver::getSimularityMeasure(
    const std::string& firstSequence, const std::string& secondSequence
) {

}

std::string SimilaritySolver::getSimilarityTable() {

}

void SimilaritySolver::setSequenceRetriever(std::string multiStringsInputFileName) {
    delete sequenceRetriever;
    sequenceRetriever = new MultiStringsRetriever(multiStringsInputFileName);
    numStrings = sequenceRetriever->getNumStrings();
}