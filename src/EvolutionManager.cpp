﻿#include "EvolutionManager.h"


const int POPULATION_SIZE = 100;
const int MUTATION_CHANCE = 5;
const bool RESIZE = false;

void EvolutionManager::EvolveToString (const std::string targetString, LocalizationManager &localization)
{
	
	InputOutput io;
	std::string primalString;
	
	
	int PERFECT_FITNESS_SCORE = -1;
	
	if (RESIZE == true)
	{
		
		primalString = "a";
		PERFECT_FITNESS_SCORE = targetString.length () + targetString.length ();
	} else {
		
		primalString = targetString;
		PERFECT_FITNESS_SCORE = targetString.length ();
	}
	
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
	int randomInt = RandomInt (0, 12);
	
	if (randomInt > randomInt / 2)
	{
		
		for (int i = 0; i < newString.length (); i += 1)
		{
		
			newString[i] = Mutate(newString[i], MUTATION_CHANCE);
		}
		
		if (RESIZE == true && RandomInt (0, 100) < MUTATION_CHANCE)
		{
			
			if (randomInt % 2 == 0 && newString.size () > 0)
			{
				
				newString.resize (newString.size () - 1);
			} else {
				
				newString.resize (newString.size () + 1, Mutate ('-', 100));
			}
		}
	}
	
	return newString;
}


char EvolutionManager::Mutate (const char &currentChar, const int mutationChance)
{
	
	if (RandomInt (0, 100) < mutationChance)
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
		
		if (RESIZE)
		{
			
			if (i < targetString.length ())
			{
				
				fitness += 1;
			} else {
				
				fitness -= 1;
			}
		}
	}
	
	return fitness;
}


int EvolutionManager::RandomInt (const int from, const int to)
{
	
	//These should probably be instantiated somewhere else, I have a feeling this is impacting performance
	std::random_device device;
	std::mt19937 generator (device ());
	std::uniform_int_distribution<> distrobution (from, to);
	
	return distrobution (generator);
}