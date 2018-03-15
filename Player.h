#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "menuRisoluzioni.h"
#include "CampoDiGioco.h"
#include "ObjectDynamic.h"

using namespace std;

class Player: public ObjectDynamic{
  private:
    ALLEGRO_BITMAP* player;
    bool direzioni[4];
    
    int widthBitmap;
    int heightBitmap;
    // double velocita;
    // int riga;
    // int colonna;

  public:
    Player(int width, int height);
    ~Player();

    void onKeyLeft(CampoDiGioco* field);
  	void onKeyRight(CampoDiGioco* field);
  	void onKeyUp(CampoDiGioco* field);
  	void onKeyDown(CampoDiGioco* field);
    void onSpaceBreak(CampoDiGioco* field);
  	void onKeyReleased();

    void setRiga(int _riga);
    void setColonna(int _colonna);
    int getRiga()const;
    int getColonna()const;
    //assegnarela pos successiva alla precedente
    void draw(int x, int y, int _riga, int _colonna);
};

#endif
