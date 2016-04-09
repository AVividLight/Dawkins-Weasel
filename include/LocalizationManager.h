#ifndef LOCALIZATIONMANAGER_H
#define LOCALIZATIONMANAGER_H

#include <map>
#include <string>

#include "InputOutput.h"
#include "XMLManager.h"


class LocalizationManager
{

public:
	int InitializeLocalization (InputOutput& io, std::string desiredLanguage);
	void AddLocalizedString (int localizedStringIndex, std::string localizedString);
	std::string GetLocalizedString (int stringIndex, std::string optionalDefaultString = "");

private:
	std::map<int, std::string> localization;
	std::map<int, std::string>::iterator localizationSearch;
};

#endif //LOCALIZATIONMANAGER_H

/*

LocalizationManager Error Codes
	0 : Unable to find localization file
	1 : No string found at index (int)

*/