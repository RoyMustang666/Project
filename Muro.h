#ifndef MURO_H
#define MURO_H
#include<iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "ObjectStatic.h"

using namespace std;
class Muro: public ObjectStatic{
  // SIA IN NEMICO CHE IN MURO CHE IN SCALA FORSE VA DISTRUTTO QUELLO CREATO FORSE ...
   private:
      ALLEGRO_BITMAP *muro;
   public:
      Muro(int width, int height);
      ~Muro();


      void draw(int x, int y);
};
#endif
