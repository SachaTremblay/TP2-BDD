#include "Database.h"
#include "sqlite3.h"

#include "knob.h"

#define LOG_SQLITE3_ERROR(db) knob_log(KNOB_ERROR, "%s:%d: SQLITE3 ERROR: %s\n", FILE, LINE, sqlite3_errmsg(db))
static sqlite3* db = NULL;
void database_start(GameData* g){
    sqlite3_open("game.db",&g->db);
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
        "   FOREIGN KEY (ClasseID) REFERENCES Class (ClassID),"
        "   FOREIGN KEY (InventoryID) REFERENCES Inventory (InventoryID)"
        ");";
const char* Create_CreditCard_table = "CREATE TABLE IF NOT EXISTS CreditCard("
        "   CreditCardID INTEGER PRIMARY KEY,"
        "   CreditCardNum varchar(17),"
        "   NameOfCardHolder varchar(32),"
        "   CardCVC varchar(3)"
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
const char* Create_Items_table = "CREATE TABLE IF NOT EXISTS Items("
        "   ,"
        "   ,"
        "   ,"
        "   ,"
        "   ,"
        "   ,"
        "   ,"
        "   FOREIGN KEY () REFERENCES  ()"
        ");";

void CreationDatabase(GameData* g){

    if (sqlite3_exec(g->db, Create_Race_table,NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(db);
        return;
    }
    if (sqlite3_exec(g->db, Create_Faction_table,NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(db);
    }
    if (sqlite3_exec(g->db, Create_SocialStatus_table,NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(db);
    }
    if (sqlite3_exec(g->db, Create_Class_table,NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(db);
    }
    if (sqlite3_exec(g->db, Create_Character_table,NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(db);
    }
    if (sqlite3_exec(g->db, Create_CreditCard_table,NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(db);
    }
    if (sqlite3_exec(g->db, Create_Wallet_table,NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(db);
    }
    if (sqlite3_exec(g->db, Create_WalletItems_table,NULL, NULL, NULL) != SQLITE_OK) {
        LOG_SQLITE3_ERROR(db);
    }