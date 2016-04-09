#include "InputOutput.h"


InputOutput::InputOutput () {}
InputOutput::InputOutput (char *argv0) //char** Env)
{
	
	SetApplicationPath ((std::string) argv0); //Env);
}


void InputOutput::SetApplicationPath (std::string executableDirectory) //char** Env)
{
	
	applicationPath = executableDirectory;
	
	/*int index = 0;
	while (Env[index] != NULL)
	{
		
		if (Env[index][0] == '_' && Env[index][1] == '=')
		{
			
			applicationPath = ((std::string) Env[index]).substr (2, (strlen(Env[index]) - (strlen(Env[index]) - ((std::string) Env[index]).find_last_of ('/'))) - 1);
			break;
		}
		
		index += 1;
	}*/
}


std::string InputOutput::GetApplicationPath ()
{
	
	return applicationPath;
}


std::string InputOutput::PathUpLevels (const std::string fullPath, int levels)
{
	
	std::string appendedString = fullPath;
	
	if (fullPath != (std::string)"")
	{
		
		int index = 0;
		while (index < levels)
		{

			appendedString = appendedString.substr (0, appendedString.length () - 1);
			appendedString = appendedString.substr (0, appendedString.find_last_of ('/') + 1);
			
			index += 1;
		}
	} else {
		
		return (std::string)"";
	}
	
	return appendedString;
}


template <typename T>
void InputOutput::SendOutput(T message, bool endline)
{
	
	std::cout << message;
	
	if (endline)
	{
		
		std::cout << std::endl;
	}
}
template void InputOutput::SendOutput<std::string> (std::string message, bool endline);
template void InputOutput::SendOutput<const char*> (const char* message, bool endline);
template void InputOutput::SendOutput<char*> (char* message, bool endline);
template void InputOutput::SendOutput<int> (int message, bool endline);


int InputOutput::AskForInput (std::string& receivingVariable)
{
	
	getline (std::cin, receivingVariable);
	
	return 0;
}