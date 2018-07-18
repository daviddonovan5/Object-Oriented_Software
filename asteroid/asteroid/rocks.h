/********************************************
 * ROCKS H
 * this file holds the rocks including the
 * large medium and small
 *******************************************/

#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10





#include "flyingObject.h"  // part of the flying Objects Class
#include "velocity.h"

/*********************************************
 * CLASS rocks
 * This holds the common methods for each rock
 ********************************************/
class Rocks: public FlyingObject
{
protected:
    int size;
    
public:
    // Constructors
    Rocks();
    //Rocks(Point point) { }
    
    //Virtual methods
   
    virtual void draw() =0;
    int getSize() { return size;}
   
    
    // virtual void hit(std::vector<Rocks*>* newRocks) = 0;

   
};


/*********************************************
 * CLASS LargeRock
 * 
 *******************************************/


class LargeRock: public Rocks
{
private:
public:
    
    // constructors
    LargeRock();
    
    
    // draws the BigRock
    virtual void draw() {
        drawLargeAsteroid(getPoint(), BIG_ROCK_SPIN);

    }    
    
    
        
    
    
    
};

/*********************************************
 * MediumROck
 *
 ******************************************/
class MediumRock: public Rocks
{
private:
    int hits;
    
public:
    
    MediumRock();
    //draws the MediumRock
    virtual void draw() { }
    
    
    virtual int hit() { return 1;}

};


/*************************************
 * SmallRock
 *
 **************************************/
class SmallRock: public Rocks
{
private:
public:
    
    SmallRock();
    
    virtual void draw(){ }
    virtual int hit()  { return 1; }
};


#endif /* rocks_h */
