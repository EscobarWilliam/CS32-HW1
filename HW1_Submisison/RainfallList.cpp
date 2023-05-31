//
//  RainfallList.cpp
//  HW1
//
//  Created by William  Escobar on 4/17/23.
//

#include "RainfallList.h"
#include "Sequence.h" //since we use sequence class functions


//right now, we dont need to have a constructor for Rainfall
//the Sequence measurements constructor gets called before this
RainfallList::RainfallList()
{
    
}

bool RainfallList::add(unsigned long rainfall)
{
    //we need to validate the measurement
    //if any of the conditionals are false we return false
    //we don't need the first conditional since we are using unsigned ints
    //thus, our values will always be positive
    if(/*rainfall < 0 || */ rainfall > 400 || measurements.size() == DEFAULT_MAX_ITEMS)
        return false;
    
    measurements.insert(rainfall);
    //because we use this insert function, all values will
    //be recoreded in ascending order
    return true;
}
  // If the rainfall is valid (a value from 0 to 400) and the rainfall list
  // has room for it, add it to the rainfall list and return true.
  // Otherwise, leave the rainfall list unchanged and return false.

bool RainfallList::remove(unsigned long rainfall)
{
    //we have to be careful, we only want to remove one
    //instance of "rainfall". We can't use .remove() of the
    //sequence class because it removes all instances
    //we need to use .erase(), but we need to know the exact location first
    int p = measurements.find(rainfall);
    
    if(p != -1)
    {
        measurements.erase(p);
        return true;
    }
    
    return false;
}
  // Remove one instance of the specified rainfall from the rainfall list.
  // Return true if a rainfall was removed; otherwise false.

int RainfallList::size() const
{
    return measurements.size();
}// Return the number of rainfalls in the list.

unsigned long RainfallList::minimum() const
{
    //if there are no measurements then return NO_RAINFALLS
    if(size() == 0)
        return NO_RAINFALLS;
    
    //because the values will be in order since added with
    //the sequence.insert(const ItemType& value)
    //we can just return the first item in the list
    unsigned long temp;
    measurements.get(0, temp);
    return temp;
    
    
}
  // Return the lowest-valued rainfall in the rainfall list.  If the list is
  // empty, return NO_RAINFALLS.

unsigned long RainfallList::maximum() const
{
    //if there are no measurements then return NO_RAINFALLS
    if(size() == 0)
        return NO_RAINFALLS;
    
    //because the values will be in order since added with
    //the sequence.insert(const ItemType& value)
    //we can just return the last item in the list
    unsigned long temp;
    measurements.get(measurements.size()-1, temp);//we need to subtract one because of array subscipt numbering
    return temp;
}
  // Return the highest-valued rainfall in the rainfall list.  If the list is
  // empty, return NO_RAINFALLS.
void RainfallList::dump()
{
    measurements.dump();
}
