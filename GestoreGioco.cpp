#include"GestoreGioco.h"


GestoreGioco::GestoreGioco() :display(0), event_queue(0),timer(0),bitmapR(0){}

bool GestoreGioco::inizializzatore(){

  if(!al_init()){
    cout<<"ALLEGRO NON INIZIALIZZATO"<<endl;
    return false;
  }

  if(!al_init_image_addon()){
    cout<<"IMAGE ERROR"<<endl;
    return false;
  }

  if(!al_install_mouse()){
    cout<<"MOUSE ERROR"<<endl;
    return false;
  }

  // display=al_create_display(640,480);


  // if(!display){
  //   cout<<"DISPLAY NON INIZIALIZZATO"<<endl;
  //   return false;
  // }

  //al_load_bitmap() ci deve essere tra poco
  // bitmapR = al_create_bitmap(80, 80);
  menuRisoluzioni *start=new menuRisoluzioni();
  string menu= start->startMenu();

  cout<<menu<<endl;

  al_install_keyboard();

  event_queue=al_create_event_queue();

  timer=al_create_timer(1.0/(float)FPS);

  al_register_event_source(event_queue,al_get_keyboard_event_source());
	al_register_event_source(event_queue,al_get_timer_event_source(timer));

  for (int i = 0; i < 6; i++)
		tasti[i] = false;


    // al_set_target_bitmap(bitmapR);
    // al_clear_to_color(al_map_rgb(255, 0, 255));
    // al_set_target_bitmap(al_get_backbuffer(display));
    // al_clear_to_color(al_map_rgb(0,0,0));
    // al_draw_bitmap(bitmapR,0,0,0);

    al_flip_display();

    al_rest(5.0);

    // al_set_target_backbuffer(display);
      //a.draw(25,25);

  return true;

}

GestoreGioco::~GestoreGioco(){
  if(event_queue!=0)
	al_destroy_event_queue(event_queue);
	if(timer!=0)
	al_destroy_timer(timer);
	if(display!=0)
	al_destroy_display(display);
  al_destroy_bitmap(bitmapR);
}



// void GestoreGioco::loop(){
//  do{
//
//   for (int i = 0; i < 6; i++)
//     tasti[i] = false;
//
//   al_start_timer(timer);
//
//   while(1){
//     ALLEGRO_EVENT event;
//     al_wait_for_event(event_queue,&event);
//
//     if(event.type == ALLEGRO_EVENT_KEY_UP){
//       switch (event.keyboard.keycode) {
//         case ALLEGRO_KEY_UP:
//            tasti[UP]=true;
//            break
//         case ALLEGRO_KEY_DOWN:
//           tasti[DOWN]=true;
//           break
//         case ALLEGRO_KEY_RIGHT:
//           tasti[RIGHT]=true;
//           break
//         case ALLEGRO_KEY_LEFT:
//           tasti[LEFT]=true;
//           break
//         case ALLEGRO_KEY_SPACE:
//           tasti[SPACE]=true;
//           break
//         case ALLEGRO_KEY_ESCAPE:
//           tasti[ESCAPE]=true;
//           break
//       }
//     }
//
//     else if (event.type == ALLEGRO_EVENT_KEY_UP)
//     {
//       switch (event.keyboard.keycode)
//       {
//       case ALLEGRO_KEY_UP:
//         tasti[UP] = false;
//         break;
//       case ALLEGRO_KEY_DOWN:
//         tasti[DOWN] = false;
//         break;
//       case ALLEGRO_KEY_RIGHT:
//         tasti[RIGHT] = false;
//         break;
//       case ALLEGRO_KEY_LEFT:
//         tasti[LEFT] = false;
//         break;
//       case ALLEGRO_KEY_SPACE:
//         tasti[SPACE] = false;
//         break;
//       case ALLEGRO_KEY_ESCAPE:
//         tasti[ESCAPE] = false;
//         break;
//       }
//       oggettoCorrente->rilasciaTasto();//funzione in  player
//
//
//   }
//
//
//
//     }//while secondo
//   }while(!gameDone);
// }
