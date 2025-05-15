#pragma once
#include "game.h"

void InitDatabase(void);

void database_start(GameData* g);
void database_end(GameData* g);
void CreationDatabase(GameData* g);
void Save_Client(GameData client);
void SaveCharacter(GameData data);

void database_create_user(GameData* data);