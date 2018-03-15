#include "Scala.h"

Scala::Scala(int width, int height):ObjectStatic(width, height){
  scala = al_load_bitmap("Images/Omino_up.png");
  ALLEGRO_BITMAP* scalaScaled= al_create_bitmap(width,height);
  // CREO UNA BITMAP TEMPORANEA IN CUI SALVO IL VALORE PRECEDENTE
  ALLEGRO_BITMAP* prevBitmap=al_get_target_bitmap();
    cout<<"entrato"<<endl;
  al_set_target_bitmap(scalaScaled);
  al_draw_scaled_bitmap(scala,
      0,0,
      al_get_bitmap_width(scala),
      al_get_bitmap_height(scala),
      0,0,
      width, height,
      0
    );
  al_flip_display();
  al_set_target_bitmap(prevBitmap);
  al_destroy_bitmap(scala);
  scala=scalaScaled;
}

Scala::~Scala(){
   al_destroy_bitmap(scala);
}

void Scala::draw(int x, int y){

  al_draw_bitmap(scala,x,y,0);

}

// void Scala::setPositionX(int x){
//   positionX=x;
// }
//
// void Scala::setPositionY(int y){
//   positionY=y;
// }
//
// int Scala::getPositionX()const{return positionX;}
// int Scala::getPositionY()const{return positionY;}
