#include "Nemico.h"
//enemy costructor
  Nemico::Nemico(int _x, int _y):positionX(_x),positionY(_y){
    enemy=NULL;
    enemy = al_load_bitmap("Images/Wall_001.png");
    if(!enemy)
      cout<<"VAFFANCULO"<<endl;
  }

//enemy destructor
  Nemico::~Nemico(){
    al_destroy_bitmap(enemy);
  }

//draw enemy
  void Nemico::draw(int x, int y){

    al_draw_scaled_bitmap(enemy, x, y, al_get_bitmap_width(enemy), al_get_bitmap_height(enemy), 100, 100, 60, 60, 0);

  }

  void Nemico::setPositionX(int x){
     positionX=x;
  }

  void Nemico::setPositionY(int y){
     positionY=y;
  }

  int Nemico::getPositionX()const{return positionX;}
  int Nemico::getPositionY()const{return positionY;}
