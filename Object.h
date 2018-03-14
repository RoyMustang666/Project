#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include "CampoDiGioco.h"
using namespace std;

class Object{

protected:

  int width,height;

  public:
    Object(int _width, int _height);

    virtual void onKeyLeft(CampoDiGioco *field);
  	virtual void onKeyRight(CampoDiGioco *field);
  	virtual void onKeyUp(CampoDiGioco *field);
  	virtual void onKeyDown(CampoDiGioco *field);
  	virtual void onKeyReleased();
    virtual void draw(int x, int y, int _riga, int _colonna);


};

#endif
