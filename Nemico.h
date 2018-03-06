#ifndef NEMICO_H
#define NEMICO_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Object.h"
#include "Functions.h"

using namespace std;

class Nemico: public Object{
  private:
    ALLEGRO_BITMAP* enemy;

  public:
    Nemico(int _x, int _y);
    ~Nemico();

    void draw(int x, int y);

    void draw_only(int x, int y);

};

#endif
