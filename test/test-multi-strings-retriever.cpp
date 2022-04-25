#include "catch/catch.hpp"
#include "../src/multi-strings-retriever.hpp"

#include <iostream>

TEST_CASE("Testing Retrieving Multiple Strings From File") {
    MultiStringsRetriever eightStrings = MultiStringsRetriever("multiStrings.txt");
    REQUIRE(eightStrings.getNumStrings() == 8);
    for(int i = 0; i < eightStrings.getNumStrings(); ++i) {
        std::cout << "String " << i << ": " << eightStrings.getString(i) << std::endl;
    }
}