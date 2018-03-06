#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

class Functions{
//Funcion to resize bitmap images
	public:
		static ALLEGRO_BITMAP* resize_bitmap(ALLEGRO_BITMAP *pointer, int w, int h, int originX, int originY);
};
#endif
