#include "Scala.h"

Scala::Scala(int _posX, int _posY):posX(_posX), posY(_posY){
  scala=NULL;
  scala=al_load_bitmap("Images/Wall.png");
  if(!scala)
    cout<<"ERROR"<<endl;
}

Scala::~Scala(){
   al_destroy_bitmap(scala);
}

void Scala::disegnaScala(int x, int y){

  al_draw_scaled_bitmap(scala,
    x, y,
    al_get_bitmap_width(scala), al_get_bitmap_height(scala),
    0, 0,
    100, 100,
    0);

}
