#include "LocalizationManager.h"


int LocalizationManager::InitializeLocalization (InputOutput& io, std::string desiredLanguage = "english-us")
{
	
	XMLManager xml;
	pugi::xml_document doc;
	
	if (xml.ReadFromFileToVector (doc, (io.PathUpLevels (io.GetApplicationPath (), 2) + ("/resources/" + desiredLanguage + ".localized")).c_str ()) == 0)
	{
		
		pugi::xml_node strings = doc.child ("Localization").child ("Strings");
		
		for (pugi::xml_node langString = strings.first_child (); langString; langString = langString.next_sibling ())
		{

			for (pugi::xml_attribute attr = langString.first_attribute (); attr; attr = attr.next_attribute ())
			{

				AddLocalizedString (attr.as_int (), langString.child_value ());
			}
		}
	} else {
		
		return 1;
	}
	
	return 0;
}


void LocalizationManager::AddLocalizedString (int localizedStringIndex, std::string localizedString)
{
	
	localization.insert (std::map<int, std::string>::value_type(localizedStringIndex, localizedString));
}


std::string LocalizationManager::GetLocalizedString (int stringIndex, std::string optionalDefaultString)
{
	
	localizationSearch = localization.find (stringIndex);
	if (localizationSearch != localization.end())
	{
		
		return localizationSearch->second;
	} else {
		
		if (optionalDefaultString != "")
		{

			return ("[LM_ERROR-1 at " + std::to_string (stringIndex) + "] " + optionalDefaultString);
		} else {
		
			return ("LM_ERROR-1: Localized string not found at index " + std::to_string (stringIndex));
		}
	}
}