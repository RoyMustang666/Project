#ifndef OBJECTSTATIC_H
#define OBJECTSTATIC_H

#include <iostream>
#include "CampoDiGioco.h"
#include "Definizioni.h"
using namespace std;

class ObjectStatic{

protected:

  int width,height;


  public:
    ObjectStatic(int _width, int _height);

    virtual void draw(int x, int y);


};

#endif
