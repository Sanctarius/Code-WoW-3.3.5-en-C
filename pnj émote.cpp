/*
 * Copyright © 2013-2015 Sanctarius
 */

local npc = 68
  
local function OnReveivedEmote(event, creature, plr, emoteid)
    if(emoteid == 17) then -- EmotesText.dbc
        creature:Emote(2) -- Emotes.dbc
    end
end
  
RegisterCreatureEvent(npc, 8, OnReveivedEmote)
// Ce petit script en LUA permettra à un garde de Hurlevent de faire l'emote /bow (/incliner) lorsque le joueur fera cette même emote. 