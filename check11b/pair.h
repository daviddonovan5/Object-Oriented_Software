/*****************************************************
 * File: pair.h
 *
 * Purpose: Defines a Pair template class that can hold
 *   two items of arbitrary data types.
 ******************************************************/

#ifndef PAIR_H
#define PAIR_H



template <class T1, class T2>
class Pair

{
private:
    T1 t1;
    T2 t2;
    
public:
    T1 getFirst() const
    {
        return t1;
    }
    void setFirst(T1 t1)
    {
        this -> t1 = t1;
    }
    T2 getSecond() const
    {
        return t2;
    }
    void setSecond(T2 t2)
    {
        this -> t2 = t2;
    }


    void display()
    {
        cout << getFirst() << " - " << getSecond();

        
    }
   };


#endif // PAIR_H
