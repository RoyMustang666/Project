#include "Muro.h"

Muro::Muro(int width, int height):ObjectStatic(width,height){
  muro = al_load_bitmap("Images/Wall_001.png");
  ALLEGRO_BITMAP* muroScaled= al_create_bitmap(width,height);
  // CREO UNA BITMAP TEMPORANEA IN CUI SALVO IL VALORE PRECEDENTE
  ALLEGRO_BITMAP* prevBitmap=al_get_target_bitmap();
    cout<<"entratoMuro"<<endl;
  al_set_target_bitmap(muroScaled);
  al_draw_scaled_bitmap(muro,
      0,0,
      al_get_bitmap_width(muro),
      al_get_bitmap_height(muro),
      0,0,
      width, height,
      0
    );
  al_flip_display();
  al_set_target_bitmap(prevBitmap);
  al_destroy_bitmap(muro);
  muro = muroScaled;

}

Muro::~Muro(){
   al_destroy_bitmap(muro);
}

void Muro::draw(int x, int y){
  al_draw_bitmap(muro,x,y,0);

}

// void Muro::setPositionX(int x){
//   width=x;
// }

// void Muro::setPositionY(int y){
//   height=y;
// }

// int Muro::getPositionX()const{return wi;}
// int Muro::getPositionY()const{return positionY;}
