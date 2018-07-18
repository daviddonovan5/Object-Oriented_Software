#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5



#include "point.h"
#include "velocity.h"
#include "flyingObject.h"
class Ship : public FlyingObject
{
    
private:
    //Point point;
    //Velocity velocity;
    //bool alive;
    bool thrust;
    float rotate;
    
public:
    // getters & setters
    Point getPoint() const       { return point;}
    
    Velocity getVelocity() const { return velocity; }
    
    bool isAlive()               { return alive; }
    bool canThrust()             { return thrust; }
    void setAlive(bool alive)    { this -> alive = alive;}
    
    void setRotate(float rotate)   { this -> rotate = rotate;}
    int  getRotate()       const { return rotate;}
    
    Ship();
    
    // methods
    void shipThrust();
    void rotateLeft();
    void rotateRight();
    
    //void advance();
    void draw();
    
};



#endif /* ship_h */
