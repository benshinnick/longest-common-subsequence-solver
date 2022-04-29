#include <iostream>

#include "two-strings-retriever.hpp"
#include "lcs-solver.hpp"
#include "similarity-solver.hpp"

const std::string TWO_STRINGS_INPUT_FILE_NAME = "twoStrings.txt";
const std::string MULTI_STRINGS_INPUT_FILE_NAME = "multiStrings.txt";

void printDivider() {
    std::cout << "---------------------------------------------------"
        << "--------------------------------------------" << std::endl;
}

// Part 1
void printLcsResults() {
    TwoStringsRetriever twoStrings = TwoStringsRetriever(TWO_STRINGS_INPUT_FILE_NAME);
    std::string firstSequence = twoStrings.getFirstString();
    std::string secondSequence = twoStrings.getSecondString();
    LcsSolver lcsSolver = LcsSolver(firstSequence, secondSequence);
    lcsSolver.runAlgorithm();

    printDivider();
    std::cout << "The longest common subsequence between the two strings in " << TWO_STRINGS_INPUT_FILE_NAME << ":" << std::endl;
    printDivider();
    std::cout << lcsSolver.getLongestCommonSubsequence() << std::endl;
    std::cout << "Length = " << lcsSolver.getLongestCommonSubsequenceLength() << std::endl;
}

// Part 2
void printSimilarityResults() {
    SimilaritySolver similaritySolver = SimilaritySolver(MULTI_STRINGS_INPUT_FILE_NAME);

    printDivider();
    std::cout << "Similarity Measures from strings in "<< MULTI_STRINGS_INPUT_FILE_NAME << ":" << std::endl;
    printDivider();
    std::cout << similaritySolver.getSimilarityTable();
}

int main() {
    printLcsResults();
    printSimilarityResults();
    printDivider();
}