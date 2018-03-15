#ifndef DRAWER_H
#define DRAWER_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "ObjectDynamic.h"
#include "ObjectStatic.h"
#include "Definizioni.h"
#include "Nemico.h"
#include "Player.h"
#include "Muro.h"
#include "Scala.h"
#include "CampoDiGioco.h"

using namespace std;

class Drawer{
  private:
    int widthMap;
    int heightMap;
    int widthBitmap;
    int heightBitmap;
    // ALLEGRO_DISPLAY* display;

  public:
    Drawer(string risoluzioneScelta); // risoluzioneScelta dall'utente nel menu delle risoluzioni
    ~Drawer();
    int getWidth()const;
    int getHeight()const;
    void startMap(ALLEGRO_DISPLAY* display,CampoDiGioco* campoDiGioco);
    ALLEGRO_DISPLAY* get_display();


};
#endif
