
#include"GestoreGioco.h"


GestoreGioco::GestoreGioco() :display(0),event_queue(0),timer(0),player(0),field(NULL),draw(true){}

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

  // verifico quale è stata la risoluzioneScelta dall'utente
  menuRisoluzioni* menuRis = new menuRisoluzioni();
  string risoluzioneScelta = menuRis->startMenu();
  // cout<<menu<<endl;

  menuSingoloMulti *singoloMulti = new menuSingoloMulti();
  string sceltaSingMulti=singoloMulti->sceltaSingoloMulti(risoluzioneScelta);
  // cout<<singleMulti<<endl;


// creo un drawer dove disegnerò in base alla risoluzioneScelta
  drawer= new Drawer(risoluzioneScelta);
  display = drawer->get_display();



  // creo un campo di gioco dove in base alla risoluzioneScelta
  //il leggiCampoDiGioco si preoccuperà di caricare la mappa della dim corretta

  field =  new CampoDiGioco();
  field->leggiCampoDiGioco(sceltaSingMulti);

  drawer->startMap(display, field);


  player = new Player(drawer->getWidth(),drawer->getHeight());


  al_flip_display();
  // al_rest(5);


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
  delete  player;
  delete field;
  // delete  playerCorrente;
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
            player->onKeyLeft(field);
          if (tasti[RIGHT])
            player->onKeyRight(field);
          if (tasti[UP])
            player->onKeyUp(field);
          if (tasti[DOWN])
            player->onKeyDown(field);
          if (tasti[ESCAPE])
              return;
          // if (tasti[SPACE])
          //   // player->onSpaceBreak(field);
        }

      draw = true;

      if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
          break;



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
          player->onKeyReleased();
        }



        if(draw){

          al_clear_to_color(al_map_rgb(0,0,0));
          drawer->startMap(display,field);
          al_flip_display();
        }



   }//while secondo
  }while(!gameDone);
}
