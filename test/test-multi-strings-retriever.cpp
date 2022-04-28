#include "catch/catch.hpp"
#include "../src/multi-strings-retriever.hpp"

#include <iostream>

TEST_CASE("Testing Retrieving Multiple Strings From File") {
    MultiStringsRetriever eightStrings = MultiStringsRetriever();
    REQUIRE(eightStrings.getNumStrings() == 8);
    REQUIRE(eightStrings.getStr(0) == "asdfdsasdfdsadfdsasdf");
    REQUIRE(eightStrings.getStr(1) == "asdfdsasd");
    REQUIRE(eightStrings.getStr(2) == "asdfdsasdfdsadfdsasdfsdssasadsfsdfsdsfadsfsdassdsfasdsd");
    REQUIRE(eightStrings.getStr(3) == "asdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsd");
    REQUIRE(eightStrings.getStr(4) == "dsasdfsadfdsasdfsdssa");
    REQUIRE(eightStrings.getStr(5) == "asdfdsasdfdsadfdsasdfdsfsdsdssdasasadsfsdsdsfadsfsdassdsfasdsd");
    REQUIRE(eightStrings.getStr(6) == "dsasasdfdfsadfdsas");
    REQUIRE(eightStrings.getStr(7) == "asdfdsasd");
}

TEST_CASE("Test Simple Ascending Alphapet Strings") {
    MultiStringsRetriever alphabetStrings = MultiStringsRetriever("simpleMultiStrings.txt");
    REQUIRE(alphabetStrings.getNumStrings() == 26);
    REQUIRE(alphabetStrings.getStr(0) == "a");
    for(int i = 0; i < 26; ++i) {
        REQUIRE(alphabetStrings.getStr(i).length() == (i+1));
        REQUIRE(alphabetStrings.getStrLen(i) == (i+1));
    }
    REQUIRE(alphabetStrings.getStr(25) == "abcdefghijklmnopqrstuvwxyz");
}