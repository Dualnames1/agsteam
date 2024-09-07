//
// AGSteam: Steam API Plugin for AGS
// (C) 2011-2017 MonkeyMoto Productions, Inc.
//
// NOTICE: This file contains references to the Steamworks API. See the included
// LICENSE file for details and restrictions on using this file.
#include "ags2client/IAGS2Client.h"
#include "SteamAchievements.h"
#include "steam/steam_api.h"


using namespace AGSteam::Plugin;

namespace AGSteam
{
    namespace Plugin
    {
        struct SteamAchievements_Statics
        {
        public:
            static SteamAchievements ACHIEVEMENTS;
        };
    }
}

SteamAchievements SteamAchievements_Statics::ACHIEVEMENTS;

SteamAchievements& SteamAchievements::GetSteamAchievements() noexcept
{
    return SteamAchievements_Statics::ACHIEVEMENTS;
}




char const* SteamAchievements::GetTextEntered() const noexcept
{
    
    const uint32 MAX_INPUT_LENGTH = 12 + 1;

    uint32 length = SteamUtils()->GetEnteredGamepadTextLength();
    char szTextInput[MAX_INPUT_LENGTH];
    //*szTextInput = ""+TextInput_content;
    
    bool success = SteamUtils()->GetEnteredGamepadTextInput(szTextInput, length);
    
    
    //strcpy(szTextInput, TextInput_content);

    if (!success) return nullptr;
    else
    {
        //GetAGSEngine()->AbortGame();
        return szTextInput;
    }

    
}



bool SteamAchievements::ShowText(char const *Desc,int charnum, char const *Text) const noexcept
{
	if (!AGS2Client::GetClient()->IsInitialized()) return false;
    
    AGS2Client::GetClient()->SetStatus(false);
    //AGSSteam_SetStatus(true)
    SteamUtils()->ShowFloatingGamepadTextInput(k_EFloatingGamepadTextInputModeModeSingleLine, 0, 0, 640, 360);
        //ShowGamepadTextInput(k_EGamepadTextInputModeNormal, k_EGamepadTextInputLineModeSingleLine, Desc, static_cast<uint32> (charnum), Text);
    SteamAPI_RunCallbacks();
	return true;
	//return SteamUserStats()->StoreStats();
}





bool SteamAchievements::ResetAchievement(char const *ID) const noexcept
{
	if (!AGS2Client::GetClient()->IsInitialized()) return false;
	SteamUserStats()->ClearAchievement(ID);
	return SteamUserStats()->StoreStats();
}

bool SteamAchievements::IsAchievementAchieved(char const *ID) const noexcept
{
	if (!AGS2Client::GetClient()->IsInitialized()) return false; // Steam not initialized, we can't do anything
	bool achieved = false;
	SteamUserStats()->GetAchievement(ID, &achieved);
	return achieved;
}

bool SteamAchievements::SetAchievementAchieved(char const *ID) const noexcept
{
	if (!AGS2Client::GetClient()->IsInitialized()) return false; // Steam not initialized or haven't received call back from Steam yet, so we can't set achievements
	int result = SteamUserStats()->SetAchievement(ID);
	SteamUserStats()->StoreStats();
	SteamAPI_RunCallbacks();
	return (result != 0);
}
