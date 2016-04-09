#include "EvolutionManager.h"


const int POPULATION_SIZE = 100;
const int MUTATION_CHANCE = 5;

void EvolutionManager::EvolveToString (const std::string targetString, LocalizationManager &localization)
{
	
	const int PERFECT_FITNESS_SCORE = targetString.length ();
	
	InputOutput io;
	std::string primalString = targetString;
	CreateInitialString (primalString);

	io.SendOutput (localization.GetLocalizedString (5, "Primal string: "), false);
	io.SendOutput (primalString);
	
	std::vector<std::string> population (POPULATION_SIZE, "");
	CreatePopulation (population, primalString);
	
	
	int generation = 0;

	int mostFitFitness = 0;
	std::string mostFitString = population.at (0);
	
	int bestFitness = -1;
	std::string bestString = "";
	
	while (mostFitFitness != PERFECT_FITNESS_SCORE)
	{
		
		generation += 1;
		
		if (mostFitFitness < bestFitness)
		{
			
			mostFitString = bestString;
		} else {
			
			bestFitness = mostFitFitness;
			bestString = mostFitString;
		}
		
		CreatePopulation (population, mostFitString);

		mostFitFitness = -1;
	
		for (int i = 0; i < POPULATION_SIZE; i += 1)
		{
			
			if (DetermineFitness (population.at (i), targetString) > mostFitFitness)
			{

				mostFitString = population.at (i);
				mostFitFitness = DetermineFitness (population.at (i), targetString);
			}
		}

		io.SendOutput (localization.GetLocalizedString (6, "At generation "), false);
		io.SendOutput (generation, false);
		io.SendOutput (localization.GetLocalizedString (7, ", most fit string '"), false);
		io.SendOutput ("", false);
		io.SendOutput (mostFitString, false);
		io.SendOutput (localization.GetLocalizedString (8, "' has fitness: "), false);
		io.SendOutput (mostFitFitness);
	}
	
	io.SendOutput ("");
	io.SendOutput (localization.GetLocalizedString (9, "Evolved to '"), false);
	io.SendOutput (mostFitString, false);
	io.SendOutput (localization.GetLocalizedString (10, "' in "), false);
	io.SendOutput (generation, false);
	io.SendOutput (localization.GetLocalizedString (11, " generations, with a "), false);
	io.SendOutput (MUTATION_CHANCE, false);
	io.SendOutput (localization.GetLocalizedString (12, "/100 mutation chance."));
	io.SendOutput ("");
}


void EvolutionManager::CreateInitialString (std::string &primalString)
{
	
	for (int i = 0; i < primalString.length (); i += 1)
	{
		
		primalString[i] = (char)RandomInt (32, 126);
	}
}


void EvolutionManager::CreatePopulation (std::vector<std::string> &population, const std::string &parentString)
{
	
	for (int i = 0; i < population.size (); i += 1)
	{
		
		population.at (i) = Reproduce (parentString);
	}
}


std::string EvolutionManager::Reproduce (const std::string &parentString)
{
	
	std::string newString = parentString;
	
	for (int i = 0; i < newString.length (); i += 1)
	{
		
		newString[i] = Mutate(newString[i], MUTATION_CHANCE);
	}
	
	return newString;
}


char EvolutionManager::Mutate (const char &currentChar, const int MUTATION_CHANCE)
{
	
	if (RandomInt (0, 100) < MUTATION_CHANCE)
	{
		
		return (char)RandomInt (32, 126);
	}
	
	return currentChar;
}


int EvolutionManager::DetermineFitness (const std::string &childString, const std::string &targetString)
{
	
	int fitness = 0;
	
	for (int i = 0; i < childString.length (); i += 1)
	{
		
		if (childString[i] == targetString[i])
		{
			
			fitness += 1;
		}
	}
	
	return fitness;
}


int EvolutionManager::RandomInt (const int from, const int to)
{
	
	std::random_device device;
	std::mt19937 generator (device ());
	std::uniform_int_distribution<> distrobution (from, to);
	
	return distrobution (generator);
}


/*
Outline for Evolution Algorithm
	Via https://en.wikipedia.org/wiki/Weasel_program

	0. Start with a random string
	1. Make 100 copies of the string (reproduce)
	2. For each character in each of the 100 copies, with a probability of 5%, replace (mutate) the character with a new random character.
	3. Compare each new string with the target string "METHINKS IT IS LIKE A WEASEL", and give each a score (the number of letters in the string that are correct and in the correct position).
	4. If any of the new strings has a perfect score (28), halt. Otherwise, take the highest scoring string, and go to step 2.
*/