#include "catch/catch.hpp"
#include "../src/multi-strings-retriever.hpp"
#include "../src/similarity-solver.hpp"

#include <iostream>

TEST_CASE("Testing Similarity Solver Similarity Measures") {
    SimilaritySolver similaritySolver = SimilaritySolver("testMultiStrings.txt");
    REQUIRE(similaritySolver.getNumSequences() == 5);
    std::cout << similaritySolver.getSimilarityTable() << std::endl;

    REQUIRE(similaritySolver.getSimularityMeasure(0, 1) == 'H');
    REQUIRE(similaritySolver.getSimularityMeasure(2, 3) == 'M');
    REQUIRE(similaritySolver.getSimularityMeasure(2, 4) == 'L');
    REQUIRE(similaritySolver.getSimularityMeasure(0, 2) == 'D');
}

TEST_CASE("Testing Similarity Solver LCS Length") {
    SimilaritySolver similaritySolver = SimilaritySolver("testMultiStrings.txt");
    REQUIRE(similaritySolver.getNumSequences() == 5);
    
    REQUIRE(similaritySolver.getLcsLength(0, 1) == 9);
    REQUIRE(similaritySolver.getLcsLength(2, 3) == 16);
    REQUIRE(similaritySolver.getLcsLength(2, 4) == 12);
    REQUIRE(similaritySolver.getLcsLength(0, 2) == 9);
}

