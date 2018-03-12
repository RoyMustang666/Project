#ifndef SCALA_H
#define SCALA_H
#include<iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Object.h"

using namespace std;
class Scala : public Object{
   private:
      ALLEGRO_BITMAP *scala;
      // int width, height;
   public:
      Scala(int width, int height);
      ~Scala();

      // void setPositionX(int x);
      // void setPositionY(int y);
      //
      // int getPositionX()const;
      // int getPositionY()const;

      void draw(int x, int y);
};
#endif
