#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Object.h"
#include "Functions.h"

using namespace std;

class Player: public Object{
  private:
    ALLEGRO_BITMAP* player;

  public:
    Player(int _x, int _y);
    ~Player();

    void draw(int x, int y);
};

#endif
