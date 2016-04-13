#ifndef EVOLUTIONMANAGER_H
#define EVOLUTIONMANAGER_H

#include <random>

#include <vector>
#include <string>

#include "InputOutput.h"
#include "LocalizationManager.h"


class EvolutionManager
{
	
public:
	void EvolveToString (const std::string targetString, LocalizationManager &localization);
	

private:
	void CreateInitialString (std::string &primalString);
	void CreatePopulation (std::vector<std::string> &population, const std::string &parentString);
	std::string Reproduce (const std::string &parentString);
	char Mutate (const char &currentChar, const int mutationChance);
	int DetermineFitness (const std::string &childString, const std::string &targetString);
	int RandomInt (int from, int to);
	
};

#endif //EVOLUTIONMANAGER_H