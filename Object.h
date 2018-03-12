#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>

using namespace std;

class Object{

protected:

  int width,height;

  public:
    Object(int _width, int _height);
    // virtual void setPositionX();
    // virtual void setPositionY();
    //
    // virtual int getPositionX();
    // virtual int getPositionY();

    virtual void draw(int x, int y);


};

#endif
