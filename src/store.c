#include "store.h"
#include <assert.h>

#define SizeOfTile 65

void AddItemInStore(GameData* g, Vector2* Cursor) {
    DrawRectangle(Cursor->x,Cursor->y, SizeOfTile, SizeOfTile, RED);
    Cursor->x += SizeOfTile + PADDING;
    if(Cursor->x > g->win.w - SizeOfTile - PADDING) {
        Cursor->x = 10;
        Cursor->y += SizeOfTile + PADDING;
    }
}

void ui_store(GameData* g){
    Vector2 Cursor = {10,30};
    for(int i = 0; i < 60 ; i++) {
        AddItemInStore(g, &Cursor);
    }
}