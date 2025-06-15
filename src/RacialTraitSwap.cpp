/*
 *MIT License
 *
 *Copyright (c) 2023 Azerothcore
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy
 *of this software and associated documentation files (the "Software"), to deal
 *in the Software without restriction, including without limitation the rights
 *to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *copies of the Software, and to permit persons to whom the Software is
 *furnished to do so, subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all
 *copies or substantial portions of the Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *SOFTWARE.
 *
 * Racial Traits Swap NPC For Azerothcore Custom Changes Branch
 * Written by SPP DEV MDIC
 * SQL Assistance by Nemesis Dev Jinnai
 * Modified for Azerothcore
 */

#include "Chat.h"
#include "Config.h"
#include "Creature.h"
#include "GameEventMgr.h"
#include "Item.h"
#include "ItemEnchantmentMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "WorldSession.h"

#define LOCALE_RACESWAP_4 "种族特质交换"

#define LOCALE_EXIT_4 "[再见]"

#define LOCALE_BACK_4 "[返回]"

#define LOCALE_GOLD_4 " 金."

// female icons
#define LOCALE_BES_4 "|TInterface\\icons\\Achievement_Character_Bloodelf_Female:25|t血精灵种族特质交换 -"

// male icons
#define LOCALE_BES_13 "|TInterface\\icons\\Achievement_Character_Bloodelf_Male:25|t血精灵种族特质交换 -"

// female icons
#define LOCALE_DRS_4 "|TInterface\\icons\\Achievement_Character_Draenei_Female:25|t德萊尼种族特质交换 -"

// male icons
#define LOCALE_DRS_13 "|TInterface\\icons\\Achievement_Character_Draenei_Male:25|t德萊尼种族特质交换 -"

// female icons
#define LOCALE_DWS_4 "|TInterface\\icons\\Achievement_Character_Dwarf_Female:25|t矮人种族特质交换 -"

// male icons
#define LOCALE_DWS_13 "|TInterface\\icons\\Achievement_Character_Dwarf_Male:25|t矮人种族特质交换 -"

// female icons
#define LOCALE_GNS_4 "|TInterface\\icons\\Achievement_Character_Gnome_Female:25|t侏儒种族特质交换 -"

// male icons
#define LOCALE_GNS_13 "|TInterface\\icons\\Achievement_Character_Gnome_Male:25|t侏儒种族特质交换 -"

// female icons
#define LOCALE_HUS_4 "|TInterface\\icons\\Achievement_Character_Human_Female:25|t人类种族特质交换 -"

// male icons
#define LOCALE_HUS_13 "|TInterface\\icons\\Achievement_Character_Human_Male:25|t人类种族特质交换 -"

// female icons
#define LOCALE_NES_4 "|TInterface\\icons\\Achievement_Character_Nightelf_Female:25|t暗夜精灵种族特质交换 -"

// male icons
#define LOCALE_NES_13 "|TInterface\\icons\\Achievement_Character_Nightelf_Male:25|t暗夜精灵种族特质交换 -"

// female icons
#define LOCALE_ORC_4 "|TInterface\\icons\\Achievement_Character_Orc_Female:25|t兽人种族特质交换 -"

// male icons
#define LOCALE_ORC_13 "|TInterface\\icons\\Achievement_Character_Orc_Male:25|t兽人种族特质交换 -"

// female icons
#define LOCALE_TUR_4 "|TInterface\\icons\\Achievement_Character_Tauren_Female:25|t牛头人种族特质交换 -"

// male icons
#define LOCALE_TUR_13 "|TInterface\\icons\\Achievement_Character_Tauren_Male:25|t牛头人种族特质交换 -"

// female icons
#define LOCALE_TRL_4 "|TInterface\\icons\\Achievement_Character_Troll_Female:25|t巨魔种族特质交换 -"

// male icons
#define LOCALE_TRL_13 "|TInterface\\icons\\Achievement_Character_Troll_Male:25|t巨魔种族特质交换 -"

// female icons
#define LOCALE_UND_4 "|TInterface\\icons\\Achievement_Character_Undead_Female:25|t亡灵种族特质交换 -"

// male icons
#define LOCALE_UND_13 "|TInterface\\icons\\Achievement_Character_Undead_Male:25|t亡灵种族特质交换 -"

// New Function - remove all existing racials
void RemoveAllRacials(Player* player)
{
    // Draenei:
    player->removeSpell(28875, SPEC_MASK_ALL, false); // unlearn Gemcutting
    player->removeSpell(6562, SPEC_MASK_ALL, false);  // unlearn Heroic Presence (Warrior, Paladin, Hunter, DK)
    player->removeSpell(28878, SPEC_MASK_ALL, false); // unlearn Heroic Presence (Priest, Shaman)
    player->removeSpell(28880, SPEC_MASK_ALL, false); // unlearn Gift of Naaru (Warrior, increased by AP)
    player->removeSpell(59542, SPEC_MASK_ALL, false); // unlearn Gift of Naaru (Paladin, increase by AP or SP, whichever is higher)
    player->removeSpell(59543, SPEC_MASK_ALL, false); // unlearn Gift of Naaru (Hunter, increase by AP)
    player->removeSpell(59544, SPEC_MASK_ALL, false); // unlearn Gift of Naaru (Priest, increase by SP)
    player->removeSpell(59545, SPEC_MASK_ALL, false); // unlearn Gift of Naaru (DK, increased by AP)
    player->removeSpell(59547, SPEC_MASK_ALL, false); // unlearn Gift of Narru (Shaman, increase by AP or SP, whichever is higher)
    player->removeSpell(59548, SPEC_MASK_ALL, false); // unlearn Gift of Naaru (Mage, increase by SP)
    player->removeSpell(59221, SPEC_MASK_ALL, false); // unlearn Shadow Resistance (Warrior)
    player->removeSpell(59535, SPEC_MASK_ALL, false); // unlearn Shadow Resistance (Paladin)
    player->removeSpell(59536, SPEC_MASK_ALL, false); // unlearn Shadow Resistance (Hunter)
    player->removeSpell(59538, SPEC_MASK_ALL, false); // unlearn Shadow Resistance (Priest)
    player->removeSpell(59539, SPEC_MASK_ALL, false); // unlearn Shadow Resistance (DK)
    player->removeSpell(59540, SPEC_MASK_ALL, false); // unlearn Shadow Resistance (Shaman)
    player->removeSpell(59541, SPEC_MASK_ALL, false); // unlearn Shadow Resistance (Mage)

    // Dwarf:
    player->removeSpell(2481, SPEC_MASK_ALL, false);  // unlearn Find Treasure
    player->removeSpell(20596, SPEC_MASK_ALL, false); // unlearn Frost Resistance
    player->removeSpell(20595, SPEC_MASK_ALL, false); // unlearn Gun Specialization
    player->removeSpell(59224, SPEC_MASK_ALL, false); // unlearn Mace Specialization
    player->removeSpell(20594, SPEC_MASK_ALL, false); // unlearn Stoneform

    // Gnome:
    player->removeSpell(20592, SPEC_MASK_ALL, false); // unlearn Arcane Resistance
    player->removeSpell(20593, SPEC_MASK_ALL, false); // unlearn Engineering Specialization
    player->removeSpell(20589, SPEC_MASK_ALL, false); // unlearn Escape Artist
    player->removeSpell(20591, SPEC_MASK_ALL, false); // unlearn Expansive Mind

    // Human:
    player->removeSpell(20599, SPEC_MASK_ALL, false); // unlearn Diplomacy
    player->removeSpell(59752, SPEC_MASK_ALL, false); // unlearn Every man for himself
    player->removeSpell(20864, SPEC_MASK_ALL, false); // unlearn Mace Specialization
    player->removeSpell(58985, SPEC_MASK_ALL, false); // unlearn Perception
    player->removeSpell(20597, SPEC_MASK_ALL, false); // unlearn Sword Specialization
    player->removeSpell(20598, SPEC_MASK_ALL, false); // unlearn The Human Spirit

    // Night Elf:
    player->removeSpell(20583, SPEC_MASK_ALL, false); // unlearn Nature Resistance
    player->removeSpell(20582, SPEC_MASK_ALL, false); // unlearn Quickness
    player->removeSpell(58984, SPEC_MASK_ALL, false); // unlearn Shadowmeld
    player->removeSpell(20585, SPEC_MASK_ALL, false); // unlearn Wisp Spirit
    player->removeSpell(21009, SPEC_MASK_ALL, false); // unlearn Elusiveness

    // Orc:
    player->removeSpell(20574, SPEC_MASK_ALL, false); // unlearn Axe Specialization
    player->removeSpell(20573, SPEC_MASK_ALL, false); // unlearn Hardiness
    player->removeSpell(54562, SPEC_MASK_ALL, false); // unlearn Command (DK)
    player->removeSpell(20576, SPEC_MASK_ALL, false); // unlearn Command (Hunter)
    player->removeSpell(65222, SPEC_MASK_ALL, false); // unlearn Command (Shaman)
    player->removeSpell(20575, SPEC_MASK_ALL, false); // unlearn Command (Warlock)
    player->removeSpell(21563, SPEC_MASK_ALL, false); // unlearn Command (non-pet class)
    player->removeSpell(20572, SPEC_MASK_ALL, false); // unlearn Blood Fury (AP only)
    player->removeSpell(33697, SPEC_MASK_ALL, false); // unlearn Blood fury (AP + SP)
    player->removeSpell(33702, SPEC_MASK_ALL, false); // unlearn Blood Fury (SP only)

    // Tauren:
    player->removeSpell(20552, SPEC_MASK_ALL, false); // unlearn Cultivation
    player->removeSpell(20550, SPEC_MASK_ALL, false); // unlearn Endurance
    player->removeSpell(20551, SPEC_MASK_ALL, false); // unlearn Nature Resistance
    player->removeSpell(20549, SPEC_MASK_ALL, false); // unlearn Warstomp

    // Troll:
    player->removeSpell(20557, SPEC_MASK_ALL, false); // unlearn Beast Slaying
    player->removeSpell(26297, SPEC_MASK_ALL, false); // unlearn Berserking
    player->removeSpell(26290, SPEC_MASK_ALL, false); // unlearn Bow Specialization
    player->removeSpell(20558, SPEC_MASK_ALL, false); // unlearn Throwing Specialization
    player->removeSpell(58943, SPEC_MASK_ALL, false); // unlearn Da Voodoo Shuffle
    player->removeSpell(20555, SPEC_MASK_ALL, false); // unlearn Regeneration

    // Undead:
    player->removeSpell(20577, SPEC_MASK_ALL, false); // unlearn Cannibalize
    player->removeSpell(20579, SPEC_MASK_ALL, false); // unlearn Shadow Resistance
    player->removeSpell(5227, SPEC_MASK_ALL, false);  // unlearn Underwater Breating
    player->removeSpell(7744, SPEC_MASK_ALL, false);  // unlearn Will of the Forsaken

    // Blood Elf:
    player->removeSpell(28877, SPEC_MASK_ALL, false); // unlearn Arcane Affinity
    player->removeSpell(28730, SPEC_MASK_ALL, false); // unlearn Arcane Torrent (mana)
    player->removeSpell(25046, SPEC_MASK_ALL, false); // unlearn Arcane Torrent (energy)
    player->removeSpell(50613, SPEC_MASK_ALL, false); // unlearn Arcane Torrent (runic power)
    player->removeSpell(822, SPEC_MASK_ALL, false);   // unlearn Magic Resistance
}

class Azerothcore_Race_Trait_announce : public PlayerScript
{
public:
    Azerothcore_Race_Trait_announce() : PlayerScript("Azerothcore_Race_Trait_announce") { }

    void OnPlayerLogin(Player* Player)
    {
		uint32 loc = Player->GetSession()->GetSessionDbLocaleIndex();
        if (sConfigMgr->GetOption<bool>("Azerothcore.Racial.Trait.Swap.Announce.enable", true))
            if (loc == 4)
                ChatHandler(Player->GetSession()).SendSysMessage("|cff00ff00本服务端已加载|r |cff00ccff种族特质交换 |r|cff00ff00模块.|r");
            else
                ChatHandler(Player->GetSession()).SendSysMessage("This server is running the |cff4CFF00Azerothcore Racial Trait Swap NPC |rmodule.");
    }
};

class npc_race_trait_swap : public CreatureScript
{
public:
    npc_race_trait_swap() : CreatureScript("npc_race_trait_swap") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        char const* localizedEntry;
        switch (player->GetSession()->GetSessionDbcLocale())
        {            
            case LOCALE_zhCN:
                localizedEntry = LOCALE_RACESWAP_4;
                break;
            default:
                localizedEntry = LOCALE_RACESWAP_4;
        }
        AddGossipItemFor(player, GOSSIP_ICON_TRAINER, localizedEntry, GOSSIP_SENDER_MAIN, 11);
        SendGossipMenuFor(player, 98888, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*menuId*/, uint32 gossipListId) override
    {
        int32 const RTS1 = sConfigMgr->GetOption<int32>("Racial.Traits.Swap.Gold", 100);

        char const* localizedExit = {};
        char const* localizedBack = {};
        char const* localizedGold = {};
        char const* localizedBES = {};
        char const* localizedDRS = {};
        char const* localizedDWS = {};
        char const* localizedGNS = {};
        char const* localizedHUS = {};
        char const* localizedNES = {};
        char const* localizedORC = {};
        char const* localizedTUR = {};
        char const* localizedTRL = {};
        char const* localizedUND = {};

        switch (player->GetSession()->GetSessionDbcLocale())
        {            
            case LOCALE_zhCN:
                localizedExit = LOCALE_EXIT_4;
                localizedBack = LOCALE_BACK_4;
                localizedGold = LOCALE_GOLD_4;
                break;
            default:
                localizedExit = LOCALE_EXIT_4;
                localizedBack = LOCALE_BACK_4;
                localizedGold = LOCALE_GOLD_4;
        }

        if (player->getGender() == GENDER_FEMALE)
        {
            switch (player->GetSession()->GetSessionDbcLocale())
            {
                case LOCALE_zhCN:
                    localizedBES = LOCALE_BES_4;
                    localizedDRS = LOCALE_DRS_4;
                    localizedDWS = LOCALE_DWS_4;
                    localizedGNS = LOCALE_GNS_4;
                    localizedHUS = LOCALE_HUS_4;
                    localizedNES = LOCALE_NES_4;
                    localizedORC = LOCALE_ORC_4;
                    localizedTUR = LOCALE_TUR_4;
                    localizedTRL = LOCALE_TRL_4;
                    localizedUND = LOCALE_UND_4;
                    break;
                default:
                    localizedBES = LOCALE_BES_4;
                    localizedDRS = LOCALE_DRS_4;
                    localizedDWS = LOCALE_DWS_4;
                    localizedGNS = LOCALE_GNS_4;
                    localizedHUS = LOCALE_HUS_4;
                    localizedNES = LOCALE_NES_4;
                    localizedORC = LOCALE_ORC_4;
                    localizedTUR = LOCALE_TUR_4;
                    localizedTRL = LOCALE_TRL_4;
                    localizedUND = LOCALE_UND_4;
            }
        }
        else if (player->getGender() == GENDER_MALE)
        {
            switch (player->GetSession()->GetSessionDbcLocale())
            {
                case LOCALE_zhCN:
                    localizedBES = LOCALE_BES_13;
                    localizedDRS = LOCALE_DRS_13;
                    localizedDWS = LOCALE_DWS_13;
                    localizedGNS = LOCALE_GNS_13;
                    localizedHUS = LOCALE_HUS_13;
                    localizedNES = LOCALE_NES_13;
                    localizedORC = LOCALE_ORC_13;
                    localizedTUR = LOCALE_TUR_13;
                    localizedTRL = LOCALE_TRL_13;
                    localizedUND = LOCALE_UND_13;
                    break;
                default:
                    localizedBES = LOCALE_BES_13;
                    localizedDRS = LOCALE_DRS_13;
                    localizedDWS = LOCALE_DWS_13;
                    localizedGNS = LOCALE_GNS_13;
                    localizedHUS = LOCALE_HUS_13;
                    localizedNES = LOCALE_NES_13;
                    localizedORC = LOCALE_ORC_13;
                    localizedTUR = LOCALE_TUR_13;
                    localizedTRL = LOCALE_TRL_13;
                    localizedUND = LOCALE_UND_13;
            }
        }

        std::ostringstream messageBE;
        messageBE << localizedBES << RTS1 << localizedGold;
        std::ostringstream messageDR;
        messageDR << localizedDRS << RTS1 << localizedGold;
        std::ostringstream messageDW;
        messageDW << localizedDWS << RTS1 << localizedGold;
        std::ostringstream messageGN;
        messageGN << localizedGNS << RTS1 << localizedGold;
        std::ostringstream messageHU;
        messageHU << localizedHUS << RTS1 << localizedGold;
        std::ostringstream messageNE;
        messageNE << localizedNES << RTS1 << localizedGold;
        std::ostringstream messageOR;
        messageOR << localizedORC << RTS1 << localizedGold;
        std::ostringstream messageTA;
        messageTA << localizedTUR << RTS1 << localizedGold;
        std::ostringstream messageTR;
        messageTR << localizedTRL << RTS1 << localizedGold;
        std::ostringstream messageUN;
        messageUN << localizedUND << RTS1 << localizedGold;

        ClearGossipMenuFor(player);

        switch (gossipListId)
        {
            case 11:
                if (player)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, messageBE.str(), GOSSIP_SENDER_MAIN, 1); // Blood Elf Selection
                    AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, messageDR.str(), GOSSIP_SENDER_MAIN, 2); // Draenei Selection
                    AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, messageDW.str(), GOSSIP_SENDER_MAIN, 3); // Dwarves Selection
                    AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, messageGN.str(), GOSSIP_SENDER_MAIN, 4); // Gnome Selection
                    AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, messageHU.str(), GOSSIP_SENDER_MAIN, 5); // Human Selection
                    AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, messageNE.str(), GOSSIP_SENDER_MAIN, 6); // Night Elf Selection
                    AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, messageOR.str(), GOSSIP_SENDER_MAIN, 7); // Orc Selection
                    AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, messageTA.str(), GOSSIP_SENDER_MAIN, 8); // Tauren Selection
                    AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, messageTR.str(), GOSSIP_SENDER_MAIN, 9); // Troll Selection
                    AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, messageUN.str(), GOSSIP_SENDER_MAIN, 10); // Undead
                    AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedExit, GOSSIP_SENDER_MAIN, 1111);
                    SendGossipMenuFor(player, 98888, creature->GetGUID());
                }
                break;

            case 1111: // close
                CloseGossipMenuFor(player);
                break;

            case 1: // Blood Elf Selection
                AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "致力于血精灵的荣耀", GOSSIP_SENDER_MAIN, 112);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedBack, GOSSIP_SENDER_MAIN, 11);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedExit, GOSSIP_SENDER_MAIN, 1111);
                SendGossipMenuFor(player, 988881, creature->GetGUID());
                break;

            case 112: // Blood Elf
                CloseGossipMenuFor(player);
                if (!player->HasEnoughMoney(RTS1 * GOLD)) // gold check
                    return true;
                player->ModifyMoney(-RTS1 * GOLD); // Deducting the money if check passes
                player->CastSpell(player, 47292); // Level up visual effect to let you know the transaction did occure and money is deducted
                RemoveAllRacials(player); // Remove all racials
                player->learnSpell(28877, false); // Arcane Affinity
                player->learnSpell(822, false); // Magic Resistance
                // Arcane Torrent
                // NOTE: Druid will get 2 versions of Arcane Torrent since they can use both Energy and Mana. If the custom version of Arcane Torrent is added, the druid will also need to pick that up.
                switch (player->getClass())
                {
                    case CLASS_DEATH_KNIGHT:
                    case CLASS_WARRIOR:
                        player->learnSpell(50613, false); // Arcane Torrent
                        break;
                    case CLASS_HUNTER:
                    case CLASS_MAGE:
                    case CLASS_PALADIN:
                    case CLASS_PRIEST:
                    case CLASS_SHAMAN:
                    case CLASS_WARLOCK:
                        player->learnSpell(28730, false); // Arcane Torrent (Mana)
                        break;
                    case CLASS_ROGUE:
                        player->learnSpell(25046, false); // Arcane Torrent (Energy)
                        break;
                    case CLASS_DRUID:
                        player->learnSpell(28730, false); // Arcane Torrent (Mana)
                        player->learnSpell(25046, false); // Arcane Torrent (Energy)
                        break;
                }
                break;

            case 2: // Draenei Selection
                AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "致力于德莱尼的圣光事业", GOSSIP_SENDER_MAIN, 212);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedBack, GOSSIP_SENDER_MAIN, 11);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedExit, GOSSIP_SENDER_MAIN, 1111);
                SendGossipMenuFor(player, 988882, creature->GetGUID());
                break;

            case 212: // Draenei
                CloseGossipMenuFor(player);
                if (!player->HasEnoughMoney(RTS1 * GOLD)) // gold check
                    return true;
                player->ModifyMoney(-RTS1 * GOLD); // Deducting the money if check passes
                player->CastSpell(player, 47292); // Level up visual effect to let you know the transaction did occure and money is deducted
                RemoveAllRacials(player); // Remove all racials
                player->learnSpell(28875, false); // Gem Cutting

                // Heroic Presence Variants
                switch (player->getClass())
                {
                    case CLASS_DEATH_KNIGHT:
                    case CLASS_HUNTER:
                    case CLASS_PALADIN:
                    case CLASS_ROGUE:
                    case CLASS_WARRIOR:
                        player->learnSpell(6562, false); // Heroic Presence
                        break;
                    case CLASS_DRUID:
                    case CLASS_MAGE:
                    case CLASS_PRIEST:
                    case CLASS_SHAMAN:
                    case CLASS_WARLOCK:
                        player->learnSpell(28878, false); // Heroic Presence
                        break;
                }

                // Gift of Naaru + Shadow Resistance VARIANTS
                switch (player->getClass())
                {
                    case CLASS_DEATH_KNIGHT:
                        player->learnSpell(59545, false); // Gift of Naaru
                        player->learnSpell(59539, false); // Shadow Resistance
                        break;
                    case CLASS_HUNTER:
                        player->learnSpell(59543, false); // Gift of Naaru
                        player->learnSpell(59536, false); // Shadow Resistance
                        break;
                    case CLASS_MAGE:
                    case CLASS_WARLOCK:
                        player->learnSpell(59548, false); // Gift of Naaru
                        player->learnSpell(59541, false); // Shadow Resistance
                        break;
                    case CLASS_PALADIN:
                        player->learnSpell(59542, false); // Gift of Naaru
                        player->learnSpell(59535, false); // Shadow Resistance
                        break;
                    case CLASS_PRIEST:
                        player->learnSpell(59544, false); // Gift of Naaru
                        player->learnSpell(59538, false); // Shadow Resistance
                        break;
                    case CLASS_DRUID:
                    case CLASS_SHAMAN:
                        player->learnSpell(59547, false); // Gift of Naaru
                        player->learnSpell(59540, false); // Shadow Resistance
                        break;
                    case CLASS_ROGUE:
                    case CLASS_WARRIOR:
                        player->learnSpell(28880, false); // Gift of Naaru
                        player->learnSpell(59221, false); // Shadow Resistance
                        break;
                }
                break;

            case 3: // Dwarves Selection
                AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "致力于矮人的坚毅精神", GOSSIP_SENDER_MAIN, 31);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedBack, GOSSIP_SENDER_MAIN, 11);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedExit, GOSSIP_SENDER_MAIN, 1111);
                SendGossipMenuFor(player, 988883, creature->GetGUID());
                break;

            case 31: // Dwarves
                CloseGossipMenuFor(player);
                if (!player->HasEnoughMoney(RTS1 * GOLD)) // gold check
                    return true;
                player->ModifyMoney(-RTS1 * GOLD); // Deducting the money if check passes
                player->CastSpell(player, 47292); // Level up visual effect to let you know the transaction did occure and money is deducted
                RemoveAllRacials(player); // Remove all racials
                player->learnSpell(2481, false); // Find Treasure
                player->learnSpell(20596, false); // Frost Resistance
                player->learnSpell(20595, false); // Gun Specialization
                player->learnSpell(59224, false); // Mace Specialization
                player->learnSpell(20594, false); // Stoneform
                break;

            case 4: // Gnome Selection
                AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "致力于侏儒的科技伟力", GOSSIP_SENDER_MAIN, 41);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedBack, GOSSIP_SENDER_MAIN, 11);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedExit, GOSSIP_SENDER_MAIN, 1111);
                SendGossipMenuFor(player, 988884, creature->GetGUID());
                break;

            case 41: // Gnome
                CloseGossipMenuFor(player);
                if (!player->HasEnoughMoney(RTS1 * GOLD)) // gold check
                    return true;
                player->ModifyMoney(-RTS1 * GOLD); // Deducting the money if check passes
                player->CastSpell(player, 47292); // Level up visual effect to let you know the transaction did occur and money is deducted
                RemoveAllRacials(player); // Remove all racials
                player->learnSpell(20592, false); // Arcane Resistance
                player->learnSpell(20593, false); // Engineering Specialization
                player->learnSpell(20589, false); // Escape Artist
                player->learnSpell(20591, false); // Expansive Mind
                break;

            case 5: // Human Selection
                AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "致力于人类的精神力量", GOSSIP_SENDER_MAIN, 51);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedBack, GOSSIP_SENDER_MAIN, 11);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedExit, GOSSIP_SENDER_MAIN, 1111);
                SendGossipMenuFor(player, 988885, creature->GetGUID());
                break;

            case 51: // Human
                CloseGossipMenuFor(player);
                if (!player->HasEnoughMoney(RTS1 * GOLD)) // gold check
                    return true;
                player->ModifyMoney(-RTS1 * GOLD); // Deducting the money if check passes
                player->CastSpell(player, 47292); // Level up visual effect to let you know the transaction did occure and money is deducted
                RemoveAllRacials(player); // Remove all racials
                player->learnSpell(20599, false); // Diplomacy
                player->learnSpell(59752, false); // Every man for himself
                player->learnSpell(20864, false); // Mace Specialization
                player->learnSpell(58985, false); // Perception
                player->learnSpell(20597, false); // Sword Specialization
                player->learnSpell(20598, false); // The Human Spirit
                break;

            case 6: // Night Elf Selection
                AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "致力于古老的暗夜精灵的事业", GOSSIP_SENDER_MAIN, 61);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedBack, GOSSIP_SENDER_MAIN, 11);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedExit, GOSSIP_SENDER_MAIN, 1111);
                SendGossipMenuFor(player, 988886, creature->GetGUID());
                break;

            case 61: // Night Elf
                CloseGossipMenuFor(player);
                if (!player->HasEnoughMoney(RTS1 * GOLD)) // gold check
                    return true;
                player->ModifyMoney(-RTS1 * GOLD); // Deducting the money if check passes
                player->CastSpell(player, 47292); // Level up visual effect to let you know the transaction did occure and money is deducted
                RemoveAllRacials(player); // Remove all racials
                player->learnSpell(20583, false); // Nature Resistance
                player->learnSpell(20582, false); // Quickness
                player->learnSpell(58984, false); // Shadowmeld
                player->learnSpell(20585, false); // Wisp Spirit
                player->learnSpell(21009, false); // Elusiveness
                break;

            case 7: // Orc Selection
                AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "致力于兽人的强大力量", GOSSIP_SENDER_MAIN, 71);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedBack, GOSSIP_SENDER_MAIN, 11);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedExit, GOSSIP_SENDER_MAIN, 1111);
                SendGossipMenuFor(player, 988887, creature->GetGUID());
                break;

            case 71: // Orc
                CloseGossipMenuFor(player);
                if (!player->HasEnoughMoney(RTS1 * GOLD)) // gold check
                    return true;
                player->ModifyMoney(-RTS1 * GOLD); // Deducting the money if check passes
                player->CastSpell(player, 47292); // Level up visual effect to let you know the transaction did occure and money is deducted
                RemoveAllRacials(player); // Remove all racials
                player->learnSpell(20574, false); // Axe Specialization
                player->learnSpell(20573, false); // Hardiness
                // Command
                switch (player->getClass())
                {
                    case CLASS_DEATH_KNIGHT:
                        player->learnSpell(54562, false);
                        break;
                    case CLASS_HUNTER:
                        player->learnSpell(20576, false);
                        break;
                    case CLASS_SHAMAN:
                        player->learnSpell(65222, false);
                        break;
                    case CLASS_WARLOCK:
                        player->learnSpell(20575, false);
                        break;
                    // Command (Non Pet Users)
                    default:
                        player->learnSpell(21563, false);
                        break;
                }
                // Blood Fury
                switch (player->getClass())
                {
                    case CLASS_ROGUE:
                    case CLASS_WARRIOR:
                    case CLASS_HUNTER:
                    case CLASS_DEATH_KNIGHT:
                        player->learnSpell(20572, false); // Blood Fury (AP only)
                        break;
                    case CLASS_SHAMAN:
                    case CLASS_DRUID:
                    case CLASS_PALADIN:
                        player->learnSpell(33697, false); // Blood Fury (SP + AP)
                        break;
                    case CLASS_MAGE:
                    case CLASS_WARLOCK:
                    case CLASS_PRIEST:
                        player->learnSpell(33702, false); // Blood Fury (SP only)
                        break;
                }
                break;

            case 8: // Tauren Selection
                AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "致力于牛头人的耐力", GOSSIP_SENDER_MAIN, 81);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedBack, GOSSIP_SENDER_MAIN, 11);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedExit, GOSSIP_SENDER_MAIN, 1111);
                SendGossipMenuFor(player, 988888, creature->GetGUID());
                break;

            case 81: // Tauren
                CloseGossipMenuFor(player);
                if (!player->HasEnoughMoney(RTS1 * GOLD)) // gold check
                    return true;
                player->ModifyMoney(-RTS1 * GOLD); // Deducting the money if check passes
                player->CastSpell(player, 47292); // Level up visual effect to let you know the transaction did occure and money is deducted
                RemoveAllRacials(player); // Remove all racials
                player->learnSpell(20552, false); // Cultivation
                player->learnSpell(20550, false); // Endurance
                player->learnSpell(20551, false); // Nature Resistance
                player->learnSpell(20549, false); // Warstomp
                break;

            case 9: // Troll Selection
                AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "致力于巨魔的巫毒力量", GOSSIP_SENDER_MAIN, 91);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedBack, GOSSIP_SENDER_MAIN, 11);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedExit, GOSSIP_SENDER_MAIN, 1111);
                SendGossipMenuFor(player, 988889, creature->GetGUID());
                break;

            case 91: // Troll
                CloseGossipMenuFor(player);
                if (!player->HasEnoughMoney(RTS1 * GOLD)) // gold check
                    return true;
                player->ModifyMoney(-RTS1 * GOLD); // Deducting the money if check passes
                player->CastSpell(player, 47292); // Level up visual effect to let you know the transaction did occure and money is deducted
                RemoveAllRacials(player); // Remove all racials
                player->learnSpell(20557, false); // Beast Slaying
                player->learnSpell(26297, false); // Berserking
                player->learnSpell(26290, false); // Bow Specialization
                player->learnSpell(58943, false); // Da Voodoo Shuffle
                player->learnSpell(20555, false); // Regeneration
                player->learnSpell(20558, false); // Throwing Specialization
                break;

            case 10: // Undead Selection
                AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "致力于亡灵的决心", GOSSIP_SENDER_MAIN, 101);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedBack, GOSSIP_SENDER_MAIN, 11);
                AddGossipItemFor(player, GOSSIP_ICON_TALK, localizedExit, GOSSIP_SENDER_MAIN, 1111);
                SendGossipMenuFor(player, 988880, creature->GetGUID());
                break;

            case 101: // Undead
                CloseGossipMenuFor(player);
                if (!player->HasEnoughMoney(RTS1 * GOLD)) // gold check
                    return true;
                player->ModifyMoney(-RTS1 * GOLD); // Deducting the money if check passes
                player->CastSpell(player, 47292); // Level up visual effect to let you know the transaction did occure and money is deducted
                RemoveAllRacials(player); // Remove all racials
                player->learnSpell(20577, false); // Cannibalize
                player->learnSpell(20579, false); // Shadow Resistance
                player->learnSpell(5227, false);  // Underwater Breating
                player->learnSpell(7744, false);  // Will of the Forsaken
                break;

            default:
                break;
        }
        return true;
    }
};

void AddSC_racial_traits_npc()
{
    new Azerothcore_Race_Trait_announce();
    new npc_race_trait_swap();
}
