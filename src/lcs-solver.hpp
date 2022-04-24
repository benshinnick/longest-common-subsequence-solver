#ifndef LCS_SOLVER_HPP
#define LCS_SOLVER_HPP

#include <string>

#include "two-strings-retriever.hpp"

class LcsSolver {

    static const int MAX_SEQUENCE_LENGTH = 1000;

    private:
        std::string firstSequence;
        std::string secondSequence;
        int costs[MAX_SEQUENCE_LENGTH+1][MAX_SEQUENCE_LENGTH+1];

        void getRightShiftedSequence(std::string sequence);
        void getLeftShiftedSequence(std::string sequence);
        std::string recoverLongestCommonSubsequence();

    public:
        LcsSolver(std::string firstSequence, std::string secondSequence);
        void runAlgorithm();
        std::string getLongestCommonSubsequence();
        int getLongestCommonSubsequenceLength();

        void setFirstSequence(std::string firstSequence);
        std::string getFirstSequence();
        void setSecondSequence(std::string firstSequence);
        std::string getSecondSequence();
};

#endif