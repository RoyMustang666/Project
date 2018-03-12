#include"menuSingoloMulti.h"

menuSingoloMulti::menuSingoloMulti():display(0),button(0),posX(0),posY(0){}

menuSingoloMulti::~menuSingoloMulti(){
  al_destroy_display(display);
  al_destroy_bitmap(button);
  al_destroy_timer(timer);
  al_destroy_event_queue(event_queue);
  // al_destroy_bitmap(buttonMulti);
}

string menuSingoloMulti::sceltaSingoloMulti(string _risoluzione){
  // if(!al_init()){
  //   cout<<"ALLEGRO NON INIZIALIZZATO"<<endl;
  //   return "false";
  // }
  //
  // if(!al_init_image_addon()){
  //   cout<<"ALLEGRO IMAGE NON INIZIALIZZATO"<<endl;
  //   return "false";
  // }

  timer = al_create_timer(1.0 / FPS);
   if(!timer) {
     cout<<"ALLEGRO NON INIZIALIZZATO"<<endl;
     return "false";
   }

  int larghezzaScelta=0;
  int altezzaScelta=0;

  if(_risoluzione=="SD"){
    display=al_create_display(larghezzaSD,altezzaSD);
    larghezzaScelta=larghezzaSD;
    altezzaScelta=altezzaSD;
  }
  if(_risoluzione=="HD"){
    display=al_create_display(larghezzaR,altezzaR);
    larghezzaScelta=larghezzaR;
    altezzaScelta=altezzaR;
  }
  if(_risoluzione=="FH"){
    display=al_create_display(larghezzaFH,altezzaFH);
    larghezzaScelta=larghezzaFH;
    altezzaScelta=altezzaFH;
  }


 if(larghezzaScelta==larghezzaSD && altezzaScelta==altezzaSD){
   button = al_load_bitmap("Images/TitoloLodeRunner.png");
   al_draw_bitmap(button,90,10,0);

   button=al_load_bitmap("Images/Singleplayer.png");
   al_draw_bitmap(button,220,110,0);

   button=al_load_bitmap("Images/Multiplayer.png");
   al_draw_bitmap(button,220,290,0);

 }

 if(larghezzaScelta==larghezzaR && altezzaScelta==altezzaR){
   button = al_load_bitmap("Images/TitoloLodeRunner.png");
   al_draw_bitmap(button,430,10,0);

   button=al_load_bitmap("Images/Singleplayer.png");
   al_draw_bitmap(button,573,152,0);

   button=al_load_bitmap("Images/Multiplayer.png");
   al_draw_bitmap(button,573,536,0);
 }

 if(larghezzaScelta==larghezzaFH && altezzaScelta==altezzaFH){
   button = al_load_bitmap("Images/TitoloLodeRunner.png");
   al_draw_bitmap(button,725,10,0);

   button=al_load_bitmap("Images/Singleplayer.png");
   al_draw_bitmap(button,860,500,0);

   button=al_load_bitmap("Images/Multiplayer.png");
   al_draw_bitmap(button,860,650,0);
 }

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
       if(larghezzaScelta==larghezzaSD && altezzaScelta==altezzaSD){
        if(posX >= 220 && posX <= 440 && posY >= 110 && posY <= 190){
          al_destroy_display(display);
          al_destroy_bitmap(button);
          al_destroy_timer(timer);
          al_destroy_event_queue(event_queue);
          return "SinglePlayer";
        }

         else if(posX >= 220 && posX <= 440 && posY >= 290 && posY <= 370){
           al_destroy_display(display);
           al_destroy_bitmap(button);
           al_destroy_timer(timer);
           al_destroy_event_queue(event_queue);
           return "MultiPlayer";
         }
        }

       if(larghezzaScelta==larghezzaR && altezzaScelta==altezzaR){
        if(posX >= 573 && posX <= 753 && posY >= 152 && posY <= 232){
          al_destroy_display(display);
          al_destroy_bitmap(button);
          al_destroy_timer(timer);
          al_destroy_event_queue(event_queue);
          return "SinglePlayer";
        }

         else if(posX >= 573 && posX <= 773 && posY >= 536 && posY <= 616){
           al_destroy_display(display);
           al_destroy_bitmap(button);
           al_destroy_timer(timer);
           al_destroy_event_queue(event_queue);
           return "MultiPlayer";
         }
        }


       if(larghezzaScelta==larghezzaFH && altezzaScelta==altezzaFH){
        if(posX >= 860 && posX <= 1060 && posY >= 500 && posY <= 580){
          al_destroy_display(display);
          al_destroy_bitmap(button);
          al_destroy_timer(timer);
          al_destroy_event_queue(event_queue);
          return "SinglePlayer";
        }

         else if(posX >= 860 && posX <= 1060 && posY >= 650 && posY <= 730){
           al_destroy_display(display);
           al_destroy_bitmap(button);
           al_destroy_timer(timer);
           al_destroy_event_queue(event_queue);
           return "MultiPlayer";
         }
        }

     }

   }// fine while true

   return "0";

}
