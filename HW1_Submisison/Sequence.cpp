//
//  Sequence.cpp
//  HW1
//
//  Created by William  Escobar on 4/16/23.
//

#include "Sequence.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///       IMPLEMENTATION OF SEQUENCE CLASS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Sequence::Sequence()// Create an empty sequence (i.e., one whose size() is 0).
{
    //my approach is to have the sequence initiallized to its default value
    //Every time that we add an element, we increment the counter of the array
    
    m_size = 0; //set counter to zero, there are no element constructed yet
    
    for(int i = 0; i < DEFAULT_MAX_ITEMS; i++)
    {
        sequence[i] = {};//this sets the sequence element to its default value which is determined by C++
                        
    }
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
    if(pos < 0 || pos > size() || size() >= DEFAULT_MAX_ITEMS)
        return -1;
    
    //the following code basically moves over all values in the array
    //from the 'pos' that we want to insert it an move them over
    for (int i = size(); i> pos; i--)
    {
        sequence[i] = sequence[i-1];
    }
    sequence[pos] = value;
    m_size++;
    return pos;
//    //pos is out of bounds of the array(overflow/underflow)
//    //or the array is already completely full
//    if(pos > size() || pos < 0 || size() >= DEFAULT_MAX_ITEMS)
//        return -1;
//    //pos is at the end of the array
//    if(pos == size())
//    {
//        //to have gotten here, that means that we want to insert at the end
//        //and we made sure that the array still has room to except another
//        //element
//        sequence[pos] = value;
//        m_size++;
//        return pos;
//    }
//    //pos is at the beginning of the array
//    else if(pos == 0)
//    {
//        //if we are here, that means that we want to insert an
//        //element to the very beginning of the array. To do this
//        //we will have to copy all the values into another temporary array
//        ItemType temp[m_size];
//
//        for(int i = 0; i<m_size; i++)//maybe use a copy constructor instead???
//        {
//            temp[i] = sequence[i];
//        }
//
//        //set first element value
//        sequence[pos] = value;
//
//        //move the rest of the values down by one
//        for(int i = 0; i<m_size; i++)
//        {
//            sequence[i+1] = temp[i];
//        }
//        //make sure to increment afterwards, otherwise in the
//        //for loop above, you will step out of bounds of the arrays
//        m_size++;
//
//
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
//
//    return pos;//pos is somewhere in the middle of the array
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
        
//        for(int i = 0; i<m_size; i++)
//        {
//            sequence[i] = temp[i];
//            if(i == (m_size - 1) )
//                sequence[i+1] = {}; //set the last value to default
//        }
//
    }
    else //pos is somewhere in the middle of the array
    {
  
    
        //im getting an error here about having a
        //variable length array 'temp'
        //int size = m_size;
        //ItemType temp[size];
        //int count = 0;
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
//     This way we don't have to
//     Copy, delete, or allocate new memory.
//***************************************************************
void Sequence::swap(Sequence& other)
{
    ItemType temp;
    //we need to consider when the arrays are of the same length
    if(m_size == other.size())
    {
        for(int i = 0; i<m_size; i++)
        {
            other.get(i, temp);
            other.set(i, sequence[i]);
            sequence[i] = temp;
        }
    }
    
    //now we need to consider if one or the other array is longer
    if(m_size > other.size())
    {
        for(int i = 0; i<m_size; i++)
        {
            other.get(i, temp);
            other.set(i, sequence[i]);
            sequence[i] = temp;
        }
        
        //dont forget to adjust the lengths of the arrays
        int temp;
        temp = m_size;
        m_size = other.size();
        other.m_size = temp;
    }
    else
    {
        for(int i = 0; i<other.size(); i++)
        {
            other.get(i, temp);
            other.set(i, sequence[i]);
            sequence[i] = temp;
        }
        
        //dont forget to adjust the lengths of the arrays
        int temp;
        temp = m_size;
        m_size = other.size();
        other.m_size = temp;
    }
}
  // Exchange the contents of this sequence with the other one.

void Sequence::dump()
{
    for(int i=0; i<m_size; i++)
    {
        std::cerr << sequence[i] << std::endl;
    }
}
