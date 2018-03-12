#include "Player.h"

//player costructor
  Player::Player(int width, int height):Object(width, height){
    player = al_load_bitmap("Images/Wall_001.png");
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
  }

//player destructor
  Player::~Player(){
    al_destroy_bitmap(player);
  }

//draw player
  void Player::draw(int x, int y){
    al_draw_bitmap(player,x,y,0);
  }

  // void Player::setPositionX(int x){
  //     positionX=x;
  // }
  // void Player::setPositionY(int y){
  //     positionY=y;
  // }
  //
  // int Player::getPositionX()const{return positionX;}
  // int Player::getPositionY()const{return positionY;}
