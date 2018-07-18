#include "bullet.h"

void Bullet :: draw() {
   
    time ++;
    
    if (time == 40)
    {
        kill();
        time = 1;
    }
    drawDot(point);

}
