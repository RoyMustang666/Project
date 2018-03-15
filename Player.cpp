#include "Player.h"

//player costructor
  Player::Player(int width, int height):ObjectDynamic(width, height){
    riga = 16;
    colonna = 22;
    player = al_load_bitmap("Images/Omino.png");
    ALLEGRO_BITMAP* playerScaled= al_create_bitmap(width,height);
    // CREO UNA BITMAP TEMPORANEA IN CUI SALVO IL VALORE PRECEDENTE
    ALLEGRO_BITMAP* prevBitmap=al_get_target_bitmap();
      cout<<"entrato"<<endl;
    al_set_target_bitmap(playerScaled);
    al_draw_scaled_bitmap(player,
        0,0,
        al_get_bitmap_width(player),
        al_get_bitmap_height(player),
        0,0,
        width, height,
        0
      );
    al_flip_display();
    al_set_target_bitmap(prevBitmap);
    al_destroy_bitmap(player);
    player=playerScaled;

// serve per i tasti e i movimenti
// costruttore....
    direzioni[LEFT]=true;
    direzioni[RIGHT]=true;
    direzioni[UP]=false;
    direzioni[DOWN]=false;

    widthBitmap=width;
    heightBitmap=height;
  }

//player destructor
  Player::~Player(){
    al_destroy_bitmap(player);
  }

//draw player
  void Player::draw(int x, int y, int _riga, int _colonna){
    al_draw_bitmap(player,x,y,0);
    // questi servono ad aggiornare le posizioni del player sulla x e la y
    riga=_riga;
    colonna=_colonna;
  }

  void Player::setRiga(int _riga){
    riga=_riga;
  }
  void Player::setColonna(int _colonna){
    colonna=_colonna;
  }

  int Player::getRiga()const{
    return riga;
  }

  int Player::getColonna()const{
    return colonna;
  }

  void Player::onKeyLeft(CampoDiGioco *field){
    if(direzioni[LEFT]){
     direzioni[RIGHT] = direzioni[UP] = direzioni[DOWN] = false;
     if(field->getElementoMappa(riga, colonna-1)== 0 || field->getElementoMappa(riga, colonna-1)==4){
       field->setElementoMatrice(riga, colonna-1, 5);
       field->setElementoMatrice(riga, colonna, 0);
     }
   }
  }

  void Player::onKeyRight(CampoDiGioco *field){
    if(direzioni[RIGHT]){
     direzioni[LEFT] = direzioni[UP] = direzioni[DOWN] = false;
     if(field->getElementoMappa(riga, colonna+1)== 0 && field->getElementoMappa(riga, colonna+1)==4){
       field->setElementoMatrice(riga, colonna+1, 5);
       field->setElementoMatrice(riga, colonna, 0);
     }
   }
  }

   void Player::onKeyUp(CampoDiGioco *field){
    if(direzioni[UP]){
     direzioni[RIGHT] = direzioni[LEFT] = direzioni[DOWN] = false;
     if(field->getElementoMappa(riga-1, colonna)== 0 || field->getElementoMappa(riga-1, colonna)==4){
       field->setElementoMatrice(riga-1, colonna, 5);
       field->setElementoMatrice(riga-1, colonna, 0);
     }
    }
  }

  void Player::onKeyDown(CampoDiGioco *field){
    if(direzioni[DOWN]){
    direzioni[RIGHT] = direzioni[UP] = direzioni[LEFT] = false;
    if(field->getElementoMappa(riga+1, colonna)== 0 || field->getElementoMappa(riga+1, colonna)==4){
      field->setElementoMatrice(riga+1, colonna, 5);
      field->setElementoMatrice(riga+1, colonna, 0);
      }
     }
   }

  void Player::onKeyReleased(){
     direzioni[RIGHT] = direzioni[UP] = direzioni[DOWN] = direzioni[LEFT] = false;
  }
