#include "Scala.h"

Scala::Scala(int _posX, int _posY):positionX(_posX), positionY(_posY){
  scala=NULL;
  scala=al_load_bitmap("Images/Wall.png");
  if(!scala)
    cout<<"ERROR"<<endl;
}

Scala::~Scala(){
   al_destroy_bitmap(scala);
}

void Scala::draw(int x, int y){

  al_draw_scaled_bitmap(scala, x, y, al_get_bitmap_width(scala), al_get_bitmap_height(scala), 100, 100, 100, 100, 0);

}

void Scala::setPositionX(int x){
  positionX=x;
}

void Scala::setPositionY(int y){
  positionY=y;
}

int Scala::getPositionX()const{return positionX;}
int Scala::getPositionY()const{return positionY;}
