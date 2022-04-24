#include "catch/catch.hpp"
#include "../src/two-strings-retriever.hpp"

TEST_CASE("Testing Retrieving Two Strings From File") {
    TwoStringsRetriever twoStrings = TwoStringsRetriever("testTwoStrings.txt");
    REQUIRE(twoStrings.getFirstString() == "fdsasdfxsdss");
    REQUIRE(twoStrings.getSecondString() == "adfdsasdfsdssasadsfsfsds");
}