#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>

using namespace std;

class Object{

  public:
    virtual void setPositionX();
    virtual void setPositionY();

    virtual int getPositionX();
    virtual int getPositionY();

    virtual void draw();


};

#endif
