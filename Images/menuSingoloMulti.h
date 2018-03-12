#ifndef MENUSINGOLOMULTI_H
#define MENUSINGOLOMULTI_H

#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include"menuRisoluzioni.h"
#include"Definizioni.h"
using namespace std;

class menuSingoloMulti{

  private:
     ALLEGRO_DISPLAY *display;
     ALLEGRO_BITMAP *button;
    //  ALLEGRO_BITMAP *buttonMulti;
     ALLEGRO_EVENT_QUEUE *event_queue = NULL;
     ALLEGRO_TIMER *timer = NULL;
     bool redraw = true;
     float posX;
     float posY;

  public:
     menuSingoloMulti();
     ~menuSingoloMulti();

     string sceltaSingoloMulti(string _risoluzione);


};
#endif
