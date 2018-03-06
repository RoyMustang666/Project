#include "Player.h"

//player costructor
  Player::Player(int _x, int _y):positionX(_x),positionY(_y){
    player = al_load_bitmap("Images/Mario_8Bit.png");
  }

//player destructor
  Player::~Player(){
    al_destroy_bitmap(player);
  }

//draw player
  void Player::draw(int x, int y){

    al_draw_scaled_bitmap(player, x, y, al_get_bitmap_width(player), al_get_bitmap_height(player), 150, 150, 250, 250, 0);

  }

  void Player::setPositionX(int x){
      positionX=x;
  }
  void Player::setPositionY(int y){
      positionY=y;
  }

  int Player::getPositionX()const{return positionX;}
  int Player::getPositionY()const{return positionY;}
