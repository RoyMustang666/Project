#ifndef NEMICO_H
#define NEMICO_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Object.h"


using namespace std;

class Nemico: public Object{
  private:
    ALLEGRO_BITMAP* enemy;
    int positionX, positionY;

  public:
    Nemico(int _x, int _y);
    ~Nemico();

    void setPositionX(int x);
    void setPositionY(int y);

    int getPositionX()const;
    int getPositionY()const;

    void draw(int x, int y);


};

#endif
