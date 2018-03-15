#ifndef SCALA_H
#define SCALA_H
#include<iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "ObjectStatic.h"

using namespace std;
class Scala : public ObjectStatic{
   private:
      ALLEGRO_BITMAP *scala;

   public:
      Scala(int width, int height);
      ~Scala();


      void draw(int x, int y);
};
#endif
