#ifndef OBJECTDYNAMIC_H
#define OBJECTDYNAMIC_H

#include <iostream>
#include "CampoDiGioco.h"
#include "Definizioni.h"
using namespace std;

class ObjectDynamic{

protected:

  int width,height;
  double velocita;
  int riga;
  int colonna;

  public:
    ObjectDynamic(int _width, int _height);

    virtual void onKeyLeft(CampoDiGioco *field);
  	virtual void onKeyRight(CampoDiGioco *field);
  	virtual void onKeyUp(CampoDiGioco *field);
  	virtual void onKeyDown(CampoDiGioco *field);
  	virtual void onKeyReleased();
    // serve per rompere il muro e se il nemico incontra un noWalk si ferma
    // mentre il player se incontra un "noWalk" non cammina ma a differenza del nemico
    // che rimane bloccato lui scende finchè non incontra un "walk"
    // virtual void onSpaceBreak(CampoDiGioco* field);
    virtual void draw(int x, int y, int _riga, int _colonna);


};

#endif
