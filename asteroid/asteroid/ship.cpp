#include "ship.h"
#include<iostream>

#include "uiDraw.h"
#include <cmath>
/************************************************
 * Rotate Left
 *
 ************************************************/
void Ship:: rotateLeft()
{
    
     rotate += ROTATE_AMOUNT;
     rotate = fmod(rotate, 360.0);
    setRotate(rotate);
    
    
    
}

/************************************************
 * Rotate Right
 *
 ************************************************/
void Ship:: rotateRight()
{

    rotate -= ROTATE_AMOUNT;
    rotate = fmod(rotate, 360.0);
    setRotate(rotate);
}


/***********************************************
 * APPLY THRUST
 * This will apply left thurst
 *
 **********************************************/
void Ship:: shipThrust()
{
    float dx = THRUST_AMOUNT * (-sin(M_PI / 180.0 * rotate));
    float dy = THRUST_AMOUNT * (cos(M_PI / 180.0 * rotate));
   
    velocity.setDx(dx + velocity.getDx());
    velocity.setDy(dy + velocity.getDy());
}

/****************************************
 * ADVANCE
 * this will move the spaceship by setting
 * the x and y points
 *****************************************/
/*
void Ship:: advance()
{
    point.setX(velocity.getDx() + point.getX());
    point.setY(velocity.getDy() + point.getY());
    
    
}
*/

void Ship:: draw()
{
    
    drawShip(point, rotate, true);
    
  
}

Ship::Ship()
{
    alive = true;
    rotate = 90;
    
}
