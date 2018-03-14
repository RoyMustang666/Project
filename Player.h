#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Object.h"
#include "menuRisoluzioni.h"
#include "CampoDiGioco.h"

using namespace std;

class Player: public Object{
  private:
    ALLEGRO_BITMAP* player;
    bool direzioni[4];
    double velocita;
    int riga;
    int colonna;
  public:
    Player(int width, int height);
    ~Player();

    void setRiga(int _riga);
    void setColonna(int _colonna);
    void onKeyLeft();
  	void onKeyRight();
  	void onKeyUp();
  	void onKeyDown();
  	void onKeyReleased();
    //assegnarela pos successiva alla precedente
    void draw(int x, int y, int _riga, int _colonna);
};

#endif
