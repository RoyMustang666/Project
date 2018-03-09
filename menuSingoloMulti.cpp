#include"menuSingoloMulti.h"

menuSingoloMulti::menuSingoloMulti():display(0),buttonSingolo(0),buttonMulti(0),posX(0),posY(0){
}

menuSingoloMulti::~menuSingoloMulti(){
  al_destroy_display(display);
  al_destroy_bitmap(buttonSingolo);
  al_destroy_bitmap(buttonMulti);
}

string menuSingoloMulti::sceltaSingoloMulti(string _risoluzione){
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

  buttonSingolo=al_load_bitmap("Images/Wall.png");
  buttonMulti=al_load_bitmap("Images/Wall.png");

 if(larghezzaScelta==larghezzaSD && altezzaScelta==altezzaSD){
   al_draw_bitmap(buttonSingolo,220,110,0);
   al_draw_bitmap(buttonMulti,220,290,0);
 }

 if(larghezzaScelta==larghezzaR && altezzaScelta==altezzaR){
   al_draw_bitmap(buttonSingolo,,,0);
   al_draw_bitmap(buttonMulti,,,0);
 }

 if(larghezzaScelta==larghezzaFH && altezzaScelta==altezzaFH){
   al_draw_bitmap(buttonSingolo,,,0);
   al_draw_bitmap(buttonMulti,,,0);
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
        if(posX >= 220 && posX <= 440 && posY >= 100 && posY <= 180)
             return "SinglePlayer";

         else if(posX >= 220 && posX <= 440 && posY >= 280 && posY <= 360)
             return "MultiPlayer";
        }

       if(larghezzaScelta==larghezzaR && altezzaScelta==altezzaR){
        if()
             return "SinglePlayer";

         else if()
             return "MultiPlayer";
        }

       if(larghezzaScelta==larghezzaFH && altezzaScelta==altezzaFH){
        if()
             return "SinglePlayer";

         else if()
             return "MultiPlayer";
        }

     }

   }

   return "0";

}
