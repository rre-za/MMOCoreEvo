/*

- Made by mthsena -

REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES('900003','0','0','0','0','0','23810','0','0','0','Useful Master','- by mthsena -',NULL,'0','80','80','0','35','35','1','1','1.14286','2','3','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','1','1','1','1','0','0','0','0','0','0','0','0','1','0','0','0','Useful_Master','1');

*/
#include "ScriptPCH.h"

class Useful_Master : public CreatureScript
{
public:
	Useful_Master() : CreatureScript("Useful_Master") { }

	bool OnGossipHello(Player *player, Creature *creature)
	{
		player->ADD_GOSSIP_ITEM_EXTENDED(0,"[Reset Cooldowns]",GOSSIP_SENDER_MAIN,1,"Are you sure?",0,false);
		player->ADD_GOSSIP_ITEM_EXTENDED(0,"[Reset Instances]",GOSSIP_SENDER_MAIN,2,"Are you sure?",0,false);
		player->ADD_GOSSIP_ITEM(4,"Close Window.",GOSSIP_SENDER_MAIN,3);

		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());         
		return true;
	}

	bool OnGossipSelect(Player *player, Creature *creature, uint32 sender, uint32 uiAction)
	{
		int8 diff = -1;
		uint16 MapId = 0;

		if (sender == GOSSIP_SENDER_MAIN)
		{
			player->PlayerTalkClass->ClearMenus();
			switch(uiAction)
			{
			case 1:// [Reset Cooldowns]
				player->RemoveAllSpellCooldown();
				creature->MonsterWhisper("Your cooldowns were cleaned!", player->GetGUID());
				player->CLOSE_GOSSIP_MENU();
				break;

			case 2:// [Reset Instances]
				for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
				{
					Player::BoundInstancesMap &binds = player->GetBoundInstances(Difficulty(i));
					for (Player::BoundInstancesMap::iterator itr = binds.begin(); itr != binds.end();)
					{
						player->UnbindInstance(itr, Difficulty(i));
					}
				}
				creature->MonsterWhisper("Your instances were cleaned!", player->GetGUID());
				player->CLOSE_GOSSIP_MENU();
				break;

			case 3:// Close Window
				player->CLOSE_GOSSIP_MENU();
				break; 
			}
		}
		return true;
	}
};

void AddSC_Useful_Master()
{
	new Useful_Master();
}