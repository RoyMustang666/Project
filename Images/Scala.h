#ifndef SCALA_H
#define SCALA_H
#include<iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
using namespace std;
class Scala{
   private:
      ALLEGRO_BITMAP *scala;
      int positionX, positionY;
   public:
      Scala(int _posX, int _posY);
      ~Scala();

      void setPositionX(int x);
      void setPositionY(int y);

      int getPositionX()const;
      int getPositionY()const;

      void draw(int x, int y);
};
#endif
