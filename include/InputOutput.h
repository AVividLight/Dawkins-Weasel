#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H

#include <stdio.h>  /* defines FILENAME_MAX */
#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
 #endif

#include <iostream>
#include <string>


class InputOutput
{
	
public:
	InputOutput ();
	InputOutput (char *argv0); //char** Env);
	
	void SetApplicationPath (std::string executableDirectory); //char** Env);
	std::string GetApplicationPath ();
	
	std::string PathUpLevels (const std::string fullPath, int levels);
	
	template <typename T>
	void SendOutput(T message, bool endline = true);
	
	int AskForInput (std::string& receivingVariable);
	
private:
	std::string applicationPath;
};


#endif //INPUTOUTPUT_H