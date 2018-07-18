//
//  main.cpp
//  Struct
//
//  Created by David Donovan on 4/7/17.
//  Copyright © 2017 David Donovan. All rights reserved.
//

#include <iostream>
using namespace std;

struct Position {
    
    float latitude;
    float longitude;
    int altitude;
    
};


void display (const Position & pos);
void prompt (Position & pos);
void promptPointer(Position * pos);



int main() {

    Position pos1;
    prompt(pos1);
    
    display(pos1);
    
    Position pos2 =
    {                             // use curly braces to surround the values
        43.82937,                  // latitude member variable
        -111.7828,                 // longitude
        4865                       // elevation
    };
    
    pos1 = pos2;
    
    cout << "new value" << endl;;
    display(pos1);
    cout << endl;
    promptPointer(& pos1);
    
    
    
    return 0;
}

void display(const Position & pos)
{
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(4);

    cout << "("  << pos.latitude     // reference each member variable with the
    << ", " << pos.longitude    //     dot operator.  Since the variable is
    << ", " << pos.altitude     //     a const, there is no chance of
    << ")";
}


void prompt(Position & pos)
{
    cout << "Please enter the position as latitude longitude altitude: ";
    cin  >> pos.latitude
    >> pos.longitude
    >> pos.altitude;
}

void promptPointer(Position * pPos)
{
    cout << "Please enter the position as latitude longitude altitude: ";
    cin  >> pPos->latitude
    >> pPos->longitude
    >> pPos->altitude;
    
}
