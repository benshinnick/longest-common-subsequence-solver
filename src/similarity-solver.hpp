#ifndef SIMILARITY_SOLVER_HPP
#define SIMULARITY_SOLVER_HPP

#include <sstream>

#include "multi-strings-retriever.hpp"

class SimilaritySolver {

    private:
        int numStrings;
        MultiStringsRetriever sequenceRetriever;

        int calculateLcsLength(
            const std::string& firstSequence,
            const std::string& secondSequence
        );
        char calucateSimularityMeasure();


    public:
        SimilaritySolver();
        SimilaritySolver(std::string multiStringsInputFileName);

        char getSimularityMeasure(
            const std::string& firstSequence,
            const std::string& secondSequence
        );
        std::string getSimilarityTable();
        void setSequenceRetriever(std::string multiStringsInputFileName);
};

#endif