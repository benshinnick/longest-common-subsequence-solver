#include "catch/catch.hpp"
#include "../src/multi-strings-retriever.hpp"
#include "../src/similarity-solver.hpp"

TEST_CASE("Testing Similarity Solver Constructors") {
    SimilaritySolver similaritySolver1 = SimilaritySolver();
    REQUIRE(similaritySolver1.getNumStrings() == 8);
    SimilaritySolver similaritySolver2 = SimilaritySolver("simpleMultiStrings.txt");
    REQUIRE(similaritySolver2.getNumStrings() == 26);

    similaritySolver1.setSequenceRetriever("simpleMultiStrings.txt");
    REQUIRE(similaritySolver1.getNumStrings() == 26);
}