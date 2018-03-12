#ifndef MURO_H
#define MURO_H
#include<iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
using namespace std;
class Muro{
   private:
      ALLEGRO_BITMAP *muro;
      int positionX, positionY;
   public:
      Muro(int _posX, int _posY);
      ~Muro();

      void setPositionX(int x);
      void setPositionY(int y);

      int getPositionX()const;
      int getPositionY()const;

      void draw(int x, int y);
};
#endif
