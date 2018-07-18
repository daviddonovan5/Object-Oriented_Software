#include "lander.h"

#include "uiDraw.h"
/************************************************
 * APPLYGRAVITY
 * This will apply gravity to the spaceship 
 ************************************************/
void Lander:: applyGravity(float gravity)
{
  float change =  velocity.getDy() - gravity;

  velocity.setDy(change);
  
}

/***********************************************
 * APPLY THRUSTLEFT
 * This will apply left thurst 
 * It will not work if fuel is at 0
 * Will also deduct fuel by 1
 **********************************************/
void Lander:: applyThrustLeft()
{
  if(fuel > 0)
    {
  float change =  velocity.getDx() + .1;

  velocity.setDx(change);
  fuel -= 1;
    }
  else
    {
    thrust = false;
    fuel = 0;
    }
}

/*********************************************
 * APPLY THRUST RIGHT
 * This will apply thrust to the right 
 * and deduct 1 unit of fuel but will stop 
 * if out of fuel. 
 ********************************************/
void Lander:: applyThrustRight()
{
  if (fuel >0)
    {
  float change =  velocity.getDx() - .1;

  velocity.setDx(change);
  fuel -=1;
    }
  else
    {
    thrust = false;
    fuel = 0;
    }
}

/***************************************
 * APPLY THRUST BOTTOM
 * This will fight gravity, but will use 
 * three units of fuel.  Will not work if
 * of fuel 
 ****************************************/ 
void Lander:: applyThrustBottom()
{
  if (fuel > 0)
    {
  float change =  velocity.getDy() + .3;

  velocity.setDy(change);
  fuel -= 3;
    }
  else
    {
    thrust = false;
    fuel = 0;
    }
}

/****************************************
* ADVANCE
* this will move the spaceship by setting 
* the x and y points 
*****************************************/
void Lander:: advance()
{
  point.setX(velocity.getDx() + point.getX());
  point.setY(velocity.getDy() + point.getY());

}

void Lander:: draw()
{
  drawLander(point);
}

Lander::Lander()
{
  alive = true;
  landed= false;
  fuel = 500;
  thrust = true;
}
