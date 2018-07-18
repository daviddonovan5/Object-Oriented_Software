//
//  main.cpp
//  exceptions
//
//  Created by David Donovan on 4/5/17.
//  Copyright © 2017 David Donovan. All rights reserved.
//



#include <iostream>
#include <string>
using namespace std;

void exceptionalFunction() throw(int, float, string, char);

int main() {
    try {
        exceptionalFunction();
        cout << "Nothing was thrown\n";
        
    } catch (int integer) {
        cout << "an integer was caught\n";
    }
    catch(float floatingPoint)
    {
    cout << "a floating number was caught\n";
    }
    catch(string text)
    {
        cout << "a string text was caught\n";
    }
    catch(...)
    {
        cout << "Error: Unexpected item thrown\n";
    }
    
    
    return 0;
}


int prompt()
{
    cout << "Which type of exception would you like to throw?\n";
    cout << "\t1. Integer\n";
    cout << "\t2. Float\n";
    cout << "\t3. String\n";
    cout << "\t4. Nothing at all, thank you!\n";
    
    int input;
    cin >> input;
    
    return input;
}


void exceptionalFunction() throw(int, float, string, char)
{
    switch(prompt())
    {
        case 1:
            throw 0;
        case 2:
            throw float(0.0);
        case 3:
            throw string ("zero");
        case 4:
            break;
        default:
            throw('0');
            
    }
     cout << "End of the exceptional function\n";
}
