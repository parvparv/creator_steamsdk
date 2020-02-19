#pragma once

#include "steam/steam_api.h"
#pragma comment(lib, "steam_api.lib") 
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std; 
using std::string;
 
class steam_use
{public:
	string steamsta, steamid, language;

	void init_steam() {
		if (SteamAPI_RestartAppIfNecessary(1240840)) { steamsta += " no_steam"; }
		else { steamsta += " yes_steam"; }
		if (SteamAPI_Init()) { steamsta += " yes_init"; }
		else { steamsta += " no_init"; }
		CSteamID steamID = SteamUser()->GetSteamID();
		//steamsta2 = SteamFriends()->GetPersonaName(); 
		 language  =  SteamApps()->GetCurrentGameLanguage(); 
		 steamid = to_string(steamID.ConvertToUint64()) ;
	}


};

