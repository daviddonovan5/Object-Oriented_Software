#include "flyingObject.h"


//kills the object

void FlyingObject::kill()
{
    alive = false;
}

// moves the flying object

void FlyingObject::advance()
{
       point.setX(velocity.getDx() + point.getX());
       point.setY(velocity.getDy() + point.getY());
    
    if (point.getX() > 200)
        point.setX(-200);
    if (point.getX() < -200)
        point.setX(200);
    
    if (point.getY() > 200)
        point.setY(-200);
    
    if (point.getY() < -200)
        point.setY(200);
    
}
