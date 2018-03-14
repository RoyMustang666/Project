#include"GestoreGioco.h"


GestoreGioco::GestoreGioco() :display(0),event_queue(0),timer(0),oggetto(0),oggettoCorrente(0){}

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

  al_set_new_display_flags(ALLEGRO_NOFRAME);

  menuRisoluzioni *start=new menuRisoluzioni();
  string menu= start->startMenu();
  cout<<menu<<endl;

  menuSingoloMulti *SM=new menuSingoloMulti();
  string singleMulti=SM->sceltaSingoloMulti(menu);
  cout<<singleMulti<<endl;

  Drawer *disegna= new Drawer(menu);
  display=disegna->get_display();
  int a=3;
  if(singleMulti=="SinglePlayer")
    disegna->startMap(display, a);

  al_flip_display();
  al_rest(5);


  al_install_keyboard();

  event_queue=al_create_event_queue();

  timer=al_create_timer(1.0/(float)FPS);

  al_register_event_source(event_queue,al_get_keyboard_event_source());
	al_register_event_source(event_queue,al_get_timer_event_source(timer));

  for (int i = 0; i < 6; i++)
		tasti[i] = false;


    al_flip_display();

    //al_rest(5.0);

    // al_set_target_backbuffer(display);
      //a.draw(25,25);

  return true;

}

// FINE INIZIALIZZATOREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

GestoreGioco::~GestoreGioco(){
	al_destroy_event_queue(event_queue);
  al_destroy_timer(timer);
  al_destroy_display(display);
  delete  oggetto;
  delete  oggettoCorrente;
  // al_destroy_bitmap(bitmapR);
}





void GestoreGioco::loop(){
 do{

  for (int i = 0; i < 6; i++)
    tasti[i] = false;

  al_start_timer(timer);

  while(1){
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue,&event);

   if (event.type == ALLEGRO_EVENT_TIMER)
    {
      if(tasti[LEFT])
        oggetto->moveLeft(CampoDiGioco *field);
      if (tasti[RIGHT])
        oggetto->moveRight(CampoDiGioco *field);
      if (tasti[UP])
        oggetto->moveUp(CampoDiGioco *field);
      if (tasti[DOWN])
        oggetto->moveDown(CampoDiGioco *field);
      if (tasti[ESCAPE])
        oggetto->pressExit();
      if (tasti[SPACE])
        oggetto->pressSpace();



      draw = true;
      }
      else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
          break;
        }

      else if (event.type == ALLEGRO_EVENT_KEY_DOWN)
  			{
  				switch (event.keyboard.keycode)
  				{
  				case ALLEGRO_KEY_UP:
  				  tasti[UP] = true;
  					break;
  				case ALLEGRO_KEY_DOWN:
  					tasti[DOWN] = true;
  					break;
  				case ALLEGRO_KEY_RIGHT:
  					tasti[RIGHT] = true;
  					break;
  				case ALLEGRO_KEY_LEFT:
  					tasti[LEFT] = true;
  					break;
  				case ALLEGRO_KEY_SPACE:
  					tasti[SPACE] = true;
  					break;
  				case ALLEGRO_KEY_ESCAPE:
  					tasti[ESCAPE] = true;
  					break;
  				}
  			}
        else if (event.type == ALLEGRO_EVENT_KEY_UP)
        {
          switch (event.keyboard.keycode)
          {
          case ALLEGRO_KEY_UP:
            tasti[UP] = false;
            break;
          case ALLEGRO_KEY_DOWN:
            tasti[DOWN] = false;
            break;
          case ALLEGRO_KEY_RIGHT:
            tasti[RIGHT] = false;
            break;
          case ALLEGRO_KEY_LEFT:
            tasti[LEFT] = false;
            break;
          case ALLEGRO_KEY_SPACE:
            tasti[SPACE] = false;
            break;
          case ALLEGRO_KEY_ESCAPE:
            tasti[ESCAPE] = false;
            break;

          }
          oggetto->onKeyReleased();

        }

            if (draw){
               drawer->getdisplay();
               al_flip_display();
            }
      //oggettoCorrente->rilasciaTasto();//funzione in  player






   }//while secondo
  }while(!gameDone);
}
