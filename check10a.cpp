/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother mccracken, CS165
* Author:
*    your David Donovan
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/
#include <vector>
#include <iostream>
#include <string>

using namespace std;




/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
    vector<int> numbers;

    
    int num;
    cout << "Enter int: " ;
    
    cin >> num;
    
    while (num !=0)
    {
        numbers.push_back(num);
        cout << "Enter int: ";
        cin >> num;
        
    }
    
    cout << "Your list is:\n";
    
    for (vector<int>::iterator it = numbers.begin(); it < numbers.end(); it++)
    {
        cout << *it <<endl;
    }

    cout << endl;
    vector<string> words;
    cout << "Enter string: ";
    string text;
    cin >> text;
    while (text != "quit")
    {
        words.push_back(text);
        cout << "Enter string: ";
      cin >> text;
    }
    
    // loop through the list
    cout << "The list forwards:\n";
    for (vector <string> :: iterator it = words.begin();
         it < words.end();
         it++)
        cout << "\t" << *it << endl;
    
    
    
   return 0;
}


