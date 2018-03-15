#include "Drawer.h"

// questa string sarà data dal passaggio nel gestore gioco dopo la scelta
// delle risoluzioni
Drawer::Drawer(string risoluzioneScelta){

  if(risoluzioneScelta=="SD"){
    //case "SD":
      widthMap=larghezzaSD;
      heightMap=altezzaSD;
    }
  else if(risoluzioneScelta=="HD"){
    //case "HD":
    widthMap=larghezzaR;
    heightMap=altezzaR;
  }
  else if(risoluzioneScelta=="FH"){
    //case "FH":
      widthMap=larghezzaFH;
      heightMap=altezzaFH;
  }

  widthBitmap=widthMap/32;
  heightBitmap=heightMap/18;

  // display=al_create_display(widthMap, heightMap);
}

int Drawer::getWidth()const{
  return widthBitmap;
}
int Drawer::getHeight()const{
  return heightBitmap;
}


// servirà in base alla risoluzioneScelta di quanto fare grande il display sempre in gestore gioco
  ALLEGRO_DISPLAY* Drawer::get_display(){
    ALLEGRO_DISPLAY* display=al_create_display(widthMap, heightMap);
  return display;
}

// servirà prima fare un al_clear_to_color();
// e dopo richiamare questa funzione qui su un Drawer
// ovviamente tutto questo nel loop di GestoreGioco
void Drawer::startMap(ALLEGRO_DISPLAY* display,CampoDiGioco* campoDiGioco){
  ObjectStatic* muro = new Muro(widthBitmap,heightBitmap);
  ObjectStatic* scala =  new Scala(widthBitmap,heightBitmap);
  ObjectDynamic* player =  new Player(widthBitmap,heightBitmap);
  ObjectDynamic* nemico =  new Nemico(widthBitmap,heightBitmap);

  for(int i=0; i<18; i++){
    for(int j=0; j<32; j++){
      // la i e la j modificano la colonna e la riga di dove si trova il pg
      // posI posJ è il punto per disegnare l'immagine in base alla dimensione
      int posI=j*widthBitmap;
      int posJ=i*heightBitmap;
      // evito di andare a creare una matrice di app
      switch (campoDiGioco->getElementoMappa(i,j)){
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
        player->draw(posI,posJ,i,j);
          break;
        case 6: // nemico
        nemico->draw(posI,posJ,i,j);
          break;

        default:
          break;
      }

    }
  }
  delete muro;
  delete scala;
  delete player;
  delete nemico;
}


//matrix[i][j];


//Nemico giallo(i*widthBitmap, j*heightBitmap);
