#include "catch/catch.hpp"
#include "../src/two-strings-retriever.hpp"
#include "../src/lcs-solver.hpp"

TEST_CASE("Testing LCS Solver On Simple In Class Example") {
    TwoStringsRetriever twoStrings = TwoStringsRetriever("testTwoStringsInClass.txt");
    std::string firstSequence = twoStrings.getFirstString();
    std::string secondSequence = twoStrings.getSecondString();

    LcsSolver lcsSolver = LcsSolver(firstSequence, secondSequence);
    REQUIRE(lcsSolver.getFirstSequence() == "abacd");
    REQUIRE(lcsSolver.getSecondSequence() == "baca");

    lcsSolver.runAlgorithm();
    lcsSolver.printCostArray();
    REQUIRE(lcsSolver.getLongestCommonSubsequence() == "bac");
    REQUIRE(lcsSolver.getLongestCommonSubsequenceLength() == 3);
}

TEST_CASE("Testing LCS Solver") {
    TwoStringsRetriever twoStrings = TwoStringsRetriever("testTwoStrings.txt");
    std::string firstSequence = twoStrings.getFirstString();
    std::string secondSequence = twoStrings.getSecondString();

    LcsSolver lcsSolver = LcsSolver(firstSequence, secondSequence);
    REQUIRE(lcsSolver.getFirstSequence() == "fdsasdfxsdss");
    REQUIRE(lcsSolver.getSecondSequence() == "adfdsasdfsdssasadsfsfsds");

    lcsSolver.runAlgorithm();
    REQUIRE(lcsSolver.getLongestCommonSubsequence() == "fdsasdfsdss");
    REQUIRE(lcsSolver.getLongestCommonSubsequenceLength() == 11);
}