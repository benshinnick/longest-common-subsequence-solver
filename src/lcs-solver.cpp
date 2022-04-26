#include "lcs-solver.hpp"

std::string LcsSolver::getRightShiftedSequence(std::string sequence) {
    return ' ' + sequence;
}

std::string LcsSolver::getLeftShiftedSequence(std::string sequence) {
    return sequence.substr(1);
}

std::string LcsSolver::recoverLongestCommonSubsequence(int r, int c) {
    if(r == 0 || c == 0)
        return std::string();
    if(firstSequence[r] == secondSequence[c]) 
        return recoverLongestCommonSubsequence(r-1, c-1) + firstSequence[r];
    if(costs[r-1][c] >= costs[r][c-1])
        return recoverLongestCommonSubsequence(r-1, c);
    return recoverLongestCommonSubsequence(r, c-1);
}

LcsSolver::LcsSolver(std::string firstSequence, std::string secondSequence) {
    setFirstSequence(firstSequence);
    setSecondSequence(secondSequence);
}

void LcsSolver::runAlgorithm() {
    int firstSequenceLength = firstSequence.size();
    int secondSequenceLength = secondSequence.size();

    // for(int r = 0; r < firstSequenceLength; ++r)
    //     costs[r][0] = 0;
    // for(int c = 1; c < secondSequenceLength; ++c)
    //     costs[0][c] = 0;

    for(int r = 1; r < firstSequenceLength; ++r) {
        for(int c = 1; c < secondSequenceLength; ++c) {
            if(firstSequence[r] == secondSequence[c]) {
                costs[r][c] = costs[r-1][c-1] + 1;
                continue;
            }
            if(costs[r-1][c] >= costs[r][c-1]) {
                costs[r][c] = costs[r-1][c];
                continue;
            }
            costs[r][c] = costs[r][c-1];
        }
    }
}

std::string LcsSolver::getLongestCommonSubsequence() {
    return recoverLongestCommonSubsequence(firstSequence.size()-1, secondSequence.size()-1);
}

int LcsSolver::getLongestCommonSubsequenceLength() {
    return costs[firstSequence.size()-1][secondSequence.size()-1];
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