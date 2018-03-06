#include "Functions.h"

ALLEGRO_BITMAP* Functions::resize_bitmap(ALLEGRO_BITMAP* pointer, int w, int h, int originX, int originY){
  al_init_image_addon();
  ALLEGRO_BITMAP *resized_bitmap, *prev_target;

  cout<<"after just entering in function: "<<al_get_target_bitmap()<<endl; //controll cout target_bitmap

  // 1. create a temporary bitmap of size we want
  //resized_bitmap = al_create_bitmap(w, h);
  resized_bitmap = al_create_bitmap(w,h);

  if(!resized_bitmap){
    return NULL;
  }

  // 2. load the bitmap at the original size
  // loaded_bitmap = al_load_bitmap(filename);
  // if (!loaded_bitmap)
  // {
  //    al_destroy_bmp(resized_bitmap);
  //    return NULL;
  // }

  // 3. set the target bitmap to the resized bitmap
  prev_target = al_get_target_bitmap(); //save old target in an ALLEGRO_BITMAP pointer
  al_set_target_bitmap(resized_bitmap); //set new bitmap target

  cout<<"Changed pointer bitmap: "<<al_get_target_bitmap()<<endl;

  // 4. copy the loaded bitmap to the resized bitmap
  al_draw_scaled_bitmap(pointer,
     originX, originY,                                // source origin (0,0)
     al_get_bitmap_width(pointer),     // source width
     al_get_bitmap_height(pointer),    // source height
     originX, originY,                                // target origin (0,0)
     w, h,                                // target dimensions
     0                                    // flags (same as source)
  );
  al_flip_display();
  // 5. restore the previous target and clean up
  al_set_target_bitmap(prev_target); //re-set old target
  //al_destroy_loaded_bmp(pointer); //destroy old pointer
  return resized_bitmap; //return new ALLEGRO_BITMAP pointer
}

//load image
//resize
//upload on display
