#ifndef SIMILARITY_SOLVER_HPP
#define SIMILARITY_SOLVER_HPP

#include <sstream>

#include "multi-strings-retriever.hpp"

class SimilaritySolver {

    private:
        int numSequences;
        MultiStringsRetriever multiStringsRetriever;

        int calculateLcsLength(
            const std::string& firstSequence,
            const std::string& secondSequence
        );
        char calcucateSimularityMeasure(int firstLen, int secondLen, int lcsLen);

    public:
        SimilaritySolver();
        SimilaritySolver(std::string multiStringsInputFileName);

        char getSimularityMeasure(int firstStringNum, int secondStringNum);
        std::string getSimilarityTable();
        void setMultiStringsRetriever(std::string multiStringsInputFileName);
        int getNumSequences();

};

#endif