#include "DataBase.h"
#include <sqlite3.h>
#include "knob.h"
#define LOG_SQLITE3_ERROR(db) knob_log(KNOB_ERROR, "%s:%d: SQLITE3 ERROR: %s\n", __FILE__, __LINE__, sqlite3_errmsg(db))

void DataBaseStart(GameData* g) {
    sqlite3_open("game.db", &g->db);
    DataBaseInitTables(g);
    DataBaseInitItems(g);
}

const char* Create_Race_table = "CREATE TABLE IF NOT EXISTS Race("
        "   RaceID INTEGER PRIMARY KEY,"
        "   Race TEXT"
        ");";
const char* Create_Faction_table = "CREATE TABLE IF NOT EXISTS Faction("
        "   FactionID INTEGER PRIMARY KEY,"
        "   Faction TEXT"
        ");";
const char* Create_SocialStatus_table ="CREATE TABLE IF NOT EXISTS SocialStatus("
        "   SocialStatusID INTEGER PRIMARY KEY,"
        "   SocialStatus TEXT"
        ");";
const char* Create_Class_table = "CREATE TABLE IF NOT EXISTS Class("
        "   Race RaceID,"
        "   Faction FactionID,"
        "   SocialStatus SocialStatusID"
        ");";
const char* Create_Character_table = "CREATE TABLE IF NOT EXISTS Character("
        "   CharacterID INTEGER PRIMARY KEY,"
        "   Name TEXT,"
        "   Level INTEGER,"
        "   Strength INTEGER,"
        "   Stamina INTEGER,"
        "   Stealth INTEGER,"
        "   Charisma INTEGER,"
        "   ClasseID INTEGER,"
        "   InventoryID INTEGER,"
        "   FOREIGN KEY (ClasseID) REFERENCES Class (ClassID),"
        "   FOREIGN KEY (InventoryID) REFERENCES Inventory (InventoryID)"
        ");";
const char* Create_CreditCard_table = "CREATE TABLE IF NOT EXISTS CreditCard("
        "   CreditCardID INTEGER PRIMARY KEY,"
        "   CreditCardNum VARCHAR(17),"
        "   NameOfCardHolder VARCHAR(32),"
        "   CardCVC VARCHAR(3)"
        ");";
const char* Create_Wallet_table = "CREATE TABLE IF NOT EXISTS Wallet("
        "   WalletID INTEGER PRIMARY KEY,"
        "   Capacity INTEGER,"
        "   GGBucksPossessed INTEGER"
        ");";
const char* Create_WalletItems_table = "CREATE TABLE IF NOT EXISTS WalletItems("
        "   WalletID INTEGER PRIMARY KEY,"
        "   Capacity INTEGER,"
        "   GGBucksPossessed INTEGER"
        ");";
const char* Create_Client_table = "CREATE TABLE IF NOT EXISTS Client("
        "   ClientID INTEGER PRIMARY KEY,"
        "   Name TEXT,"
        "   PassWord TEXT,"
        "   CharacterID INTEGER,"
        "   WalletID INTEGER,"
        "   CreditCardID INTEGER,"
        "   FOREIGN KEY (CharacterID) REFERENCES Character (CharacterID),"
        "   FOREIGN KEY (WalletID) REFERENCES Wallet (WalletID),"
        "   FOREIGN KEY (CreditCardID) REFERENCES CreditCard (CreditCardID)"
        ");";
const char* Create_Items_table = "CREATE TABLE IF NOT EXISTS Items("
        "   ItemID INTEGER PRIMARY KEY,"
        "   Name VARCHAR(16),"
        "   Value INTEGER,"
        "   IsWeapon INTEGER,"
        "   IsArmor INTEGER,"
        "   IsEquipped INTEGER,"
        "   IsHeavy INTEGER,"
        "   Color ENUM"
        ");";

void DataBaseInitTables(GameData* g){

    if (sqlite3_exec(g->db, Create_Race_table,NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    if (sqlite3_exec(g->db, Create_Faction_table,NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    if (sqlite3_exec(g->db, Create_SocialStatus_table,NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    if (sqlite3_exec(g->db, Create_Class_table,NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    if (sqlite3_exec(g->db, Create_Character_table,NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    if (sqlite3_exec(g->db, Create_CreditCard_table,NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    if (sqlite3_exec(g->db, Create_Wallet_table,NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    if (sqlite3_exec(g->db, Create_WalletItems_table,NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    if (sqlite3_exec(g->db, Create_WalletItems_table,NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    if (sqlite3_exec(g->db, Create_Client_table,NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
    if (sqlite3_exec(g->db, Create_Items_table,NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
}

const char* Insert_Items = "INSERT OR IGNORE INTO Items (ItemID, Name, Value, IsWeapon, IsArmor, IsEquipped, IsHeavy, Color) VALUES"
        "(1,'Hatchet', 10, 1, 0, 0, 0, 'Silver'),"
        "(2,'Bow', 23, 1, 0, 0, 0, 'PineWood'),"
        "(3,'Crossbow', 30, 1, 0, 0, 0, 'Acacia'),"
        "(4,'Long Axe', 20, 1, 0, 0, 1, 'Silver'),"
        "(5,'Spear', 24, 1, 0, 0, 0, 'Silver'),"
        "(6,'Long Sword', 34, 1, 0, 0, 1, 'Silver'),"
        "(7,'Holy Sword', 10, 1, 0, 0, 0, 'Gold'),"
        "(8,'Light Weight Armor', 10, 0, 1, 0, 0, 'White'),"
        "(9,'Heavy Weight Armor', 25, 0, 1, 0, 1, 'Black And Red'),"
        "(10,'Swiftness Armor', 30, 0, 1, 0, 0, 'Blue'),"
        "(11,'Armor Of The Arised', 75, 0, 0, 0, 1, 'Red And Gold')"
        ");";

void DataBaseInitItems(GameData* g){
    if (sqlite3_exec(g->db, Insert_Items,NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(g->db);
        return;
    }
}



void DataBaseEnd(GameData* g) {
    sqlite3_close(g->db);
}