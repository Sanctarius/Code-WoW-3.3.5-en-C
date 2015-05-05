/*
 * Copyright © 2013-2015 Sanctarius
 */
 
#include "ScriptPCH.h"
#include <cstring>
 
class pnj_regen : public CreatureScript
{
    public:
 
        pnj_regen()
            : CreatureScript("pnj_regen")
        {
        }
 
        //MENU GENE
        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
          pPlayer->ADD_GOSSIP_ITEM(4, "Vie au Maximum->", GOSSIP_SENDER_MAIN, 1); // Option pour mettre votre vie au maximum
          if (pPlayer->getClass() == CLASS_HUNTER) // Option visible simplement pour les chasseurs
          {
            pPlayer->ADD_GOSSIP_ITEM(4, "Mana au Maximum->", GOSSIP_SENDER_MAIN, 2); // Option pour mettre votre mana au maximum
          }
          if (pPlayer->getClass() == CLASS_DRUID) // Option visible simplement pour les druides
          {
            pPlayer->ADD_GOSSIP_ITEM(4, "Mana au Maximum->", GOSSIP_SENDER_MAIN, 2);
          }
          if (pPlayer->getClass() == CLASS_MAGE)
          {
            pPlayer->ADD_GOSSIP_ITEM(4, "Mana au Maximum->", GOSSIP_SENDER_MAIN, 2);
          }
          if (pPlayer->getClass() == CLASS_PALADIN)
          {
            pPlayer->ADD_GOSSIP_ITEM(4, "Mana au Maximum->", GOSSIP_SENDER_MAIN, 2);
          }
          if (pPlayer->getClass() == CLASS_SHAMAN)
          {
            pPlayer->ADD_GOSSIP_ITEM(4, "Mana au Maximum->", GOSSIP_SENDER_MAIN, 2);
          }
          if (pPlayer->getClass() == CLASS_WARLOCK)
          {
            pPlayer->ADD_GOSSIP_ITEM(4, "Mana au Maximum->", GOSSIP_SENDER_MAIN, 2);
          }
          if (pPlayer->getClass() == CLASS_PRIEST)
          {
            pPlayer->ADD_GOSSIP_ITEM(4, "Mana au Maximum->", GOSSIP_SENDER_MAIN, 2);
          }   
          pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Quitter", GOSSIP_SENDER_MAIN, 3);
          pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
          return true;
        }
 
        bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
        {
          switch (uiAction)
          {
            case 1: // VIE
            {
              pPlayer->SetHealth(pPlayer->GetMaxHealth());
              pCreature->MonsterWhisper("Votre Vie est au Maximum.", pPlayer->GetGUID());
              pPlayer->CLOSE_GOSSIP_MENU();
              break;
            }
            case 2: // MANA
            {
              pPlayer->SetPower(POWER_MANA, pPlayer->GetMaxPower(POWER_MANA));
              pCreature->MonsterWhisper("Votre Mana est au Maximum.", pPlayer->GetGUID());
              pPlayer->CLOSE_GOSSIP_MENU();
              break;
            }
            case 3: //Quitter
            {
              pCreature->MonsterWhisper("Aurevoir.", pPlayer->GetGUID());
              pPlayer->CLOSE_GOSSIP_MENU();
              break;
            }
          }
          return true;
        }
};
 
void AddSC_pnj_regen()
{
    new pnj_regen();
}