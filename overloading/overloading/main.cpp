//
//  main.cpp
//  overloading
//
//  Created by David Donovan on 4/10/17.
//  Copyright © 2017 David Donovan. All rights reserved.
//

#include <iostream>
using namespace std;


void displayGPA(float gpa)
{
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(1);
    cout << gpa;
}


void displayMoney(float money)
{
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(2);
    cout << "$" << money;
}


void display(void(*pDisplay)(float), float value){
    
    cout << "The answer is: ";
    
    pDisplay(value);
    cout << endl;
}

int main (){
    
    float value;
    cout << "What is the amount? ";
    cin >> value;
    
    char input;
    cout << "Is this money (y/n)";
    cin  >> input;
    
    void (*pDisplay)(float);
   
    if (input == 'Y' || input == 'y')
        pDisplay = displayMoney;
    else
        pDisplay = displayGPA;

    display(pDisplay, value);
    
}
