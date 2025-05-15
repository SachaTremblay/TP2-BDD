#pragma once
#include "game.h"

void DataBaseStart(GameData* g);
void DataBaseEnd(GameData* g);
void DataBaseInitTables(GameData* g);
void DataBaseInitItems(GameData* g);
void DataBaseCreateUser(GameData* g); //Create User
void DataBaseSaveCharacter(GameData* g); //Update Character
Items* GetItemImage(GameData* g);