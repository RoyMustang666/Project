#include "Nemico.h"
//enemy costructor
  Nemico::Nemico(int _x, int _y){
    enemy = al_load_bitmap("Images/Omino128_bord.png");
    if(!enemy)
      cout<<"ERROR DRAWING"<<endl;
  }

//enemy destructor
Nemico::~Nemico(){
  al_destroy_bitmap(enemy);
}

//draw enemy
void Nemico::draw(int x, int y){

  cout<<getPositionX()<<" "<<getPositionY()<<endl;

  al_draw_scaled_bitmap(enemy,
    0, 0,
    al_get_bitmap_width(enemy), al_get_bitmap_height(enemy),
    160, 160,
    x, y,
    0);

  cout<<getPositionX()<<" "<<getPositionY()<<endl;
}

void Nemico::draw_only(int x, int y){
  al_draw_bitmap(enemy, x, y, 0);
}
