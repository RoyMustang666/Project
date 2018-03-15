#include "ObjectDynamic.h"

ObjectDynamic::ObjectDynamic(int _width, int _height){}


void ObjectDynamic::onKeyLeft(CampoDiGioco *field){}
void ObjectDynamic::onKeyRight(CampoDiGioco *field){}
void ObjectDynamic::onKeyUp(CampoDiGioco *field){}
void ObjectDynamic::onKeyDown(CampoDiGioco *field){}
void ObjectDynamic::onKeyReleased(){}
// serve per rompere il muro e se il nemico incontra un noWalk si ferma
// mentre il player se incontra un "noWalk" non cammina ma a differenza del nemico
// che rimane bloccato lui scende finchè non incontra un "walk"
// void ObjectDynamic::onSpaceBreak(CampoDiGioco* field){}
void ObjectDynamic::draw(int x, int y, int _riga, int _colonna){}


// GestoreGioco::inizializzatore{
//
//      ObjectDynamic* player = new Player(inizioX,inizioY);
//     CampoDiGioco campoA;
//
//     campoA.leggiCampoDiGioco(numNemici);
//
//   }
//
//
//   loop{
//
//     if(muoveAdestra){
//         player.onKeyRight();
//
//         int dopoDestra=player.getRiga();
//
//     }
//
//
// onKeyRight()
//
//
//   }
