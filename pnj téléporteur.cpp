/*
 * Copyright © 2013-2015 Sanctarius
 */
 
#include "ScriptPCH.h"
#include <cstring>
 
class pnj_tel : public CreatureScript
{
    public:
 
        pnj_tel()
            : CreatureScript("pnj_tel")
        {
        }
 
        //MENU GENERAL
        bool OnGossipHello(Player* pPlayer, Creature* pCreature) // Affichage du menu
        {
          pPlayer->ADD_GOSSIP_ITEM(4, "Zone Y", GOSSIP_SENDER_MAIN, 1); // Première option
          pPlayer->ADD_GOSSIP_ITEM(4, "Zone X", GOSSIP_SENDER_MAIN, 2); // Deuxième option
          pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Quitter", GOSSIP_SENDER_MAIN, 3); // Troisième option ( Fermeture du menu )
          pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
          return true;
        }
 
        bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction) // Action lors du clique de l'option choisi
        {
          switch(uiAction)
          {
            case 1: // Téléportation Zone Y
            {
              pPlayer->CLOSE_GOSSIP_MENU(); // Fermeture du menu
              pPlayer->TeleportTo(1, 3254.35f, -4467.673f, 266.237f, 4.665f); // (id de la Map, coordonnées X, coordonnées Y, coordonnées Z, Orientation)
              break;
            }
            case 2: // Téléportation Zone X
            {
              pPlayer->CLOSE_GOSSIP_MENU(); // Fermeture du menu
              pPlayer->TeleportTo(37, 1069.477f, 9.154f, 317.017f, 3.69f); // (id de la Map, coordonnées X, coordonnées Y, coordonnées Z, Orientation)
              break;
            }
            case 3: // Quitter
            {               
              pCreature->MonsterWhisper("Au revoir Jeune Maître.", pPlayer->GetGUID()); // Message "Au revoir" entre le pnj et le joueur
              pPlayer->CLOSE_GOSSIP_MENU(); // Fermeture du menu
              break;
            }
          }
          return true; 
        }
};
 
void AddSC_pnj_tel()
{
    new pnj_tel(); // Nom du script à donné au pnj dans la base de données
}