#include "LocalizationManager.h" 
#include "EvolutionManager.h"

int main(int argc, char* argv[]) //, char* Env[])
{
	
	InputOutput io(argv[0]); //Env);
	LocalizationManager localization;
	EvolutionManager evolutionManager;
	
	
	const bool DEBUG_PATH = false;
	if (DEBUG_PATH)
	{
		
		io.SendOutput ("\nApplication path: ", false);
		io.SendOutput (io.GetApplicationPath ());
	
		io.SendOutput ("\nPath up 1 levels: ", false);
		io.SendOutput (io.PathUpLevels (io.GetApplicationPath (), 1));
	}
	
	
	io.SendOutput ("");
	if (localization.InitializeLocalization (io, "english-us") != 0)
	{
		
		io.SendOutput ("LM_ERROR-0: Unable to parse localization file!");
	}
	
	io.SendOutput (localization.GetLocalizedString (1, "Please enter a target string: "), false);

	std::string targetString = "";
	if (io.AskForInput(targetString) != 0)
	{
		
		io.SendOutput (localization.GetLocalizedString (2, "Error in AskForInput!"));
		return 1;
	} else {
		
		evolutionManager.EvolveToString (targetString, localization);
	}
	
	return 0;
}
