#ifndef DRAWER_H
#define DRAWER_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Definizioni.h"
#include "Nemico.h"
#include "Player.h"
#include "Muro.h"
#include "Scala.h"
#include "CampoDiGioco.h"

using namespace std;

class Drawer{
  private:
    string res;
    int widthMap;
    int heightMap;
    int widthBitmap;
    int heightBitmap;
    // ALLEGRO_DISPLAY* display;

  public:
    Drawer(string res); //input: screen resolution
    ~Drawer();
    void startMap(ALLEGRO_DISPLAY* display,int nn);
    ALLEGRO_DISPLAY* get_display();


};
#endif
