#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Object.h"

using namespace std;

class Player: public Object{
  private:
    ALLEGRO_BITMAP* player;
    int positionX, positionY;
  public:
    Player(int _x, int _y);
    ~Player();

    void setPositionX(int x);
    void setPositionY(int y);

    int getPositionX()const;
    int getPositionY()const;

    void draw(int x, int y);
};

#endif
