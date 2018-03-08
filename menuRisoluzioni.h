#ifndef MENURISOLUZIONI_H
#define MENURISOLUZIONI_H

#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include"Definizioni.h"
using namespace std;

class menuRisoluzioni{

  private:
     ALLEGRO_DISPLAY *display;
     ALLEGRO_BITMAP *buttonSD;
     ALLEGRO_BITMAP *buttonR;
     ALLEGRO_BITMAP *buttonFH;
     float posX;
     float posY;

  public:
     menuRisoluzioni();
     ~menuRisoluzioni();

     string startMenu();


};
#endif
