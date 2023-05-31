//
//  Sequence.cpp
//  HW1
//
//  Created by William  Escobar on 4/16/23.
//

#include "newSequence.h"
#include <iostream>
#include <stdlib.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///       IMPLEMENTATION OF SEQUENCE CLASS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Sequence::Sequence()// Create an empty sequence (i.e., one whose size() is 0).
{
    //my approach is to have the sequence initiallized to its default value
    //Every time that we add an element, we increment the counter of the array
    sequence = new ItemType[DEFAULT_MAX_ITEMS];
    
    m_size = 0; //set counter to zero, there are no elements yet
    max_size = DEFAULT_MAX_ITEMS;
    
    for(int i = 0; i < DEFAULT_MAX_ITEMS; i++)
    {
        sequence[i] = {};//this sets the sequence element to its default value
                        
    }
}
Sequence::~Sequence()
{
    delete [] sequence; //deletes any allocated memory
}
Sequence::Sequence(int size)
{
    if(size < 0)
    {
        std::cout << "Attempt to create a sequence of a non-valid size detected. Size of squence must be a positive integer value. Program terminated." << std::endl;
        exit(1);
    }
    //dynamically allocate memory for user sequence
    sequence = new ItemType[size];
    m_size = 0; //set counter to zero, there are no elements yet
    max_size = size;
    
    for(int i = 0; i < size; i++)
    {
        sequence[i] = {};//this sets the sequence element to its default value
    }
    
}
Sequence& Sequence::operator=(const Sequence &other)
{
    if(this != &other)
    {
    //we want to set all values of "this" to be the same as "other"
        
        //if the sequence already has values in it, we need to delete them
        if(m_size > 0)
            delete [] sequence;
        
        max_size = other.max_size;
        m_size = other.size();
        sequence = new ItemType[max_size];
        
        //now we need to copy over the values
        for(int i=0; i<m_size; i++)
        {
            other.get(i, sequence[i]);
        }
        
    }
    return *this;
}
bool Sequence::empty() const
{
    return (m_size == 0); // Return true if the sequence is empty, otherwise false.
}
int Sequence::size() const
{
    return m_size;// Return the number of items in the sequence.
    
}
//***************************************************************
//      int Sequence::insert(int, const str&) is a function
//      that adds an element to the sequence as long as the
//      position(integer) that is passed to the function is
//      a position in the Sequence. If the integer passed is
//      above or below the bounds of the array, then
//      the function will return -1. If the item can be placed,
//      then the function returns the position integer
//
//      three cases: pos int can be > length of list(EXCEED)
//                   pos int can be < lenght of list(UNDERFLOW)
//                   pos int can be within the list(VALID)
//***************************************************************
int Sequence::insert(int pos, const ItemType& value)
{
    //pos is out of bounds of the array(overflow/underflow)
    //or the array is already completely full
    if(pos > size() || pos < 0 || size() >= max_size)
        return -1;
    //pos is at the end of the array
    if(pos == size())
    {
        //to have gotten here, that means that we want to insert at the end
        //and we made sure that the array still has room to except another
        //element
        sequence[pos] = value;
        m_size++;
        return pos;
    }
    else
    { //we use the same algorithm as before
        for (int i = size(); i> pos; i--)
        {
            sequence[i] = sequence[i-1];
        }
        sequence[pos] = value;
        m_size++;
        return pos;
        
    }
    //pos is at the beginning of the array
//    else if(pos == 0)
//    {
//        //if we are here, that means that we want to insert an
//        //element to the very beginning of the array. To do this
//        //we will have to copy all the values into another temporary array
//
//        for (int i = size(); i> pos; i--)
//        {
//            sequence[i] = sequence[i-1];
//        }
//        sequence[pos] = value;
//        m_size++;
//        return pos;
////        ItemType temp[m_size];
////
////        for(int i = 0; i<m_size; i++)//maybe use a copy constructor instead???
////        {
////            temp[i] = sequence[i];
////        }
//
//        //set first element value
////        sequence[pos] = value;
////
////        //move the rest of the values down by one
////        for(int i = 0; i<m_size; i++)
////        {
////            sequence[i+1] = temp[i];
////        }
////        //make sure to increment afterwards, otherwise in the
////        //for loop above, you will step out of bounds of the arrays
////        m_size++;
////
////
//    }
//    else //pos is somewhere in the middle of the array
//    {
//        ItemType temp[m_size];
//        int count = 0;
//        for(int i = pos; i<m_size; i++)
//        {
//            temp[count] = sequence[i];
//            count++;
//        }
//
//        sequence[pos] = value;
//        m_size++;
//
//        count = 0;
//        for(int i = pos+1; i<m_size; i++)
//        {
//            sequence[i] = temp[count];
//            count++;
//        }
//
//    }
    
    return pos;//pos is somewhere in the middle of the array
}
  
//***************************************************************
//            int Sequence::insert(const ItemType& value)
//      This insert function just gets passed a value and not
//      a specific location. The function is supposed to figure
//      out what location to insert the value based on its value.
//      The function should insert value in a position
//      where the element before it has a smaller data value, and
//      the one that follows it has a larger data value. Then
//      the function returns the position where it was inserted.
//***************************************************************
int Sequence::insert(const ItemType& value)
{
    if(m_size == max_size) // we can't add any more items
        return -1;
    
    int p;
    
    //case1: List is empty, so we add value to begining of the list
    if(size() == 0)
    {
        p=0;
        insert(p, value);
        return p;
    }
    
    else
    {
        //call the find() function to look for where we
        //need to insert the value
        p = find(value);
        
        //p=-1 means that we didnt find any element with data == "value"
        //so we need to dertermine where "value" belongs
        //once that happens, we insert the value there and adjust the
        //sequence
        if(p == -1)
        {
            int count = 0;
            while(value > sequence[count] && count < m_size)
            {
                count++;
            }
            
            //once we are here, we should now know where the item needs to be inserted
            //we can then call the other insert() function
            insert(count, value);
            return p;
        }
        
        //if we made it here, we have found a duplicate value
        //and are inserting it there
        insert(p, value);
        return p;
    }
}

bool Sequence::erase(int pos)
{
    //pos is out of bounds of the array(overflow/underflow)
    if(pos > size() || pos < 0 )
        return false;
    //pos is at the end of the array
    if(pos == size())
    {
        //to have gotten here, that means that we want to erase at the end
        sequence[pos] = {};
        m_size--;
        return true;
    }
    //pos is at the beginning of the array
    else if(pos == 0)
    {
        //if we are here, that means that we want to erase an
        //element at the very beginning of the array.
        
        //ItemType temp[m_size];
        
        for(int i = 0; i<m_size; i++)
        {
            sequence[i] = sequence[i+1];// sequence[i+1] because we want
                                    //to move over all values
        }
        m_size--;
        
    }
    else //pos is somewhere in the middle of the array
    {
  
        for(int i = pos; i<m_size; i++)
        {
            sequence[i] = sequence[i+1];//sequence[i+1] because we don't want the value at pos
            //count++;
        }

        m_size--;
        
        //count = 0;
//        for(int i = pos; i<m_size; i++)
//        {
//            sequence[i] = temp[count];
//            count++;
//        }
    }
//    //pos is at the beginning of the array
//    else if(pos == 0)
//    {
//        //if we are here, that means that we want to erase an
//        //element at the very beginning of the array. To do this
//        //we will have to copy all the values into another temporary array
//        ItemType temp[m_size];
//
//        for(int i = 0; i<m_size; i++)//maybe use a copy constructor instead???
//        {
//            temp[i] = sequence[i+1];// sequence[i+1] because we don't want to
//                                //copy the element we will get erased
//        }
//        m_size--;
//
//        for(int i = 0; i<m_size; i++)
//        {
//            sequence[i] = temp[i];
//            if(i == (m_size - 1) )
//                sequence[i+1] = {}; //set the last value to default
//        }
//
//    }
//    else //pos is somewhere in the middle of the array
//    {
//        ItemType temp[m_size];
//        int count = 0;
//        for(int i = pos; i<m_size; i++)
//        {
//            temp[count] = sequence[i+1];//sequence[i+1] because we don't want the value at pos
//            count++;
//        }
//
//        m_size--;
//
//        count = 0;
//        for(int i = pos; i<m_size; i++)
//        {
//            sequence[i] = temp[count];
//            count++;
//        }
//    }
    
    return true;//we sucessfully erased
}
  // If 0 <= pos < size(), remove the item at position pos from
  // the sequence (so that all items that followed that item end up at
  // positions one lower than they were at before), and return true.
  // Otherwise, leave the sequence unchanged and return false.
 
int Sequence::remove(const ItemType& value)
{
    int p = find(value);
    
    if(p == -1)//no items with that value were found
        return 0;
    
    int counter = 0;
    while(p != -1)
    {
        erase(p);
        p = find(value);
        counter++;
    }
    
    return counter;
}
  // Erase all items from the sequence that == value.  Return the
  // number of items removed (which will be 0 if no item == value).

bool Sequence::get(int pos, ItemType& value) const
{
    if(pos > size() || pos < 0)
        return false;
    
    value = sequence[pos];
    return true;
}
  // If 0 <= pos < size(), copy into value the item in position pos
  // of the sequence and return true.  Otherwise, leave value unchanged
  // and return false.

bool Sequence::set(int pos, const ItemType& value)
{
    if(pos > size() || pos < 0)
        return false;
  
    sequence[pos] = value;
        
    return true;
}
  // If 0 <= pos < size(), replace the item at position pos in the
  // sequence with value and return true.  Otherwise, leave the sequence
  // unchanged and return false.

int Sequence::find(const ItemType& value) const
{
    int count = 0;
    while(value != sequence[count]  && count < m_size)
        count++;
    
    if(value == sequence[count])
        return count;
    
    else
        return -1;//if we made it here, it means that we didn't find any element == "value"
}
  // Let p be the smallest integer such that value == the item at
  // position p in the sequence; if no such item exists, let p be -1.
  // Return p.

//***************************************************************
//           void Sequence::swap(Sequence& other)
//     Exchange the contents of this sequence with the other one.
//     We can simply swap the addresses to their sequences
//***************************************************************
void Sequence::swap(Sequence& other)
{
    //swap the sequences addresses
    ItemType* temp = other.sequence;
    other.sequence = sequence;
    sequence = temp;
    
    //next we need to swap the private member variables
    int r = other.size();
    other.m_size = this->m_size;
    this->m_size = r;
    
    r = other.max_size;
    other.max_size = this->max_size;
    this->max_size = r;
}
void Sequence::dump()
{
    for(int i=0; i<m_size; i++)
    {
        std::cerr << sequence[i] << std::endl;
    }
}
