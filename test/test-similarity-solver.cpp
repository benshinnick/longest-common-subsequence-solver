#include "catch/catch.hpp"
#include "../src/multi-strings-retriever.hpp"
#include "../src/similarity-solver.hpp"

#include <iostream>

TEST_CASE("Testing Similarity Solver Constructors") {

    SimilaritySolver similaritySolver1 = SimilaritySolver();
    REQUIRE(similaritySolver1.getNumSequences() == 8);
    SimilaritySolver similaritySolver2 = SimilaritySolver("simpleMultiStrings.txt");
    REQUIRE(similaritySolver2.getNumSequences() == 26);

    std::cout << similaritySolver1.getSimilarityTable() << std::endl;
}