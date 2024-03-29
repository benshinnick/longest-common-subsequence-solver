#ifndef SIMILARITY_SOLVER_HPP
#define SIMILARITY_SOLVER_HPP

#include <sstream>
#include <iomanip>
#include <cmath>

#include "multi-strings-retriever.hpp"

class SimilaritySolver {

    private:
        int numSequences;
        MultiStringsRetriever multiStringsRetriever;

        int calculateLcsLength(
            const std::string& firstSequence,
            const std::string& secondSequence
        );
        char calcucateSimilarityMeasure(int firstLen, int secondLen, int lcsLen);


    public:
        SimilaritySolver();
        SimilaritySolver(std::string multiStringsInputFileName);

        char getSimilarityMeasure(int firstStrNum, int secondStrNum);
        int getLcsLength(int firstStrNum, int secondStrNum);
        std::string getSimilarityTable();
        void setMultiStringsRetriever(std::string multiStringsInputFileName);
        int getNumSequences();

};

#endif