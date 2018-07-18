#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40


#include "flyingObject.h"
#include <cmath>    // used for sin, cos, and M_PI



class Bullet : public FlyingObject
{
    
private:
    int time;
    
public:
    // constructor
    Bullet(){alive = true; time = 1; }
    
    // draws the bullet
    void draw();
    
    void fire(Point point, float angle)
    {
        
        this -> point = point;
            
        velocity.setDx (BULLET_SPEED * (-sin(M_PI / 180.0 * angle)));
        velocity.setDy (BULLET_SPEED * (cos(M_PI / 180.0 * angle)));
        
      
        
        
        
    }
};

#endif 
