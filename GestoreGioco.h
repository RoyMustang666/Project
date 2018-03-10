#ifndef GESTOREGIOCO_H
#define GESTOREGIOCO_H

// #include <iostream>
// #include <allegro5/allegro.h>
// #include "Nemico.h"
// #include "Player.h"
// #include "Definizioni.h"
#include "Object.h"
#include "menuRisoluzioni.h"
#include "menuSingoloMulti.h"
#include "Drawer.h"

using namespace std;

class GestoreGioco{

  ALLEGRO_DISPLAY *display;
  // ALLEGRO_BITMAP *bitmapR;
  ALLEGRO_EVENT_QUEUE *event_queue;
  ALLEGRO_TIMER *timer;
  bool tasti[6];
  bool gameDone;
  Object* oggetto;
  Player* oggettoCorrente;

 public:
   GestoreGioco();
   ~GestoreGioco();

   bool inizializzatore();
   //void loop();

};
#endif
