/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"


#include <limits>
#include <algorithm>
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include <vector>

using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5


/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br)
: topLeft(tl), bottomRight(br)
{
    
    
    
    for (int i = 0; i < 5; i++)
    {
        Rocks* newRock;
        newRock = new LargeRock();
        rocks.push_back(newRock);
        
        
    }
    

    
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
    
    
    
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
    
    advanceRocks();
    advanceBullets();
    advanceShip();
    handleCollisions();
}


    


/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game :: advanceBullets()
{
    // Move each of the bullets forward if it is alive
    for (int i = 0; i < bullets.size(); i++)
    {
        if (bullets[i]->isAlive())
       {
            // this bullet is alive, so tell it to move forward
            bullets[i]->advance();
            
            if (!isOnScreen(bullets[i]->getPoint()))
            {
                // the bullet has left the screen
               bullets[i]->kill();
            }
            
        }
    }
}


void Game :: advanceRocks()
{
 
    for (vector <Rocks*> :: iterator it = rocks.begin(); it != rocks.end(); ++it)
    {
        
        (*it) -> advance();
        
    }

    
 
    
    
    
}
void Game :: advanceShip(){
    
    ship.advance();
}
    
/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game :: isOnScreen(const Point & point)
{
    return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
            && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
            && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
            && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a bird and a bullet.
 **************************************************************************/

void Game :: handleCollisions()
{
 
    for (int i = 0; i < rocks.size(); i++)
    {
        
     if (ship.isAlive() == true && getClosestDistance(ship, *rocks[i]) < 10 + rocks[i]->getSize())
     {
         ship.kill();
         
        
     }

        for (int j = 0; j < bullets.size(); j++)
        {
            if ( bullets[j]-> isAlive()== true && getClosestDistance(*bullets[j], *rocks[i]) < 1 + rocks[i] ->getSize())
            {
                rocks[i] -> kill();
            bullets[j] -> kill();
            }
            }
     
    }
            
    

 }

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/

void Game :: handleInput(const Interface & ui)
{

    // Change the rotation of the ship
    if (ui.isLeft())
    {
        
        ship.rotateLeft();
    }
    
    if (ui.isRight())
    {
        ship.rotateRight();
    }
    if (ui.isUp())
    {
        ship.shipThrust();
    }

   

    
    // Check for "Spacebar
    if (ui.isSpace())
    {
        
        Bullet* newBullet = new Bullet;
        newBullet->fire(ship.getPoint(), ship.getRotate());
        
        bullets.push_back(newBullet);
}
 
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
    for (vector <Rocks*> :: iterator it = rocks.begin(); it != rocks.end(); ++it)
    {
        
        (*it)->draw();
        
    }
    // draw ship
    
    if (ship.isAlive())
    ship.draw();
   
    
    // draw the bullets, if they are alive
    for (int i = 0; i < bullets.size(); i++)
    {
        if (bullets[i]->isAlive())
        {
            bullets[i]->draw();
        }
    }
    
    // Put the score on the screen
    //Point scoreLocation;
    //scoreLocation.setX(topLeft.getX() + 5);
    //scoreLocation.setY(topLeft.getY() - 5);
    
    //drawNumber(scoreLocation, score);
    
}



/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}


