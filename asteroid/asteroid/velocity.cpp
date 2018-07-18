#include "velocity.h"

#include <iostream>
using namespace std;


Velocity operator+(const Velocity & lhs, const Velocity & rhs)
{
    Velocity sum;
    
    sum.setDx(lhs.getDx() + rhs.getDx());
    sum.setDy(lhs.getDy() + rhs.getDy());
    
    return sum;
}

Velocity& operator+=(Velocity & lhs, const Velocity & rhs)
{
    lhs.setDx(lhs.getDx() + rhs.getDx());
    lhs.setDy(lhs.getDy() + rhs.getDy());
    
    return lhs;
}

