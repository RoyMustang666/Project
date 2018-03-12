#include "menuRisoluzioni.h"

menuRisoluzioni::menuRisoluzioni():display(0),button(0),posX(0),posY(0){}

//--------------------------------------//

menuRisoluzioni::~menuRisoluzioni(){
  al_destroy_display(display);
  al_destroy_bitmap(button);
  al_destroy_event_queue(event_queue);
  al_destroy_timer(timer);

}

//--------------------------------------//

string menuRisoluzioni::startMenu(){

  timer = al_create_timer(1.0 / FPS);
   if(!timer) {
     cout<<"ALLEGRO NON INIZIALIZZATO"<<endl;
     return "false";
   }

  display=al_create_display(larghezzaSD,altezzaSD);

  if(!display){
    cout<<"DISPLAY NON INIZIALIZZATO"<<endl;
    return "false";
  }

  //colore sfondo 51 25 0
  //colore tasti 102 51 0

  button=al_load_bitmap("Images/risoluzioneSD.png");
  al_draw_bitmap(button,220,110,0);

  button=al_load_bitmap("Images/risoluzioneHDR.png");
  al_draw_bitmap(button,220,200,0);

  button=al_load_bitmap("Images/risoluzioneFHD.png");
  al_draw_bitmap(button,220,290,0);

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

// -------------------------------------------------------------------------------
                          // CODA EVENTI
// -------------------------------------------------------------------------------

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
        if(posX >= 220 && posX <= 440 && posY >= 110 && posY <= 190){
          al_destroy_display(display);
            return "SD";
           }

        else if(posX >= 220 && posX <= 440 && posY >= 200 && posY <= 280){
          al_destroy_display(display);
              return "HD";
            }

        else if(posX >= 220 && posX <= 440 && posY >= 290 && posY <= 370){
          al_destroy_display(display);
              return "FH";
            }

      }

      if(redraw && al_is_event_queue_empty(event_queue)) {
         redraw = false;

      }
   }
   return "0";
}
