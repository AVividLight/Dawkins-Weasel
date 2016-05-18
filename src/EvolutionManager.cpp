#include "EvolutionManager.h"


const int POPULATION_SIZE = 100; //Number of strings to be created each generation
const int MUTATION_CHANCE = 5; //Chance that a character will randomly change
const bool RESIZE = false; //Defines whether the string will additionally have to mutate to the length of the target string

void EvolutionManager::EvolveToString (const std::string targetString, LocalizationManager &localization)
{
	
	InputOutput io;
	std::string primalString;
	
	
	int perfectFitnessScore = -1;

	if (RESIZE == true)
	{
		
		primalString = "a";
		perfectFitnessScore = targetString.length () + targetString.length ();
	} else {
		
		primalString = targetString;
		perfectFitnessScore = targetString.length ();
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
	
	while (mostFitFitness != perfectFitnessScore)
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


void EvolutionManager::CreateInitialString (std::string &primalString) //Combine with following function?
{
	
	for (int i = 0; i < primalString.length (); i += 1)
	{
		
		primalString[i] = (char)RandomInt (32, 126); //Call to RANDOMINT
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
	int randomInt = RandomInt (0, 12); // RANDOMINT
	
	if (randomInt > randomInt / 2)
	{
		
		for (int i = 0; i < newString.length (); i += 1)
		{
		
			newString[i] = Mutate(newString[i], MUTATION_CHANCE);
		}
		
		if (RESIZE == true && RandomInt (0, 100) < MUTATION_CHANCE) //Call to RANDOMINT
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
	
	if (RandomInt (0, 100) < mutationChance) //Call to RANDOMINT
	{
		
		return (char)RandomInt (32, 126); //Call to RANDOMINT
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
		
		if (RESIZE == true)
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


void EvolutionManager::InitializeRandom ()
{
	
	m_generator = std::minstd_rand (m_device ());
}


int EvolutionManager::RandomInt (const int from, const int to)
{

	m_distrobution = std::uniform_int_distribution<> (from, to);
	return m_distrobution (m_generator);
}
