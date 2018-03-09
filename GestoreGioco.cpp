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

  menuRisoluzioni *start=new menuRisoluzioni();
  string menu= start->startMenu();
  cout<<menu<<endl;

  menuSingoloMulti *SM=new menuSingoloMulti();
  string singleMulti=SM->sceltaSingoloMulti(menu);
  cout<<singleMulti<<endl;



  al_install_keyboard();

  event_queue=al_create_event_queue();

  timer=al_create_timer(1.0/(float)FPS);

  al_register_event_source(event_queue,al_get_keyboard_event_source());
	al_register_event_source(event_queue,al_get_timer_event_source(timer));

  for (int i = 0; i < 5; i++)
		tasti[i] = false;


    al_flip_display();

    //al_rest(5.0);

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
//    if (event.type == ALLEGRO_EVENT_TIMER)
//     {
//       if(tasti[LEFT])
//         oggettoCorrente->moveLeft();
//       if (tasti[RIGHT])
//         oggettoCorrente->moveRight();
//       if (tasti[UP])
//         oggettoCorrente->moveUp();
//       if (tasti[DOWN])
//         oggettoCorrente->moveDown();
//       if (tasti[ESCAPE])
//         oggettoCorrente->pressExit();
//       if (tasti[SPACE])
//         oggettoCorrente->pressSpace();
//
//       //oggettoCorrente->update();aggiorna il movimento
//
//       draw = true;
//     }
//         if (draw){
//           oggettoCorrente->render();
//           al_flip_display();
//          }
//       //oggettoCorrente->rilasciaTasto();//funzione in  player
//
//
//
//
//
//
//     }//while secondo
//   }while(!gameDone);
// }
