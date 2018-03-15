#ifndef NEMICO_H
#define NEMICO_H
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "ObjectDynamic.h"

using namespace std;

class Nemico: public ObjectDynamic{
  private:
    ALLEGRO_BITMAP* enemy;
    double velocita;
  // ricordarsi di inizializzare riga e colonna ereditati da ObjectStatic
  // nel costruttore

  public:
    Nemico(int width, int height);
    ~Nemico();
    bool checkCollision()const;
    void draw(int x, int y,int _riga, int _colonna);


};

#endif
