//
//  testRainfallList.cpp
//  HW1
//
//  Created by William  Escobar on 4/17/23.
//

#include "RainfallList.h"
#include <cassert>
#include <iostream>
int main()
{
    //tests constructor, insert(), get(), and remove() functions
    RainfallList s;
        s.add(10);
        s.add(90);
        s.add(60);
        s.add(30);
        s.add(110);
        //s.dump();
        assert(s.minimum() == 10);
        assert(s.maximum() == 110);
        //s.dump();
        assert(s.remove(60));
        //s.dump();
        assert(s.size() == 4);
        assert(s.minimum() == 10);
        assert(s.maximum() == 110);
        s.add(10);
        s.add(5);
        s.add(400);
        assert(s.size() == 7);
        assert(s.minimum() == 5);
        assert(s.maximum() == 400);
        assert( !(s.add(401)) );
        assert( !(s.add(-1)) );
    std::cout << "Passed all tests." << std::endl;
    //test number 2
}
