/*******************************************************************************************
*              ______                   ______                   _____                     *
*             / _____)                 |  ___ \                 / ___ \       _            *
*            | /  ___  ____  ____ _   _| | _ | | ___ _   _ ____| |   | |_   _| |_          *
*            | | (___)/ _  |/ ___) | | | || || |/ _ \ | | / _  ) |   | | | | |  _)         *
*            | \____/( ( | | |   | |_| | || || | |_| \ V ( (/ /| |___| | |_| | |__         *
*             \_____/ \_||_|_|    \__  |_||_||_|\___/ \_/ \____)\_____/ \____|\___)        *
*                                (____/                                                    *
*                               or any other files are protected. You cannot re-release    * 
*                               anywhere unless you were given permission.                 *
*                           (C) GaryMoveOut 2013. All rights reserved.                     *
********************************************************************************************/

#include "ScriptPCH.h"
#include "Channel.h"

class System_Censure : public PlayerScript
{
    public:
        System_Censure() : PlayerScript("System_Censure") {}

        void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg)
        {
            CheckMessage(player, msg, lang, NULL, NULL, NULL, NULL);
        }

        void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Player* receiver)
        {
            CheckMessage(player, msg, lang, receiver, NULL, NULL, NULL);
        }

        void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Group* group)
        {
            CheckMessage(player, msg, lang, NULL, group, NULL, NULL);
        }

        void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Guild* guild)
        {
            CheckMessage(player, msg, lang, NULL, NULL, guild, NULL);
        }

        void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Channel* channel)
        {
            CheckMessage(player, msg, lang, NULL, NULL, NULL, channel);
        }

    void CheckMessage(Player* player, std::string& msg, uint32 lang, Player* /*receiver*/, Group* /*group*/, Guild* /*guild*/, Channel* channel)
    {
        if (player->IsGameMaster() || lang == LANG_ADDON)
            return;

        // transform to lowercase (for simpler checking)
        std::string lower = msg;
        std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

        const uint8 cheksSize = 38;
        std::string checks[cheksSize];
        // Strony (Sites)
        checks[0] ="http://";
        checks[1] =".com";
        checks[2] =".www";
        checks[3] =".net";
        checks[4] =".org";
        checks[5] =".ru";
        checks[6] ="www.";
        checks[7] ="wow-";
        checks[8] ="-wow";
        checks[9] =".pl";
        // Persian ( farsi )
        checks[10] ="kir";
        checks[11] ="kos";
        checks[12] ="k0s";
        checks[13] ="madar";
        checks[14] ="jende";
        checks[15] ="kooni";
        checks[16] ="kosde";
        checks[17] ="k0sde";
        checks[18] ="nanat";
        checks[19] ="koskesh";
        checks[20] ="k0skesh";
        checks[21] ="wypierdalaj";
        checks[22] ="kutas";
        // English curses
        checks[23] ="bitch";
        checks[24] ="clit";
        checks[25] ="cock";
        checks[26] ="cum";
        checks[27] ="cunt";
        checks[28] ="dick";
        checks[29] ="faggot";
        checks[30] ="fuck";
        checks[31] ="gay";
        checks[32] ="lesbian";
        checks[33] ="penis";
        checks[34] ="prick";
        checks[35] ="slut";
        checks[36] ="twat";
        checks[37] ="whore";

        for (int i = 0; i < cheksSize; ++i)
             if (lower.find(checks[i]) != std::string::npos)
             {
                 msg = "";
                 ChatHandler(player->GetSession()).PSendSysMessage("Tablighat Va Fahashi Mamnoo Mibashad!!!");
                 return;
             }
    }
};

void AddSC_System_Censure()
{
    new System_Censure();
}