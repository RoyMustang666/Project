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
  Muro muro(widthBitmap, heightBitmap);
  Nemico giallo(widthBitmap, heightBitmap); //top left
  Player verde(widthBitmap, widthBitmap); //top right
  // Nemico azzurro(widthBitmap, heightBitmap); //bottom right
  // Player rosso(widthBitmap, heightBitmap); //bottom left

  // ALLEGRO_DISPLAY* display=al_create_display(widthMap, heightMap);

  // giallo.draw(widthBitmap,heightBitmap);
  // verde.draw(widthBitmap,heightBitmap);
  // azzurro.draw(widthBitmap,heightBitmap);
  // rosso.draw(widthBitmap,heightBitmap);
  for(int i=0; i<18; i++){
    for(int j=0; j<32; j++){
      int a=j*widthBitmap;
      int b=i*heightBitmap;
      switch (matrix[i][j]){
        case 0:

          break;
        case 1:

          break;
        case 2:

          break;
        case 3:

          break;
        case 4:

          break;
        case 5:

          break;
        case 6:
          giallo.draw(display, a, b);
          // cout<<"riga:"<<i<<" "<<"colonna:"<<j<<endl;
          break;
        case 7:

          break;
        case 8:

          break;
        default:
          break;
      }

    }
  }
}


//matrix[i][j];


//Nemico giallo(i*widthBitmap, j*heightBitmap);
