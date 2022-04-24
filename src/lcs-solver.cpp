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
    int firstSequenceLength = firstSequence.size();
    int secondSequenceLength = secondSequence.size();

    for(int r = 0; r <= firstSequenceLength; ++r)
        costs[r][0] = 0;
    for(int c = 1; c <= secondSequenceLength; ++c)
        costs[0][c] = 0;

    for(int r = 1; r <= firstSequenceLength; ++r) {
        for(int c = 1; c <= secondSequenceLength; ++c) {
            if(firstSequence[r] == secondSequence[c]) {
                costs[r][c] = costs[r-1][c-1];
                continue;
            }
            if(costs[r-1][c] >= costs[r][c-1]) {
                costs[r][c] = costs[r-1][c-1] + 1;
                continue;
            }
            costs[r][c] = costs[r][c-1];
        }
    }

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