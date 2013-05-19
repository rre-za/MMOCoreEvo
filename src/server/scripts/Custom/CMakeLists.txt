# Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  Custom/hunterpet_vendor.cpp
  Custom/Transmogrification.cpp
  Custom/Transmogrification.h
  Custom/chat_censure.cpp
  Custom/npc_arena_team_top.cpp
  Custom/mod_MultiKill.cpp
  Custom/npc_maniek.cpp
  Custom/npc_mmr_reset.cpp
  Custom/npc_shop.cpp
  Custom/npc_customize.cpp      
  Custom/arena_fast_start.cpp
  Custom/cs_fake.cpp
  Custom/ArenaSpectate.cpp
  Custom/channel_factions.cpp
  Custom/resetduel.cpp  
  #Custom/killstreak_pvp_system.cpp  
  Custom/item_custom_stone.cpp  
  #Custom/item_requester.cpp
  Custom/allinone.cpp
  Custom/professionnpc.cpp
  #Custom/npc_lottery.cpp
  Custom/npcs_mini_boss.cpp  
  Custom/guildhouse_npc.cpp    
  Custom/level_rewards.cpp  
  Custom/npc_legion_master.cpp
  Custom/event_npc.cpp
  Custom/npc_vip.cpp  
  Custom/levelnpc.cpp    
  Custom/npc_teleport.cpp
)

message("  -> Prepared: Custom")
