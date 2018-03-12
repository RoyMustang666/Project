#include "Muro.h"

Muro::Muro(int _posX, int _posY):positionX(_posX), positionY(_posY){
  muro=NULL;
  muro=al_load_bitmap("Images/Wall.png");
  if(!muro)
    cout<<"ERROR"<<endl;
}

Muro::~Muro(){
   al_destroy_bitmap(muro);
}

void Muro::draw(int x, int y){

  al_draw_scaled_bitmap(muro, x, y, al_get_bitmap_width(muro), al_get_bitmap_height(muro), 100, 100, 100, 100, 0);

}

void Muro::setPositionX(int x){
  positionX=x;
}

void Muro::setPositionY(int y){
  positionY=y;
}

int Muro::getPositionX()const{return positionX;}
int Muro::getPositionY()const{return positionY;}
