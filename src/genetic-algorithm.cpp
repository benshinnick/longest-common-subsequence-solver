#include "genetic-algorithm.hpp"

void GeneticAlgorithm::setInitialGeneration() {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd());

    Tour initialTour = Tour(numOfCities, gen, startEndCity);
    int numInitialMutationSwaps = 5;
    //First generation made up of mutated tours
    for(int i = 0; i < generationSize; ++i) {
        currGeneration[i] = initialTour.getNewMutatedTour(numInitialMutationSwaps);
    }
}

void GeneticAlgorithm::setNextGeneration() {
    int i;
    int numEliteMutationSwaps = 1, numMutationSwaps = 2;
    if(numOfCities > 11) numMutationSwaps = 4;
    
    currGeneration[0] = elite;
    for(i = 1; i < numMutationsInGeneration+1; ++i) {
        if(i % 3 == 0) currGeneration[i] = elite.getNewMutatedTour(numEliteMutationSwaps);
        else currGeneration[i].setToNewMutatedTour(numMutationSwaps);
    }
    if(i < generationSize) {
        currGeneration[i] = elite.getNextPermutedTour();
        i++;
    }
    for(; i < generationSize; ++i) {
        currGeneration[i].setToNextPermutedTour();
    }
}

void GeneticAlgorithm::updateElite() {
    Tour foundElite = currGeneration[0];
    for(int i = 0; i < generationSize; ++i) {
        if(foundElite.getTourCost() > currGeneration[i].getTourCost())
            foundElite = currGeneration[i];
    }
    elite = foundElite;
}

GeneticAlgorithm::GeneticAlgorithm(int numCities, int startEndCity, int genSize, int numGensToRun, float mutatedGenPercent) {
    this->numOfCities = numCities;
    this->startEndCity = startEndCity;
    this->generationSize = genSize;
    this->numGenerationsToRun = numGensToRun;
    this->numMutationsInGeneration = (int) (mutatedGenPercent * genSize);
    this->currGeneration.resize(genSize);
    
    setInitialGeneration();
    updateElite();
}

void GeneticAlgorithm::runGeneticAlgorithm() {
    for(int i = 0; i < numGenerationsToRun - 1; ++i) {
        setNextGeneration();
        updateElite();
    }
}

double GeneticAlgorithm::getLowestFoundTourCost() {
    return elite.getTourCost();
}

double GeneticAlgorithm::getPercentOptimal(double optimalTourCost)  {
    return getLowestFoundTourCost()/optimalTourCost * 100;
}

Tour GeneticAlgorithm::getElite() {
    return elite;
}