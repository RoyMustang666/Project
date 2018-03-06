#ifndef SCALA_H
#define SCALA_H

#include<iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

class Scala{
   private:
      int posX;
      int posY;
      ALLEGRO_BITMAP *scala;
   public:
      Scala(int _posX, int _posY);
      ~Scala();

      void disegnaScala(int x, int y);
};
#endif
