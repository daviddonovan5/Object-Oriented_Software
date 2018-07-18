#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity
{
 private:
  float dx;
  float dy;
  
 public:
  float getDx() const
  {
    return dx;
  }
  float getDy() const
  {
    return dy;
  }
  void setDx(float dx)
  {
    this -> dx = dx;
  }
  void setDy(float dy)
  {
    this -> dy =dy;
  }
  Velocity()
    {
      dx = 0;
      dy =0;
    }
  
};
#endif
