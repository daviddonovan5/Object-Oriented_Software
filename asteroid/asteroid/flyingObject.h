#ifndef flyingObject_h
#define flyingObject_h



#include <iostream>
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"


class FlyingObject
{
protected:
    Point point;
    Velocity velocity;
    bool alive;
    
public:
    
    FlyingObject() {};
    //Getters
    
    Point    getPoint    () const    { return point;   }
    Velocity getVelocity () const    { return velocity;}
    bool     isAlive     () const    { return alive;   }
    
    //Setters
    void setPoint   (Point point)    {this -> point = point;}
    void setVelocity(Velocity velocity) {this -> velocity = velocity;}
    
    // Methods
    void kill();
    void advance();
    
};

#endif






