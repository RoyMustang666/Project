#include <iostream>
#include <allegro5/allegro.h>
#include "Nemico.h"
#include "Player.h"

using namespace std;

int main(){
    //Possibilita' di scegliere la difficolta': facile (1vs1), medio (1vs2), difficile (1vs3);

    if(!al_init()){
      cout<<"ALLEGRO NON INIZIALIZZATO"<<endl;
      return 1;
    }

    al_init_image_addon();

    ALLEGRO_DISPLAY* display = al_create_display(500,500);

    if(!display){
      cout<<"DISPLAY NON INIZIALIZZATO"<<endl;
      return 2;
    }

    int posX=16, posY=16;

    Nemico a(posX,posY); // (x,y) where to draw
    //Player b(30,30);
    Nemico b(posX, posY);

    a.draw(50, 50); // new dimensions
    // al_rest(5.0);
    // al_flip_display();
    //b.draw_only(posX, posY);



    // al_rest(5.0);

    //b.draw(30,30);

    al_flip_display();


    al_rest(10.0);


    // al_set_target_backbuffer(display);
    al_destroy_display(display);

    return 0;
}
