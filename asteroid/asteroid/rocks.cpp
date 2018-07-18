#include "rocks.h"
#include "flyingObject.h"  // part of the flying Objects Class
#include "velocity.h"


/***********************************************
 * Rocks
 * sets the default for the Rocks
 ************************************************/

Rocks::Rocks()
{
    alive = true;                           // Rock must be alive
   
    Point myPoint;
    myPoint.setX(random(-200, 200));
    myPoint.setY(random(-200,200));
    setPoint(myPoint);
    
    
    
    Velocity myVelocity;                    // define velocity
    myVelocity.setDx(random(-1,1));
    myVelocity.setDy(random(-2, 2));
    setVelocity(myVelocity);
    
    
}

/***************************************************
 LargeRocks
 * This will set the defult bird
 ************************************************/
LargeRock:: LargeRock()
{
    alive = true;                           // Rock must be alive
    
    Point myPoint;
    myPoint.setX(random(-200, 200));
    myPoint.setY(random(-200,200));
    setPoint(myPoint);
    
    
    
    Velocity myVelocity;                    // define velocity
    myVelocity.setDx(random(-2,2));
    myVelocity.setDy(random(-3, 3));
    setVelocity(myVelocity);

    size = BIG_ROCK_SIZE;
}

/************************************************
 * MediumRock
 * sets defult mediumRock
 *************************************************/

MediumRock::MediumRock()
{
    //Point myPoint(-200, random(-200,200));
    //Velocity myVelocity;
    //myVelocity.setDx(random(2,5));
    
    //if (myPoint.getY() < 0)
     //   myVelocity.setDy(random (0,3));
    //else
      //  myVelocity.setDy(random(-3,0));
			 
    //setVelocity(myVelocity);
    
   
    
}

/*********************************************
 * SmallRock
 * Set Defult
 *********************************************/

SmallRock::SmallRock()
{
}


