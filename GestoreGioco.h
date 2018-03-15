#ifndef GESTOREGIOCO_H
#define GESTOREGIOCO_H

// #include <allegro5/allegro.h>
// #include "Nemico.h"
// #include "Player.h"
// #include "Definizioni.h"
#include <iostream>
#include <vector>
#include "ObjectDynamic.h"
#include "ObjectStatic.h"
#include "menuRisoluzioni.h"
#include "menuSingoloMulti.h"
#include "CampoDiGioco.h"
#include "Drawer.h"

using namespace std;

class GestoreGioco{

  ALLEGRO_DISPLAY *display;
  ALLEGRO_EVENT_QUEUE *event_queue;
  ALLEGRO_TIMER *timer;
  bool tasti[6];
  bool gameDone;
  bool draw;
  Drawer* drawer;
  ObjectDynamic* player;
  CampoDiGioco* field;



 public:
   GestoreGioco();
   ~GestoreGioco();

   bool inizializzatore();
   void loop();

};
#endif
