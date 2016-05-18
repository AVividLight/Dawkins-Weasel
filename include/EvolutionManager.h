#ifndef EVOLUTIONMANAGER_H
#define EVOLUTIONMANAGER_H

#include <vector>
#include <string>
#include <random>

#include "InputOutput.h"
#include "LocalizationManager.h"


class EvolutionManager
{
	
public:
	void EvolveToString (const std::string targetString, LocalizationManager &localization);
	

private:
	std::random_device m_device;
	std::minstd_rand m_generator;
	std::uniform_int_distribution<> m_distrobution;
	
	void InitializeRandom ();
	
	void CreateInitialString (std::string &primalString);
	void CreatePopulation (std::vector<std::string> &population, const std::string &parentString);
	std::string Reproduce (const std::string &parentString);
	char Mutate (const char &currentChar, const int mutationChance);
	int DetermineFitness (const std::string &childString, const std::string &targetString);
	int RandomInt (int from, int to);
	
};

#endif //EVOLUTIONMANAGER_H