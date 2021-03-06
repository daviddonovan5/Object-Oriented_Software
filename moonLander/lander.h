#ifndef LANDER_H
#define LANDER_H
#include "point.h"
#include "velocity.h"
class Lander
{

 private:
  Point point;
  Velocity velocity;
  bool alive;
  bool landed;
  int fuel;
  bool thrust;
  
 public:
  // getters & setters 
 Point getPoint() const { return point;}
 void setLanded(bool landed) { this -> landed = landed; }
 
 Velocity getVelocity() const { return velocity; }
 
 bool isAlive() { return alive; }




 bool isLanded()
    {
    return landed;
    }
 int getFuel()
    {
    return fuel;
    }
 bool canThrust()
    {
   return thrust;
    }

 //void setLanded(bool landed)
    {
    this -> landed = landed;
    }

 void setAlive(bool alive)
    {
    this -> alive = alive;
    }
 void setFuel(int fuel)
    {
    this -> fuel = fuel;
    }

 Lander();
  void applyGravity(float gravity);
 void applyThrustLeft();
 void applyThrustRight();
 void applyThrustBottom();
 void advance();
 void draw();
 
};


#endif
