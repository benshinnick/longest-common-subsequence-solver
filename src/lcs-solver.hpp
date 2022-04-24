#ifndef LCS_SOLVER_HPP
#define LCS_SOLVER_HPP

#include <string>

#include "two-strings-retriever.hpp"

class LcsSolver {

    static const int MAX_SEQUENCE_LENGTH = 1000;
    const std::string TWO_STRINGS_INPUT_FILE_NAME = "testTwoStrings.txt";

    private:
        std::string firstSequence;
        std::string secondSequence;
        int costs[MAX_SEQUENCE_LENGTH + 1][MAX_SEQUENCE_LENGTH + 1];

        std::string findLongestCommonSubsequence();

    public:
        LcsSolver();
        std::string getLongestCommonSubsequence();

};

#endif