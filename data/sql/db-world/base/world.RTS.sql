-- NPC ID 98888 Swirl
SET @NAME := 'Swirl';
SET @SUBNAME := 'AzerothCore Racial Traits Swapper';
SET @DISPLAY_ID := 30863;

DELETE FROM `creature_template` WHERE `entry`=98888;
INSERT INTO `creature_template` (`entry`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `unit_class`, `unit_flags`, `type`, `type_flags`, `RegenHealth`, `flags_extra`, `ScriptName`) VALUES
(98888, @NAME, @SUBNAME, 'Speak', 0, 80, 80, 35, 1, 1, 1.14286, 1, 0, 1, 0, 7, 138936390, 1, 0, 'npc_race_trait_swap');

DELETE FROM `creature_template_model` WHERE `CreatureID` = 98888;
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(98888, 0, @DISPLAY_ID, 1, 1, 0);

DELETE FROM `creature_template_locale` WHERE `entry`=98888 AND `locale`='zhCN';
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `Title`, `VerifiedBuild`) VALUES
(98888, 'zhCN', '漩涡', '种族特质交换', 0);

-- Initial Gossip 98888
DELETE FROM `npc_text` WHERE `ID`=98888;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`) VALUES
(98888, 'Greetings $n. \r\nYou can swap your racial traits and abilities with me for a cost. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\n\r\n\r\nWhat is your desire?', 'Greetings $n. \r\nYou can swap your racial traits and abilities with me for a cost. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\n\r\n\r\nWhat is your desire?');

DELETE FROM `npc_text_locale` WHERE `ID`=98888;
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`) VALUES
(98888, 'zhCN', '你好 $n。 \r\n您可以与我交换您的种族特质和能力，但需要付费。 如果您选择的种族没有 $c，那么您将失去 $c 的种族特征。\r\n您的期望是什么？', '你好 $n。 \r\n您可以与我交换您的种族特质和能力，但需要付费。 如果您选择的种族没有 $c，那么您将失去 $c 的种族特征。\r\n您的期望是什么？');

-- Blood ELf Menu 988881
DELETE FROM `npc_text` WHERE `ID`=988881;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`) VALUES
(988881, 'Greetings $n. \r\nYou can swap your racial traits and abilities with the ones of the Blood Elf. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\nYou will learn Arcane Affinity, Magic Resistance, and if you are a Death Knight, Hunter, Mage, Paladin, Rogue, or Warlock you will learn Arcane Torrent.\r\n\r\nWhat is your desire?', 'Greetings $n. \r\nYou can swap your racial traits and abilities with the ones of the Blood Elf. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\nYou will learn Arcane Affinity, Magic Resistance, and if you are a Death Knight, Hunter, Mage, Paladin, Rogue, or Warlock you will learn Arcane Torrent.\r\n\r\nWhat is your desire?');
DELETE FROM `npc_text_locale` WHERE `ID`=988881;
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`) VALUES
(988881, 'zhCN', '你好 $n。 \r\n您可以与血精灵的种族特征和能力交换。 如果您选择的种族没有 $c，那么您将失去 $c 的种族特征。\r\n您将学习奥术亲和、魔法抗性，并且如果您是死亡骑士、猎人、法师、圣骑士、盗贼 或术士，您还将学习奥术洪流。\r\n\r\n您的愿望是什么？', '你好 $n。 \r\n您可以与血精灵的种族特征和能力交换。 如果您选择的种族没有 $c，那么您将失去 $c 的种族特征。\r\n您将学习奥术亲和、魔法抗性，并且如果您是死亡骑士、猎人、法师、圣骑士、盗贼 或术士，您还将学习奥术洪流。\r\n\r\n您的愿望是什么？');

-- Draenei Menu 988882
DELETE FROM `npc_text` WHERE `ID`=988882;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`) VALUES
(988882, 'Greetings $n. \r\nYou can swap your racial traits and abilities with the ones of the Draenei. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\nYou will learn Gem Cutting, Gift of Naaru, Shadow Resistance, and if you are a Death Knight, Hunter, Mage, Paladin, Priest, Shaman, or Warrior you will learn Heroic Presence. \r\n\r\nWhat is your desire?', 'Greetings $n. \r\nYou can swap your racial traits and abilities with the ones of the Draenei. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\nYou will learn Gem Cutting, Gift of Naaru, Shadow Resistance, and if you are a Death Knight, Hunter, Mage, Paladin, Priest, Shaman, or Warrior you will learn Heroic Presence. \r\n\r\nWhat is your desire?');
DELETE FROM `npc_text_locale` WHERE `ID`=988882;
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`) VALUES
(988882, 'zhCN', '你好 $n。 \r\n您可以与德莱尼人的种族特征和能力交换。 如果您选择的种族没有 $c，那么您将失去 $c 的种族特征。\r\n您将学习宝石切割、纳鲁的赐福、暗影抗性，并且如果您是死亡骑士、猎人、法师、 圣骑士、牧师、萨满或战士，您还将学习英雄灵气。 \r\n\r\n您的要求是什么？', '你好 $n。 \r\n您可以与德莱尼人的种族特征和能力交换。 如果您选择的种族没有 $c，那么您将失去 $c 的种族特征。\r\n您将学习宝石切割、纳鲁的赐福、暗影抗性，并且如果您是死亡骑士、猎人、法师、 圣骑士、牧师、萨满或战士，您还将学习英雄灵气。 \r\n\r\n您的要求是什么？');

-- Dwarves Menu 988883
DELETE FROM `npc_text` WHERE `ID`=988883;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`) VALUES
(988883, 'Greetings $n. \r\nYou can swap your racial traits and abilities with the ones of the Dwarf. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\nYou will learn Find Treasure, Frost Resistance, Gun Specialization, Mace Specialization, and Stoneform.\r\n\r\nWhat is your desire?', 'Greetings $n. \r\nYou can swap your racial traits and abilities with the ones of the Dwarf. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\nYou will learn Find Treasure, Frost Resistance, Gun Specialization, Mace Specialization, and Stoneform.\r\n\r\nWhat is your desire?');
DELETE FROM `npc_text_locale` WHERE `ID`=988883;
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`) VALUES
(988883, 'zhCN', '你好 $n。 \r\n您可以与矮人交换种族特质和能力。 如果您选择的种族没有 $c，那么您将失去 $c 的种族特质。\r\n您将学习寻找财宝、冰霜抗性、枪械专精、锤类武器专精和石像形态。\r\n\r\n 你的愿望是什么？', '你好 $n。 \r\n您可以与矮人交换种族特质和能力。 如果您选择的种族没有 $c，那么您将失去 $c 的种族特质。\r\n您将学习寻找财宝、冰霜抗性、枪械专精、锤类武器专精和石像形态。\r\n\r\n 你的愿望是什么？');

-- Gnome Menu 988884
DELETE FROM `npc_text` WHERE `ID`=988884;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`) VALUES
(988884, 'Greetings $n. \r\nYou can swap your racial traits and abilities with the ones of the Gnome. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\nYou will learn Arcane Resistance, Engineering Specialization, Escape Artist, and Expansive Mind.\r\n\r\nWhat is your desire?', 'Greetings $n. \r\nYou can swap your racial traits and abilities with the ones of the Gnome. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\nYou will learn Arcane Resistance, Engineering Specialization, Escape Artist, and Expansive Mind.\r\n\r\nWhat is your desire?');
DELETE FROM `npc_text_locale` WHERE `ID`=988884;
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`) VALUES
(988884, 'zhCN', '你好 $n。 \r\n您可以与侏儒的种族特征和能力交换。 如果您选择的种族没有 $c，那么您将失去 $c 的种族特质。\r\n您将学到奥术抗性、工程学专精、逃命专家和开阔思维。\r\n\r\n 你的愿望是什么？', '你好 $n。 \r\n您可以与侏儒的种族特征和能力交换。 如果您选择的种族没有 $c，那么您将失去 $c 的种族特质。\r\n您将学到奥术抗性、工程学专精、逃命专家和开阔思维。\r\n\r\n 你的愿望是什么？');

-- Human Menu 988885
DELETE FROM `npc_text` WHERE `ID`=988885;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`) VALUES
(988885, 'Greetings $n. \r\nYou can swap your racial traits and abilities with the ones of the Human. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\nYou will learn Diplomacy, Every man for himself, Mace Specialization, Perception, Sword Specialization, and The Human Spirit.\r\n\r\nWhat is your desire?', 'Greetings $n. \r\nYou can swap your racial traits and abilities with the ones of the Human. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\nYou will learn Diplomacy, Every man for himself, Mace Specialization, Perception, Sword Specialization, and The Human Spirit.\r\n\r\nWhat is your desire?');
DELETE FROM `npc_text_locale` WHERE `ID`=988885;
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`) VALUES
(988885, 'zhCN', '你好 $n。 \r\n您可以将自己的种族特征和能力与人类的互换。 如果您选择的种族没有 $c，那么您将失去 $c 的种族特征。\r\n您将学到外交、自利、锤类武器专精、感知、剑专精和人类精魂。\r\n\r\n您的愿望是什么？', '你好 $n。 \r\n您可以将自己的种族特征和能力与人类的互换。 如果您选择的种族没有 $c，那么您将失去 $c 的种族特征。\r\n您将学到外交、自利、锤类武器专精、感知、剑专精和人类精魂。\r\n\r\n您的愿望是什么？');

-- Night Elf Menu 988886
DELETE FROM `npc_text` WHERE `ID`=988886;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`) VALUES
(988886, 'Greetings $n. \r\nYou can swap your racial traits and abilities with the ones of the Night Elf. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\nYou will learn Nature Resistance, Quickness, Shadowmeld, and Wisp Spirit. If you are a Death Knight, Druid, Hunter, Priest, or Rogue you will learn  Elusiveness.\r\n\r\nWhat is your desire?', 'Greetings $n. \r\nYou can swap your racial traits and abilities with the ones of the Night Elf. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\nYou will learn Nature Resistance, Quickness, Shadowmeld, and Wisp Spirit. If you are a Death Knight, Druid, Hunter, Priest, or Rogue you will learn  Elusiveness.\r\n\r\nWhat is your desire?');
DELETE FROM `npc_text_locale` WHERE `ID`=988886;
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`) VALUES
(988886, 'zhCN', '你好 $n。 \r\n您可以与暗夜精灵交换种族特征和能力。 如果您选择的种族没有 $c，那么您将失去 $c 的种族特质。\r\n您将学习自然抗性、迅捷、影遁和精灵之魂。 如果您是死亡骑士、德鲁伊、猎人、牧师或盗贼，您会学到难觅行踪。\r\n\r\n您的愿望是什么？', '你好 $n。 \r\n您可以与暗夜精灵交换种族特征和能力。 如果您选择的种族没有 $c，那么您将失去 $c 的种族特质。\r\n您将学习自然抗性、迅捷、影遁和精灵之魂。 如果您是死亡骑士、德鲁伊、猎人、牧师或盗贼，您会学到难觅行踪。\r\n\r\n您的愿望是什么？');

-- Orc Menu 988887
DELETE FROM `npc_text` WHERE `ID`=988887;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`) VALUES
(988887, 'Greetings $n. \r\nYou can swap your racial traits and abilities with the ones of the Orc. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\nYou will learn Axe Specialization, Hardiness, Command, and Blood Fury\r\n\r\nWhat is your desire?', 'Greetings $n. \r\nYou can swap your racial traits and abilities with the ones of the Orc. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\nYou will learn Axe Specialization, Hardiness, Command, and Blood Fury\r\n\r\nWhat is your desire?');
DELETE FROM `npc_text_locale` WHERE `ID`=988887;
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`) VALUES
(988887, 'zhCN', '你好 $n。 \r\n您可以与兽人的种族特征和能力交换。 如果您选择的种族没有$c，那么您将失去$c的种族特征。\r\n您将学习斧专精、坚韧、命令和血性狂怒\ r\n\r\n您的期望是什么？', '你好 $n。 \r\n您可以与兽人的种族特征和能力交换。 如果您选择的种族没有$c，那么您将失去$c的种族特征。\r\n您将学习斧专精、坚韧、命令和血性狂怒\ r\n\r\n您的期望是什么？');

-- Tauren Menu 988888
DELETE FROM `npc_text` WHERE `ID`=988888;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`) VALUES
(988888, 'Greetings $n. \r\nYou can swap your racial traits and abilities with the ones of the Tauren. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\nYou will learn Cultivation, Endurance, Nature Resistance, and War Stomp.\r\n\r\nWhat is your desire?', 'Greetings $n. \r\nYou can swap your racial traits and abilities with the ones of the Orc. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\nYou will learn Axe Specialization, Hardiness, Command, and Blood Fury\r\n\r\nWhat is your desire?');
DELETE FROM `npc_text_locale` WHERE `ID`=988888;
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`) VALUES
(988888, 'zhCN', '你好 $n。 \r\n您可以与牛头人交换自己的种族特质和能力。 如果您选择的种族没有 $c，那么您将失去 $c 的种族特质。\r\n您将学习栽培、耐久、自然抗性和战争践踏。\r\n\r\n您的期望是什么？', '你好 $n。 \r\n您可以与牛头人交换自己的种族特质和能力。 如果您选择的种族没有 $c，那么您将失去 $c 的种族特质。\r\n您将学习栽培、耐久、自然抗性和战争践踏。\r\n\r\n您的期望是什么？');

-- Troll Menu 988889
DELETE FROM `npc_text` WHERE `ID`=988889;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`) VALUES
(988889, 'Greetings $n. \r\nYou can swap your racial traits and abilities with the ones of the Troll. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\nYou will learn Beast Slaying, Berserking, Bow Specialization, Da Voodoo Shuffle, Regeneration, and Throwing Specialization.\r\n\r\nWhat is your desire?', 'Greetings $n. \r\nYou can swap your racial traits and abilities with the ones of the Troll. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\nYou will learn Beast Slaying, Berserking, Bow Specialization, Da Voodoo Shuffle, Regeneration, and Throwing Specialization.\r\n\r\nWhat is your desire?');
DELETE FROM `npc_text_locale` WHERE `ID`=988889;
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`) VALUES
(988889, 'zhCN', '你好 $n。 \r\n您可以将自己的种族特质和能力与巨魔的那些互换。 如果您选择的种族没有 $c，则您将失去 $c 的种族特质。\r\n您将学习野兽杀手、狂暴、弓专精、巫毒步、再生和投掷专精。\r\n\r\n您的愿望是什么？', '你好 $n。 \r\n您可以将自己的种族特质和能力与巨魔的那些互换。 如果您选择的种族没有 $c，则您将失去 $c 的种族特质。\r\n您将学习野兽杀手、狂暴、弓专精、巫毒步、再生和投掷专精。\r\n\r\n您的愿望是什么？');

-- Undead Menu 988880
DELETE FROM `npc_text` WHERE `ID`=988880;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`) VALUES
(988880, 'Greetings $n. \r\nYou can swap your racial traits and abilities with the ones of the Undead. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\nYou will learn Cannibalize, Shadow Resistance, Underwater Breating, and Will of the Forsaken.\r\n\r\nWhat is your desire?', 'Greetings $n. \r\nYou can swap your racial traits and abilities with the ones of the Undead. If the race you chose does not have a $c, then you will unlearn your $c racial traits.\r\nYou will learn Cannibalize, Shadow Resistance, Underwater Breating, and Will of the Forsaken.\r\n\r\nWhat is your desire?');
DELETE FROM `npc_text_locale` WHERE `ID`=988880;
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`) VALUES
(988880, 'zhCN', '你好 $n。 \r\n您可以将自己的种族特质和能力与亡灵互换。 如果您选择的种族没有$c，那么您将失去$c的种族特征。\r\n您将学习食尸、暗影抗性、水下呼吸和被遗忘者的意志。\r\n\r\n 你有什么愿望', '你好 $n。 \r\n您可以将自己的种族特质和能力与亡灵互换。 如果您选择的种族没有$c，那么您将失去$c的种族特征。\r\n您将学习食尸、暗影抗性、水下呼吸和被遗忘者的意志。\r\n\r\n 你有什么愿望');
