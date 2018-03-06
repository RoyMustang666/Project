#include "Player.h"

//player costructor
  Player::Player(int _x, int _y){
    player = al_load_bitmap("Images/omino2.png");
  }

//player destructor
  Player::~Player(){
    al_destroy_bitmap(player);
  }

//draw player
  void Player::draw(int x, int y){
    al_draw_bitmap(player, x, y, 0);
    // if(!al_draw_bitmap)
    //   cout<<"NON CARICA PLAYER"<<endl;
  }
