#include "Drawer.h"


Drawer::Drawer(string res){
  this->res=res;
  if(res=="SD"){
    //case "SD":
      widthMap=larghezzaSD;
      heightMap=altezzaSD;
    }
  else if(res=="HD"){
    //case "HD":
    widthMap=larghezzaR;
    heightMap=altezzaR;
  }
  else if(res=="FH"){
    //case "FH":
      widthMap=larghezzaFH;
      heightMap=altezzaFH;
  }

  widthBitmap=widthMap/32;
  heightBitmap=heightMap/18;

  // display=al_create_display(widthMap, heightMap);
}

  ALLEGRO_DISPLAY* Drawer::get_display(){
  ALLEGRO_DISPLAY* display=al_create_display(widthMap, heightMap);
  return display;
}


void Drawer::startMap(ALLEGRO_DISPLAY* display, int nn){
  CampoDiGioco *campoDG= new CampoDiGioco();
  int **matrix;
  campoDG->leggiCampoDiGioco(nn);
  matrix=campoDG->restituisciMappa();
  Object* muro= new Muro(widthBitmap, heightBitmap);
  Object* nemico=new Nemico(widthBitmap, heightBitmap); //top left
  Object* player=new Player(widthBitmap, widthBitmap); //top right
  Object* scala = new Scala(widthBitmap,heightBitmap);


  // Nemico azzurro(widthBitmap, heightBitmap); //bottom right
  // Player rosso(widthBitmap, heightBitmap); //bottom left

  // ALLEGRO_DISPLAY* display=al_create_display(widthMap, heightMap);

  // giallo.draw(widthBitmap,heightBitmap);
  // verde.draw(widthBitmap,heightBitmap);
  // azzurro.draw(widthBitmap,heightBitmap);
  // rosso.draw(widthBitmap,heightBitmap);
  for(int i=0; i<18; i++){
    for(int j=0; j<32; j++){
      int posI=j*widthBitmap;
      int posJ=i*heightBitmap;
      switch (matrix[i][j]){
        case 0:

          break;
        case 1: // disegna i muri
          muro->draw(posI,posJ);
          break;
        case 2:

          break;
        case 3:

          break;
        case 4: // scale
          scala->draw(posI,posJ);
          break;

        case 5: // player
        player->draw(posI,posJ);
          break;
        case 6: // nemico
        nemico->draw(posI,posJ);
          break;
        default:
          break;
      }

    }
  }
  delete muro;
  delete nemico;
  delete player;
  delete scala;
  delete campoDG;
}


//matrix[i][j];


//Nemico giallo(i*widthBitmap, j*heightBitmap);
