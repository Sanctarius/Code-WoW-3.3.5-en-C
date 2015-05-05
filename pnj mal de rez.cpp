/*
 * Copyright © 2013-2015 Sanctarius
 */
 
#include "ScriptPCH.h"
#include <cstring>
 
#ifdef WIN32
#pragma warning(disable:4305)
#endif
 
enum eEnums
{       
  GOLD = 50000, // prix pour enlever le mal de rez ( 50000 = 5 Po )
};
 
class pnj_malderez : public CreatureScript
{
    public:
 
        pnj_malderez()
            : CreatureScript("pnj_malderez")
        {
        }
 
        //MENU GENERAL
        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
          if (pPlayer->HasAura(15007)) // Si le joueur à l'aura 15007 (le mal de rez) il verra les menus suivant)
          {
            pPlayer->ADD_GOSSIP_ITEM(4, "Retirer mon mal de resurrection (5 po)->", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Quitter", GOSSIP_SENDER_MAIN, 2); // Fermer le menu
            pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
          }
          else
          {
            pCreature->MonsterWhisper("Vous n'avez pas le mal de resurrection.", pPlayer->GetGUID()); // Aucune ouverture du menu, message entre pnj et joueur directement envoyé
            pPlayer->CLOSE_GOSSIP_MENU();
          }
          return true;
        }
 
        bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
        {
          pPlayer->PlayerTalkClass->ClearMenus();
          if (uiAction == GOSSIP_ACTION_INFO_DEF + 1) // Menu de vérification
          {
            if (pPlayer->GetUInt32Value(PLAYER_FIELD_COINAGE) < GOLD) // Si le joueur n'a pas assez de Po ( Argent du joueur < Po demandé )
            {
              pCreature->MonsterWhisper("Vous n'avez pas assez d'argent!", pPlayer->GetGUID());
              pPlayer->CLOSE_GOSSIP_MENU();
            }
            else // Sinon
            {
              pPlayer->ADD_GOSSIP_ITEM(4, "Retirer ->", GOSSIP_SENDER_MAIN, 1);
              pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Quitter", GOSSIP_SENDER_MAIN, 2);
              pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
            }
            return true;
          }
 
          switch (uiAction)
          {
            case 1: // mal de rez retiré ainsi que 5 Po de votre sac
            {
              int32 GetGold = pPlayer->GetUInt32Value(PLAYER_FIELD_COINAGE);
              int32 Rob = GetGold - GOLD; // Votre argent - 5 Po
              pPlayer->SetUInt32Value(PLAYER_FIELD_COINAGE, Rob);
              pPlayer->RemoveAurasDueToSpell(15007); // Aura retiré
              pCreature->MonsterWhisper("Vous avez retirer votre mal de rez.", pPlayer->GetGUID());
              pPlayer->CLOSE_GOSSIP_MENU();
              break;
            }
            case 2: //Quitter
            {
              pCreature->MonsterWhisper("Au revoir.", pPlayer->GetGUID());
              pPlayer->CLOSE_GOSSIP_MENU();
              break;
            }
          }
          return true;
        }
};
 
void AddSC_pnj_malderez()
{
    new pnj_malderez();
}