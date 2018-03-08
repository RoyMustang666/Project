#include "menuRisoluzioni.h"

menuRisoluzioni::menuRisoluzioni():display(0),buttonR(0),buttonFH(0),buttonSD(0){}

//--------------------------------------//

menuRisoluzioni::~menuRisoluzioni(){
  al_destroy_display(display);
  al_destroy_bitmap(buttonR);
  al_destroy_bitmap(buttonFH);
  al_destroy_bitmap(buttonSD);;
}

//--------------------------------------//

string menuRisoluzioni::startMenu(){
  if(!al_init()){
    cout<<"ALLEGRO NON INIZIALIZZATO"<<endl;
    return "false";
  }

  if(!al_init_image_addon()){
    cout<<"ALLEGRO IMAGE NON INIZIALIZZATO"<<endl;
    return "false";
  }

  display=al_create_display(640,480);

  if(!display){
    cout<<"DISPLAY NON INIZIALIZZATO"<<endl;
    return "false";
  }
  //al_clear_to_color(al_map_rgb(51, 25, 0));

  if(!al_install_mouse()){
    cout<<"MOUSE NON INIZIALIZZATO"<<endl;
    return "false";
  }

  extern volatile int mouse_x;
  extern volatile int mouse_y;
  extern volatile int mouse_b;

  buttonSD=al_load_bitmap("Images/button_SD.png");
  buttonR=al_load_bitmap("Images/button_RHD.png");
  buttonFH=al_load_bitmap("Images/button_FHD.png");

  //colore sfondo 51 25 0
  //colore tasti 102 51 0

  al_draw_bitmap(buttonSD,220,110,0);
  al_draw_bitmap(buttonR,220,200,0);
  al_draw_bitmap(buttonFH,220,290,0);

  al_flip_display();

  posX=mouse_x;
  posY=mouse_y;
  // int mpos=mouse_pos;
  // posX=mouse_pos >> 16;
  // posY= mouse_pos & 0x0000ffff;

  // if(mouse_b&1 && posX >= 269 && posX <= 469 && posY >= 9 && posY <= 89)
	//      return "SD";
  //
  // if(mouse_b&1 && posX >= 269 && posX <= 469 && posY >= 99 && posY <= 179)
  //       return "HD";
  //
  // if(mouse_b&1 && posX >= 269 && posX <= 469 && posY >= 189 && posY <= 269)
  //       return "FH";

}
