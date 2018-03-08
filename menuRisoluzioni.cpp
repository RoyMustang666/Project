#include "menuRisoluzioni.h"

menuRisoluzioni::menuRisoluzioni():display(0),buttonR(0),buttonFH(0),buttonSD(0),posX(0),posY(0){}

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

  timer = al_create_timer(1.0 / FPS);
   if(!timer) {
     cout<<"ALLEGRO NON INIZIALIZZATO"<<endl;
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

  buttonSD=al_load_bitmap("Images/button_SD.png");
  buttonR=al_load_bitmap("Images/button_RHD.png");
  buttonFH=al_load_bitmap("Images/button_FHD.png");

  //colore sfondo 51 25 0
  //colore tasti 102 51 0

  al_draw_bitmap(buttonSD,220,110,0);
  al_draw_bitmap(buttonR,220,200,0);
  al_draw_bitmap(buttonFH,220,290,0);
  al_flip_display();

  al_set_target_bitmap(al_get_backbuffer(display));

   event_queue = al_create_event_queue();
   if(!event_queue) {
       cout<<"ALLEGRO NON INIZIALIZZATO"<<endl;
      return "-1";
   }

   al_register_event_source(event_queue, al_get_display_event_source(display));

   al_register_event_source(event_queue, al_get_timer_event_source(timer));

   al_register_event_source(event_queue, al_get_mouse_event_source());



   al_start_timer(timer);

   while(1)
   {
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);

      if(ev.type == ALLEGRO_EVENT_TIMER) {
         redraw = true;
      }
      else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         break;
      }
      else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
              ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {

         posX = ev.mouse.x;
         posY = ev.mouse.y;
      }
      else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        if(posX >= 220 && posX <= 440 && posY >= 100 && posY <= 180)
             return "SD";

        else if(posX >= 220 && posX <= 440 && posY >= 190 && posY <= 270)
              return "HD";

        else if(posX >= 220 && posX <= 440 && posY >= 280 && posY <= 360)
              return "FH";
      }

      if(redraw && al_is_event_queue_empty(event_queue)) {
         redraw = false;

      }
   }

   return "0";
}
