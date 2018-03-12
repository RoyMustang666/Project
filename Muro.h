#ifndef MURO_H
#define MURO_H
#include<iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Object.h"

using namespace std;
class Muro: public Object{
  // SIA IN NEMICO CHE IN MURO CHE IN SCALA FORSE VA DISTRUTTO QUELLO CREATO FORSE ...
   private:
      ALLEGRO_BITMAP *muro;
   public:
      Muro(int width, int height);
      ~Muro();

      // void setPositionX(int x);
      // void setPositionY(int y);
      //
      // int getPositionX()const;
      // int getPositionY()const;

      void draw(int x, int y);
};
#endif
