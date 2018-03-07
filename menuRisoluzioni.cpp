#include "menuRisoluzioni.h"

menuRisoluzioni::menuRisoluzioni():display(0),buttonR(0),buttonFH(0),buttonSD(0){}

menuRisoluzioni::~menuRisoluzioni(){
  al_destroy_display(display);
  al_destroy_bitmap(buttonR);
  al_destroy_bitmap(buttonFH);
  al_destroy_bitmap(buttonSD);;
}

string startMenu(){
  if(!al_init()){
    cout<<"ALLEGRO NON INIZIALIZZATO"<<endl;
    return false;
  }

  display=al_create_display(640,480);

  if(!display){
    cout<<"DISPLAY NON INIZIALIZZATO"<<endl;
    return false;
  }
  al_clear_to_color(al_map_rgb(51, 25, 0));

  al_init_mouse();

  if(!al_init_mouse()){
    cout<<"MOUSE NON INIZIALIZZATO"<<endl;
    return false;
  }

  buttonR=al_load_bitmap("");
  buttonFH=al_load_bitmap("");
  buttonSD=al_load_bitmap("");

  //colore sfondo 51 25 0
  //colore tasti 102 51 0

  al_set_target_bitmap(buttonR);
  al_clear_to_color(al_map_rgb(102,51,0));

  al_set_target_bitmap(buttonSD);
  al_clear_to_color(al_map_rgb(102,51,0));

  al_set_target_bitmap(buttonFH);
  al_clear_to_color(al_map_rgb(102,51,0));

  al_set_target_bitmap(al_get_backbuffer(display));

  al_draw_bitmap(buttonR,269,9,0);
  al_draw_bitmap(buttonSD,269,69,0);
  al_draw_bitmap(buttonFH,269,129,0);

  al_flip_display();

  al_rest(4.0);

  posX=mouse_x;
  posY=mouse_y;

  if(mouse_b&1 && posX >= buttonSD_x && posX <= buttonSD_x + buttonSD_w && posY >= buttonSD_y && posY <= buttonSD_y + buttonSD_h)
	     return "SD";


  if(mouse_b&1 && posX >= button_x && posX <= button_x + button_w && posY >= button_y && posY <= button_y + button_h)
        return "HD";

  if(mouse_b&1 && posX >= button_x && posX <= button_x + button_w && posY >= button_y && posY <= button_y + button_h)
        return "FH";




}
