#include "lcs-solver.hpp"

std::string LcsSolver::getRightShiftedSequence(std::string sequence) {
    return ' ' + sequence;
}

std::string LcsSolver::getLeftShiftedSequence(std::string sequence) {
    return sequence.substr(1);
}

std::string LcsSolver::recoverLongestCommonSubsequence() {

}

LcsSolver::LcsSolver(std::string firstSequence, std::string secondSequence) {
    setFirstSequence(firstSequence);
    setSecondSequence(secondSequence);
}

void LcsSolver::runAlgorithm() {

}

std::string LcsSolver::getLongestCommonSubsequence() {

}

int LcsSolver::getLongestCommonSubsequenceLength() {

}

void LcsSolver::setFirstSequence(std::string firstSequence) {
    this->firstSequence = getRightShiftedSequence(firstSequence);
}

std::string LcsSolver::getFirstSequence() {
    return getLeftShiftedSequence(firstSequence);
}

void LcsSolver::setSecondSequence(std::string secondSequence) {
    this->secondSequence = getRightShiftedSequence(secondSequence);
}

std::string LcsSolver::getSecondSequence() {
    return getLeftShiftedSequence(secondSequence);
}