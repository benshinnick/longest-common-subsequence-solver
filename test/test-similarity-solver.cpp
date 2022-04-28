#include "catch/catch.hpp"
#include "../src/multi-strings-retriever.hpp"
#include "../src/similarity-solver.hpp"

#include <iostream>

TEST_CASE("Testing Similarity Solver") {
    SimilaritySolver similaritySolver = SimilaritySolver("testMultiStrings.txt");
    REQUIRE(similaritySolver.getNumSequences() == 5);
    std::cout << similaritySolver.getSimilarityTable() << std::endl;

    REQUIRE(similaritySolver.getSimularityMeasure(0, 1) == 'H');
    REQUIRE(similaritySolver.getSimularityMeasure(2, 3) == 'M');
    REQUIRE(similaritySolver.getSimularityMeasure(2, 4) == 'L');
    REQUIRE(similaritySolver.getSimularityMeasure(0, 2) == 'D');
}