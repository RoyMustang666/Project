#include "Nemico.h"
//enemy costructor
  Nemico::Nemico(int width, int height):width(width),height(height){
    //enemy=NULL;
    enemy = al_load_bitmap("Images/Wall_001.png");
    ALLEGRO_BITMAP* enemyScaled= al_create_bitmap(width,height);
    ALLEGRO_BITMAP* prevBitmap=al_get_target_bitmap();
      cout<<"entrato"<<endl;
    al_set_target_bitmap(enemyScaled);
    al_draw_scaled_bitmap(enemy,
        0,0,
        al_get_bitmap_width(enemy),
        al_get_bitmap_height(enemy),
        0,0,
        width, height,
        0
      );
    al_flip_display();
    al_set_target_bitmap(prevBitmap);
    al_destroy_bitmap(enemy);
    enemy=enemyScaled;
    //al_set_target_bitmap(display);
    //creare bitmap dimensioni width/height
    //scalare la bitmap originale sulla nuova
    //spostare il puntatore dalla vecchia alla nuova
    //eliminare la vecchia
  }

//enemy destructor
  Nemico::~Nemico(){
    al_destroy_bitmap(enemy);
  }

//draw enemy
  void Nemico::draw(ALLEGRO_DISPLAY* display, int x, int y){

    // al_draw_scaled_bitmap(enemy, x, y, al_get_bitmap_width(enemy), al_get_bitmap_height(enemy), 100, 100, 60, 60, 0);
    al_draw_bitmap(enemy, x, y, 0);
  }

  // void Nemico::setPositionX(int x){
  //    positionX=x;
  // }

  // void Nemico::setPositionY(int y){
  //    positionY=y;
  // }

  // int Nemico::getPositionX()const{return positionX;}
  // int Nemico::getPositionY()const{return positionY;}
