#include "catch/catch.hpp"
#include "../src/multi-strings-retriever.hpp"

#include <iostream>

TEST_CASE("Testing Retrieving Multiple Strings From File") {
    MultiStringsRetriever eightStrings = MultiStringsRetriever();
    REQUIRE(eightStrings.getNumStrings() == 8);
    REQUIRE(eightStrings.getString(0) == "asdfdsasdfdsadfdsasdf");
    REQUIRE(eightStrings.getString(1) == "asdfdsasd");
    REQUIRE(eightStrings.getString(2) == "asdfdsasdfdsadfdsasdfsdssasadsfsdfsdsfadsfsdassdsfasdsd");
    REQUIRE(eightStrings.getString(3) == "asdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsd");
    REQUIRE(eightStrings.getString(4) == "dsasdfsadfdsasdfsdssa");
    REQUIRE(eightStrings.getString(5) == "asdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsd");
    REQUIRE(eightStrings.getString(6) == "dsasasdfdfsadfdsas");
    REQUIRE(eightStrings.getString(7) == "asdfdsasd");
}

TEST_CASE("Test Simple Ascending Alphapet Strings") {
    MultiStringsRetriever alphabetStrings = MultiStringsRetriever("simpleMultiStrings.txt");
    REQUIRE(alphabetStrings.getNumStrings() == 26);
    REQUIRE(alphabetStrings.getString(0) == "a");
    for(int i = 0; i < alphabetStrings.getNumStrings(); ++i) {
        REQUIRE(alphabetStrings.getString(i).length() == (i+1));
    }
    REQUIRE(alphabetStrings.getString(25) == "abcdefghijklmnopqrstuvwxyz");
}