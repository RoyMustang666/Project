#ifndef MURO_H
#define MURO_H
#include<iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
using namespace std;
class Muro{
   private:
      int posX;
      int posY;
      ALLEGRO_BITMAP *muro;
   public:
      Muro(int _posX, int _posY);
      ~Muro();

      void disegnaMuro(int x, int y);
};
#endif
