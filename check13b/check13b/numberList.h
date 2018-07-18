/*******************
 * NumberList class
 *******************/
#ifndef NUMBER_LIST_H
#define NUMBER_LIST_H

#include <iostream>

class NumberList
{
private:
    int size;
    int *array;
    
public:
    NumberList()
    {
        size = 0;
    }
    
    
    // TODO: Add your constructor and destructor
    
    NumberList(int index)
    {
        
         size = index;
        array = new int[size];
        
        
        for ( int i = 0; i > size; i++)
        {
            array[i] =0;
        }
        
        
        
        
        
    }
    
    ~NumberList()
    {
        std::cout << "Freeing memory"<< std::endl;
        if (array != NULL)
        {
            //delete[] array;
            array = NULL;
        }
        
    }
    
NumberList& operator=(const NumberList & other)
    {
        size = other.size;
        //array = other.array;
        
        if (array != NULL)
        {
            //delete this-> array;
            array = NULL;
        }
        
        array = new int[size];
        
        for (int i = 0; i < size; i++)
        {
            array[i] = other.array[i];
        }
        
        return *this;
    }

    
    int getNumber(int index) const;
    void setNumber(int index, int value);
    
    void displayList() const;
    
};

#endif
